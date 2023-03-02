#!/bin/sh

filePath=$(cd $(dirname $0);pwd -P)
buildDir="make_temp"


make_all(){

    if [ ! -d $buildDir ]; then
        mkdir $buildDir
    fi

    cd $buildDir
    cmake   -DCMAKE_BUILD_TYPE=$1 ..
    make    -j12


    cd ..

}



make_clean(){
    # 清除编译产生的中间文件
    rm -rf $buildDir/*
}

main () {
    case ${1} in
        "-Ex")
            make_all Example

            rm -rf output/*
            cp *.h              output/ -vp
            cp $buildDir/*.a    output/ -vp

            ;;
        "-Re")
            make_all Release

            rm -rf output/*
            cp *.h              output/ -vp
            cp $buildDir/*.a    output/ -vp

            ;;

        "-clean")
            
            make_clean
            ;;
        
        *)
            echo "####################### MENU #######################"
            echo "$0                MENU"
            echo ""
            echo "$0 -Ex            编译例子 电脑可直接运行"
            echo "$0 -Re            编译例子 使用的时安凯工具链， 在板子上运行"
            echo "$0 -clean         删除编译生成的文件"
            # echo "$0 -bk            打包备份"
            echo "###################################################"

            ;;
    esac

}

# 更新时间
buf=$(cat wasApp.h | grep "build time:" | awk '{print $4}')
sed -i "s/${buf}/$(date +%Y%m%d%H%M)/" wasApp.h

main $1 $2