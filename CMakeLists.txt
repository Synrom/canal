cmake_minimum_required(VERSION 3.21)

project(canal)

add_executable(${PROJECT_NAME} o.cpp)

add_subdirectory(src)


target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} struct)

add_compile_definitions(DEBUG)
