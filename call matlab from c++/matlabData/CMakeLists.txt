cmake_minimum_required(VERSION 3.15)

#define the project name
set(project_name "GCD_matlab")

#set the project name
project(${project_name})

set(CMAKE_CXX_STANDARD 17)

find_package(Matlab)
INCLUDE_DIRECTORIES(${Matlab_ROOT_DIR}/extern/include)

#add executable
add_executable(4-8 matlabdata.cpp)

target_link_libraries(4-8 ${Matlab_ROOT_DIR}/extern/lib/win64/microsoft/libMatlabEngine.lib)
target_link_libraries(4-8 ${Matlab_ROOT_DIR}/extern/lib/win64/microsoft/libMatlabDataArray.lib)