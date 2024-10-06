// gcc -Wall strtok.c -o strtok.elf && ./strtok.elf

//#include <string.h>
// Divide S into tokens separated by characters in DELIM.
extern char *strtok(char *s, char *delim);

extern int printf(char *, ...);

int main() {
   char teste[] = "isso é um teste.\n\n";
   
   printf("\n");
   printf("%s", strtok(teste, " "));
   printf("\n");
   printf("\n");
   return 0;
}


