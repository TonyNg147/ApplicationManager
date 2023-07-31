#!/bin/bash
read -rp "Choose build tools qmake[q] or cmake[c] ? " tool
case $tool in 
    q*) 
        tool=qmake
    ;;
    c*)
        tool=cmake
esac

if [[ "${tool}" == "cmake" ]]; then
    buildtool="cmake .."
elif [[ "${tool}" == "qmake" ]]; then
    buildtool="$HOME/Qt/6.2.7/gcc_64/bin/qmake6 ${PWD}/AM.pro"
fi


if [ -n "${buildtool}" ]; then
    rm -rf build || exit
    mkdir -p build || exit 
    cd build || exit
    eval "${buildtool}" 
    make -j8
    if [ -f ui_wrapper.sh ]; then
        mv ui_wrapper.sh AM.sh
    fi
fi
