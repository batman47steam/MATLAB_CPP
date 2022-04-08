#### Call matlab from C++

从c++中调用matlab相比从matlab中调用C++似乎要更加方便点

这个的主要应用应该还是用在利用matlab进行画图上，一般用opencv，有时候需要将图像投影到一维，然后画图进行分析，这个时候如果能直接调用matlab来画图还是会方便很多

---

主要想强调的还是CMakeLists.txt部分

主要参考了

[Build C++ Engine Programs](https://www.mathworks.com/help/matlab/matlab_external/build-c-engine-programs.html)详细说了到底要添加哪些目录和哪些库，同时哪些路径应该加入环境变量

[cmake](https://www.mathworks.com/matlabcentral/answers/472865-calling-matlab-functions-from-c-application-built-with-cmake-in-visual-studio)在cmake中链接matlab的头文件和库的方式，`Matlab_ROOT_DIR`这个变量是可以直接使用的

```CM
find_package(Matlab)
INCLUDE_DIRECTORIES(${Matlab_ROOT_DIR}/extern/include)

target_link_libraries(4-8 ${Matlab_ROOT_DIR}/extern/lib/win64/microsoft/libMatlabEngine.lib)
target_link_libraries(4-8 ${Matlab_ROOT_DIR}/extern/lib/win64/microsoft/libMatlabDataArray.lib)
```



