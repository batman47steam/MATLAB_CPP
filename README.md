# MATLAB_CPP
C++ with matlab

matlab里面调用c++的内容已经在obsidian中进行总结了，这块的内容主要针对如何更好的将由C++编写的soure file编译为mex

按照[create a c++ mex source file](https://www.mathworks.com/help/matlab/matlab_external/c-mex-source-file.html)里面说的，直接用下面的方法就可以成功的将c++ source file编译为mex

```c++
mex -setpu c++
mex MyMEXFunction.cpp
```

但是有个问题，在实际的应用中，可能C++ source file不仅仅只链接了matlab，可能还调用了很多其他的库，比如opencv之类的，在这种情况下，直接用mex进行编译可能会受到一些限制

可能的解决方法

- 在visual studio通过链接库，包含目录等一系列的设置，来包含需要的头文件和.lib文件 （稍微有点麻烦，不够炫酷）参考[CSDN](https://blog.csdn.net/xueweuchen/article/details/44244403)
- 直接利用CMakeList进行链接

---

主要参考了[stackoverflow](https://stackoverflow.com/questions/59163437/use-cmake-for-mex)的CMakeList.txt，利用CMAKEList.txt主要的目的就是可以很方便的链接其他C++库

```c++
cmake_minimum_required(VERSION 3.15)

#define the project name
set(project_name "MyMEXFunction")

project(MyMEXFunction)

set(CMAKE_CXX_STANDARD 17)
find_package(Matlab)

//most important
matlab_add_mex(
    NAME MyMEXFunction
    SRC MyMEXFunction.cpp
)

//将生成的mexw64文件复制到CMAKEList所在的根目录
add_custom_command(
    TARGET ${project_name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:MyMEXFunction> 	${CMAKE_SOURCE_DIR}/${project_name}.mexw64

)

```

```c++
mkdir _build
cmake ..
cmake --build .
```

最后的`add_custom_command`主要是将生成的`.mexw64`从`_build/Debug`目录下直接移动到cpp文件所在的目录下，方便matlab直接进行调用，参考了[stackoverflow](https://stackoverflow.com/a/60170862/9656153)

![image-20220407203810172](https://raw.githubusercontent.com/batman47steam/typora-pic/main/images/image-20220407203810172.png)

![image-20220407203839136](https://raw.githubusercontent.com/batman47steam/typora-pic/main/images/image-20220407203839136.png)
