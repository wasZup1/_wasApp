cmake_minimum_required(VERSION 3.5.1)

message("CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})

if(${CMAKE_BUILD_TYPE} STREQUAL  "Release")

    set(CMAKE_C_COMPILER "arm-anykav500-linux-uclibcgnueabi-gcc")
    set(CMAKE_CXX_COMPILER "arm-anykav500-linux-uclibcgnueabi-g++")

    set(CMAKE_C_FLAGS "-std=gnu11")

endif()

project(wasZup)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SOURCES ./*.c  ./*.cpp)

add_library(_wasApp  ${SOURCES})  # 将他们编译为一个叫 wasApp_lib 的文件


