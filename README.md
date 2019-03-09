# Binary Tree

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/f7c3d2d70b014cd497ddd212d3b39fd5)](https://app.codacy.com/app/rdtscp/bin_tree?utm_source=github.com&utm_medium=referral&utm_content=rdtscp/bin_tree&utm_campaign=Badge_Grade_Dashboard)
[![Build Status](https://travis-ci.com/rdtscp/bin_tree.svg?branch=master)](https://travis-ci.com/rdtscp/bin_tree)
![License](https://img.shields.io/badge/License-MIT-brightgreen.svg)

Binary Tree implementation in C++. Built using CMake and Google Test. 

## Download

    git clone https://github.com/acwilson96/bin_tree
    cd bin_tree

The following should be run from within the "bin_tree" directory.

## Release Install

    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release ..
    make
    make install
    cd ..

## Debug Install & Run Unit Tests

    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Debug ..
    make
    make install
    ctest -V
    cd ..

## Uninstall

    cd build
    xargs rm < install_manifest.txt
    cd ..
    rm -rf ./build/
