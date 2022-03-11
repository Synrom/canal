list(APPEND VarFiles 
	"variable/_double.cpp"
	"variable/_float.cpp"
	"variable/longdouble.cpp"
	"variable/signedchar.cpp"
	"variable/signedint.cpp"
	"variable/signedlong.cpp"
	"variable/signedlonglong.cpp"
	"variable/signedshort.cpp"
	"variable/unsignedchar.cpp"
	"variable/unsignedint.cpp"
	"variable/unsignedlong.cpp"
	"variable/unsignedlonglong.cpp"
	"variable/unsignedshort.cpp"
	"variable/variable.cpp"
	"variable/pointer.cpp"
	"variable/vcontainer.cpp"
	"variable/shl_shr.cpp"
	"variable/print.cpp"
	"variable/comperator.cpp"
	"variable/clone.cpp"
	"variable/cloneMax.cpp"
)


list(APPEND ScopeFiles 
	"scope/root_scope.cpp"
	"scope/function.cpp"
)

list(APPEND OperationFiles
	"operation/operation.cpp"
	"operation/operation_stack.cpp"
	"operation/equal.cpp"
	"operation/clone.cpp"
	"operation/shl_shr.cpp"
	"operation/int_lit.cpp"
	"operation/print.cpp"
	"operation/var_push.cpp"
	"operation/call.cpp"
	"operation/ret.cpp"
	"operation/switch.cpp"
	"operation/neg_dec_inc.cpp"
	"operation/access.cpp"
)

list(APPEND DebuggerFiles
	"debugger/debugger.cpp"
)

list(APPEND AnalyzerFiles
	"analyzer/function_finder.cpp"
	"analyzer/function_analyzer.cpp"
	"analyzer/classifiers.cpp"
	"analyzer/dump_handler.cpp"
)

list(APPEND ContainerFiles
	"container/vectors.cpp"
)

list(APPEND ResultFiles
	"result/result.cpp"
	"result/locals.cpp"
	"result/identifiers.cpp"
)

list(APPEND SchedulerFiles
	"scheduler/scheduler.cpp"
)

add_library(struct ${VarFiles} ${ScopeFiles} ${OperationFiles} ${DebuggerFiles} ${AnalyzerFiles} ${ContainerFiles} ${ResultFiles} ${SchedulerFiles})
target_link_options(struct PUBLIC -rdynamic)
target_include_directories(struct PUBLIC ../include)

Find_Package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION} in ${LLVM_INSTALL_PREFIX}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
Find_Package(Clang REQUIRED CONFIG HINTS "${LLVM_INSTALL_PREFIX}/lib/cmake/clang")
message(STATUS "Found Clang in ${CLANG_INSTALL_PREFIX}")

target_include_directories(struct PRIVATE "${CMAKE_CURRENT_LIST_DIR}")

if (${LLVM_VERSION} VERSION_LESS "10.0.0")
    target_link_libraries(canal PRIVATE
        clangFrontend
        clangParse
        clangSema
        clangAST
        clangBasic
        clangLex
        clangTooling
        clangSerialization
    )
else()
    target_link_libraries(struct PRIVATE clang-cpp)
endif()

if(TARGET LLVM)
  target_link_libraries(struct PRIVATE LLVM)
else()
  # We cannot use llvm_config() here because in some versions it uses PRIVATE when calling target_link_libraries
  # and in some it doesn't. If our calls of target_link_libraries don't do it the same way, we get a
  # fatal error.
  llvm_map_components_to_libnames(llvm_libs core support)
  target_link_libraries(struct PRIVATE ${llvm_libs})
endif()

install(TARGETS canal RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
target_include_directories(struct PUBLIC ${CLANG_INCLUDE_DIRS})
set_property(TARGET struct PROPERTY CXX_STANDARD 14)


if (NOT APPLE AND NOT MSVC)
    #  Don't link with libs that overlaps our options
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--as-needed" )
endif()


# System include dirs
if(WIN32)
    message(STATUS "Adding the following dirs as system projects")
    foreach(dir $ENV{INCLUDE})
        list(APPEND SYSTEM_INCLUDE_DIRS "include;${dir}")
    endforeach()
else()
    list(APPEND SYSTEM_INCLUDE_DIRS "include;/usr/include/")
endif()
string(REPLACE "\\" "/" SYSTEM_INCLUDE_DIRS "${SYSTEM_INCLUDE_DIRS}")

if(NOT MSVC)
# Flags not supported by MSVC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions -fno-rtti")

# TODO: Split up files and insert them row by row because
# MSVC only accepts strings of 2^16 bytes length (~65kb)

# Embed the clang header into the binary:
string(REPLACE "svn" "" LLVM_VERSION "${LLVM_VERSION}")
string(REGEX REPLACE "git.*$" "" LLVM_VERSION "${LLVM_VERSION}")
if(NOT CLANG_BUILTIN_HEADERS_DIR)
    set(CLANG_BUILTIN_HEADERS_DIR "${LLVM_LIBRARY_DIR}/clang/${LLVM_VERSION}/include")
endif()
file(GLOB BUILTINS_HEADERS "${CLANG_BUILTIN_HEADERS_DIR}/*.h")
if(NOT BUILTINS_HEADERS)
    message(FATAL_ERROR "Could not find any clang builtins headers in ${CLANG_BUILTIN_HEADERS_DIR}")
endif()
foreach(BUILTIN_HEADER ${BUILTINS_HEADERS})
    #filter files that are way to big
    if(NOT BUILTIN_HEADER MATCHES ".*/(arm_neon.h|altivec.h|vecintrin.h|avx512.*intrin.h)")
        file(READ ${BUILTIN_HEADER} BINARY_DATA)
        string(REPLACE "\\" "\\\\" BINARY_DATA "${BINARY_DATA}")
        string(REPLACE "\"" "\\\"" BINARY_DATA "${BINARY_DATA}")
        string(REPLACE "\n" "\\n\"\n\"" BINARY_DATA "${BINARY_DATA}")
        #workaround the fact that stdint.h includes itself
        string(REPLACE "__CLANG_STDINT_H" "__CLANG_STDINT_H2" BINARY_DATA "${BINARY_DATA}")
        string(REPLACE "${CLANG_BUILTIN_HEADERS_DIR}/" "/builtins/" FN "${BUILTIN_HEADER}"  )
        set(EMBEDDED_DATA "${EMBEDDED_DATA} { \"${FN}\" , \"${BINARY_DATA}\" } , \n")
    endif()
endforeach()
endif()

target_include_directories(struct PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
