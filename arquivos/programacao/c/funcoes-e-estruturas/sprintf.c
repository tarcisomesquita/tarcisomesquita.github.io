
// Write formatted output to S.

//#include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int sprintf(char *string, char *format, ...);

extern int printf(char *, ...);

int func() {
   char var[4] = {0x53,0x53,0x53,0x52};
   unsigned int *realstack;   
   unsigned int *realbase;   
   unsigned int *p;
   
   asm volatile (
      "mov   %0, esp\n\t"
      : "=&r" (realstack)
      : 
   );
   
   asm volatile (
      "mov   %0, ebp\n\t"
      : "=&r" (realbase)
      : 
   );
   printf("realstack = %08X\n", (unsigned int)realstack);
   printf("realbase  = %08X\n\n", (unsigned int)realbase);
   
   for (p = realstack; p <= (realbase + 4); p++) printf("%08X ", *p);
   printf("\n");
   
   // buffer overflow; pode se fazer stack overflow
   sprintf(var, "%012d", (unsigned int)0x00000000);
   
   for (p = realstack; p <= (realbase + 4); p++) printf("%08X ", *p);
   printf("\n\n");

/*
   p = (int *)&var;
   printf("%08X ", (unsigned int)p);
   for (i = 0; i < 15 ; i++) {
      printf("%08X ", *p);
      p = p + i;
   }
   printf("%08X\n", (unsigned int)p);
*/
   printf("var = %s\n\n", var);
   
   return 0;
}

int main() {
   func();
   
   return 0;
}

