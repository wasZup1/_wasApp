# 这里的所有代码都是葛小乐收集来的

1. 需要将output文件夹下的内容复制到工程文件夹
2. 使用前需要在 工程文件下的 CMakeLists.txt 加入以下内容

```txt

outFile 当前工程生成的目标
target_link_libraries(outFile ${CMAKE_CURRENT_SOURCE_DIR}/_wasApp/lib_wasApp.a)

```