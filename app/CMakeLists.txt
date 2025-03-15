cmake_minimum_required(VERSION 3.10)
project(desktopApp)

# 找到所有的源文件并将其添加到库
file(GLOB SRC_FILES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp ${CMAKE_CURRENT_LIST_DIR}/src/*.c)

# 添加可执行文件
add_executable(desktopApp ${SRC_FILES})

# 链接
target_link_libraries(desktopApp ui_manager lvgl lvgl::thorvg drm m pthread input freetype)