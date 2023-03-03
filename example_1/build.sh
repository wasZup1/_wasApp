#!/bin/sh

filePath=$(cd $(dirname $0);pwd -P)
projPath=$filePath/..
buildDir="make_temp"


make_all(){

    if [ ! -d $buildDir ]; then
        mkdir $buildDir
    fi

    cd $buildDir
    cmake  -DCMAKE_BUILD_TYPE="Example" ..
    make    -j12
    
    cd ..
}

make_lib(){
    cd $projPath/src

    ./build.sh -Ex
    cp -vp $projPath/src/output/*.a $projPath/example_1/lib
    cp -vp $projPath/src/output/*.h $projPath/example_1/include

    cd -
    
}



make_clean(){
    # 清除编译产生的中间文件
    rm -rf $buildDir/*
}

run_exe(){
    ./$buildDir/example_1
}



main () {
    case ${1} in
        "-all")

            make_lib
            make_all
            run_exe

            ;;
        "-lib")
            
            ;;
        "-clean")
            
            make_clean
            ;;
        
        *)
            echo "####################### MENU #######################"
            echo "$0                    MENU"
            echo "$0 -all               编译全部"
            echo "$0 -clean             删除编译生成的文件"
            echo "$0 -lib               编译库文件"
            echo ""
            echo "###################################################"

            ;;
    esac

}

main $1