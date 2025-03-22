set(CMAKE_C_STANDARD 99)#C99 # lvgl officially support C99 and above
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LV_CONF_BUILD_DISABLE_DEMOS ON)
set(LV_CONF_BUILD_DISABLE_EXAMPLES ON)

include(${CMAKE_CURRENT_LIST_DIR}/lvgl/tests/FindLibDRM.cmake)
include_directories(${Libdrm_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_LIST_DIR}/inc)

add_subdirectory(lvgl)

# 链接lvgl
target_include_directories(lvgl PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc ${CMAKE_CURRENT_LIST_DIR}/lvgl)
