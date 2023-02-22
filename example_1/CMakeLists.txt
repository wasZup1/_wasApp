cmake_minimum_required (VERSION 3.5.1)  

message("build type: " ${CMAKE_BUILD_TYPE})

aux_source_directory(. DIR_SRCS)
aux_source_directory(../src/_wasApp/ DIR_SRCS)       # 添加个人库路径

SET(ProName example_1)
project(${ProName} C)

add_executable(${ProName} ${DIR_SRCS})  #链接生成文件${ProName} 由DIR_SRC链接。
target_link_libraries(${ProName} ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib_wasApp.a)


