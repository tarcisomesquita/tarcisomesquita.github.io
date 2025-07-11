// clear ; gcc -fPIC -c libprint.c && ld -shared -soname libprint.so.1 -o libprint.so.1.0 -lc libprint.o && ldconfig -v -n . && ln -sf libprint.so.1 libprint.so && export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

// clear ; gcc -fPIC -c libprint.c && ld -shared -o libprint.so -lc libprint.o && export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

#include "stdio.h" 

void printstring(char* str) {
   printf("String: %s\n", str); 
}


// _init(void) and _fini(void) are called automatically by the dynamic loader whenever a library is loaded.

void _init() {
   printf("Inside _init()\n"); 
}

void _fini() {
   printf("Inside _fini()\n"); 
}

