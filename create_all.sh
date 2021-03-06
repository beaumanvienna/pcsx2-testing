#!/bin/bash
make clean
cd pcsx2
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DBUILTIN_PAD=ON -DBUILTIN_GS=ON -DBUILTIN_DEV9=ON -DBUILTIN_USB=ON `../detect_gtk_flags.sh` ..
cd ../../tests/pcsx2
make
