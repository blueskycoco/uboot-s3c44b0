#!/bin/sh

export ARCH=arm
export CROSS_COMPILE=arm-none-eabi-
make -j4
