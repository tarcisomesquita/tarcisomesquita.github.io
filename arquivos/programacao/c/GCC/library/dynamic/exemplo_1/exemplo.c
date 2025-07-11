// gcc -o exemplo.elf exemplo.c -L. -lprint && ./exemplo.elf

extern int printf(char *, ...);
extern void printstring(char *);

int main() {
   printf("In Main!\n");
   printstring("In Main!"); 
   return 0;
}

