cmake_minimum_required(VERSION 3.15)

#define the project name
set(project_name "MyMEXFunction")

project(MyMEXFunction)

set(CMAKE_CXX_STANDARD 17)
find_package(Matlab)

matlab_add_mex(
    NAME MyMEXFunction
    SRC MyMEXFunction.cpp
)

add_custom_command(
    TARGET ${project_name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:MyMEXFunction> ${CMAKE_SOURCE_DIR}/${project_name}.mexw64

)
