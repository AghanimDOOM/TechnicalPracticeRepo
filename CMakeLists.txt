# 设置最小的CMake版本要求
cmake_minimum_required(VERSION 3.10)
project(desktopApp VERSION 1.0)

# 查找C++编译器的最低版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加编译选项：优化级别2，调试信息，以及ASan
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g -fsanitize=address -fno-omit-frame-pointer")

add_subdirectory(components)
add_subdirectory(app)