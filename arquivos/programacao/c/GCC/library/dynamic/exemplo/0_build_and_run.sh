#!/bin/bash

# -fpic Generate position-independent code (PIC) suitable for use in a shared library
# Such code accesses all constant addresses through a global offset table (GOT).
# The dynamic loader resolves the GOT entries when the program starts

clear

if [ -f UPPERCASE.o ]; then rm UPPERCASE.o; fi
gcc  -c -fpic UPPERCASE.c

if [ -f UPPERCASE.so ]; then rm UPPERCASE.so; fi
gcc -shared -lc  -o UPPERCASE.so  UPPERCASE.o 


export LD_LIBRARY_PATH=$(pwd)  # relative path test
if [ -f lowercase.o ]; then rm lowercase.o
fi
gcc  -c -fpic lowercase.c
if [ -f lowercase.so ]; then rm lowercase.so
fi
gcc -shared -lc  -o lowercase.so  lowercase.o


if [ -f dlTest ]; then rm dlTest
fi
gcc -o dlTest dlTest.c -ldl
./dlTest

