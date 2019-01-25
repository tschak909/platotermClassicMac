#!/bin/bash

rm -rf build && mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=~/Retro68/Retro68build/toolchain/m68k-apple-macos/cmake/retro68.toolchain.cmake && make && cp PLATOTERM.dsk /mnt/d/BasiliskII/
