// gcc -Wall -static hello-exe.c -o hello-exe.exe

// objdump -d -M intel hello-exe.exe -o hello-exe.asm


#include <stdio.h>

int main() {
   printf("\nHello world exe!\n\n");
   return 3;
}

