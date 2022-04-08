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

---

关于matlabData主要想强调的有两点

- feval接受参数的方式

  - 最小的单位应该是matlab::data::array之类的
  - 如果对应的matlab函数是要接受多个参数的，就需要用std::vector把他们包装起来

- 数据默认是按照列优先排布的

  - [matlab.data.arrayfactory](https://www.mathworks.com/help/matlab/apiref/matlab.data.arrayfactory.html#bvn7dve-1)

    > *The data is copied by default in column-major order. To specify the data layout, use the* `*inputLayout*` *parameter.*

  - ```c++
    std::vector<matlab::data::Array> args({
            factory.createArray<int16_t>({2,2},  {-5, 17, 10, 0}),
            factory.createArray<int16_t>({2,2}, {-15, 3, 100, 0}) });
    ```

    - <img src="https://raw.githubusercontent.com/batman47steam/typora-pic/main/images/image-20220408155826934.png" alt="image-20220408155826934" style="zoom:80%;" />

    - [gcd](https://www.mathworks.com/help/matlab/ref/gcd.html)

      