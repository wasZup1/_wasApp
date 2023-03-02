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
        "-Example")
            make_all Example

            rm -rf output/*
            cp *.h              output/ -vp
            cp $buildDir/*.a    output/ -vp

            ;;
        "-Release")
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
            echo "$0 -Example     编译例子 电脑可直接运行"
            echo "$0 -Release     编译例子 使用的时安凯工具链， 在板子上运行"
            echo "$0 -clean             删除编译生成的文件"
            # echo "$0 -bk            打包备份"
            echo "###################################################"

            ;;
    esac

}

main $1 $2