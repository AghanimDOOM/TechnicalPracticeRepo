cmake_minimum_required(VERSION 3.10)
project(freetype)


set(CMAKE_C_STANDARD 99)#C99 # lvgl officially support C99 and above
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(freetype)


target_include_directories(freetype PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)