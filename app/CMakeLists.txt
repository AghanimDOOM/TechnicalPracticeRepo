# 找到所有的源文件并将其添加到可执行文件
file(GLOB APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# 添加可执行文件
add_executable(desktopApp ${APP_SOURCES})

# 链接
target_link_libraries(desktopApp ui_manager lvgl lvgl::thorvg ${Libdrm_LIBRARIES} m pthread)