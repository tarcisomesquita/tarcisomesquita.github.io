// clear ; gcc -c file2.c file3.c && ar cru libfile.a file2.o file3.o && ranlib libfile.a && gcc file1.c -L. -lfile -o file.elf && ./file.elf "É um teste."
// clear ; gcc -c file2.c file3.c && ar crs libfile.a file2.o file3.o && gcc file1.c -L. -lfile -o file.elf && ./file.elf "É um teste."

extern int printf(char *, ...);
extern void print2(char *);
extern void print3(char *);

int main(int argc, char **argv) {
   printf("file1: \"%s\"\n", argv[1]);
   print2(argv[1]);
   print3(argv[1]);
   
   return 0;
}

