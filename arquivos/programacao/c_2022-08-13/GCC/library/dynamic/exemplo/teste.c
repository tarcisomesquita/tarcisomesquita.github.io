// clear ; gcc -Wall teste.c UPPERCASE.so -o teste.elf && ./teste.elf && ldd ./teste.elf

int printUPPERCASE(char *);

int main() {
   printUPPERCASE("Isso é um teste.");
   return 0;
}

