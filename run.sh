#!/bin/bash
# Script that has to be run before vs code can debug

mkdir -p build
cd build/
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
./wordSearchTests
cd ..