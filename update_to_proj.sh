#/bin/bash

lib_dir="src/output"

proj_path_1="/home/xiaole/share/work/MeteC/monitor_MeteC/src/_wasApp"
proj_path_2="/home/xiaole/share/work/MeteC/camera_MeteC/_wasApp"
proj_path_3="/home/xiaole/share/work/Ryan/app_SRA_704MAHT/_wasApp"


# 编译
build_lib_reslease(){
    cd src
    ./build.sh -Re

    cd -
}

# 删除旧文件
unistall_old_files(){
    rm -rf $proj_path_1/* 
    rm -rf $proj_path_2/*
    rm -rf $proj_path_3/*
    
}

# 安装
install_new_files(){
    cp -rf -p $lib_dir/* $proj_path_1/
    cp -rf -p $lib_dir/* $proj_path_2/
    cp -rf -p $lib_dir/* $proj_path_3/
}

build_lib_reslease

unistall_old_files

install_new_files