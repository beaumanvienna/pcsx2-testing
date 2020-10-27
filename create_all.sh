#!/bin/bash
make clean
cd pcsx2
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DGTK3_API=ON ..
cd ../../tests/pcsx2
make
