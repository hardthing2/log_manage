#!/bin/bash

#############change your cross-compile path here####################
export CC=gcc
export LIBS=/lib/modules/4.10.0-28-generic/build
####################################################################
make
rm ./src/*.o
rm ./src/*mod*
rm mo*
rm Mo*
cp ./src/*.ko ./release
rm ./src/*.ko

echo "build success"
