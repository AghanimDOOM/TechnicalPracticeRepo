# 找到所有的源文件并将其添加到库
file(GLOB SRC_FILES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

# 添加静态库，并设置头文件目录为公共可见
add_library(ui_manager STATIC ${SRC_FILES})

# 设置头文件目录为公共可见，以便链接时自动包含这些路径
target_include_directories(ui_manager PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc)