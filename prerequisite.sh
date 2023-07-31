#!/bin/sh
version=$(ls ~/Qt/ | grep "[0-9]")
if [ -n "$version" ]; then
    rm -rf qtapplicationmanager || exit
    appManPath="git clone https://github.com/qt/qtapplicationmanager"
    eval "${appManPath}"
    cd qtapplicationmanager || exit
    git checkout "${version}"
    mv CMakeLists.txt CMakeLists2.txt
    echo "SET(CMAKE_PREFIX_PATH ~/Qt/${version}/gcc_64)" >> CMakeLists.txt
    cat CMakeLists2.txt >> CMakeLists.txt
    rm CMakeLists2.txt
    mkdir -p build
    cd build || exit
    cmake "$PWD"/..
    echo $PWD
    sudo make install -j8
else
    echo "Please Install Qt First"
fi
