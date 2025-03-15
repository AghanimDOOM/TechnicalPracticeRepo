cmake_minimum_required(VERSION 3.10)
project(freetype)

# 添加库
add_library(freetype SHARED IMPORTED)

# 设置库文件路径
set_target_properties(freetype PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/libfreetype.so
)

# 设置头文件路径
target_include_directories(freetype INTERFACE ${CMAKE_CURRENT_LIST_DIR}/inc)