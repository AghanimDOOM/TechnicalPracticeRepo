# 添加共享库目标
add_library(freetype SHARED IMPORTED)

# 设置库文件路径（使用带版本号的实际文件）
set_target_properties(freetype PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/lib/libfreetype.so.6.20.2
)

# 如果有符号链接，也可以设置
set_target_properties(freetype PROPERTIES
    IMPORTED_SONAME "libfreetype.so"
)

# 设置头文件路径
target_include_directories(freetype INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/inc
)