// The program will be the equivalent of:

#include <stdio.h>
int main(void) {
   puts("hello,world");
   return 0;
}

// = = = = = = = = = = = = = = = = = = = = = =

// First, I translate it to use Win32 functions instead of the C runtime:

#define STD_OUTPUT_HANDLE -11UL
#define HELLO "hello, world\n"

__declspec(dllimport) unsigned long __stdcall GetStdHandle(unsigned long hdl);

__declspec(dllimport) unsigned long __stdcall WriteConsoleA(unsigned long hConsoleOutput, const void *buffer, unsigned long chrs, unsigned long *written, unsigned long unused);

static unsigned long written;

void startup(void) {
   WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),HELLO,sizeof(HELLO)-1,&written,0);
   return;
}

