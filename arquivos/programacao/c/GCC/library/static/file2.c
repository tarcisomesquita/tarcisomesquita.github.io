// gcc -masm=intel -S file2.c -o file2.s

extern int printf(char *, ...);

void print2(char *frase) {
   printf("file2: \"%s\"\n", frase);
   return;
}

