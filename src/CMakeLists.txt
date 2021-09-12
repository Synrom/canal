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
)


list(APPEND ScopeFiles 
	"scope/scope.cpp"
	"scope/file.cpp"
	"scope/root_scope.cpp"
)

list(APPEND OperationFiles
	"operation/operation.cpp"
	"operation/root_operation.cpp"
)

list(APPEND DebuggerFiles
	"debugger/debugger.cpp"
)

add_library(struct ${VarFiles} ${ScopeFiles} ${OperationFiles} ${DebuggerFiles})
target_include_directories(struct PUBLIC ../include)
