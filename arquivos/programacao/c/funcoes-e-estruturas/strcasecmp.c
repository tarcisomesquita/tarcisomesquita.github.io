// clear ; gcc -Wall -o strcasecmp.elf strcasecmp.c && ./strcasecmp.elf ; echo $?

// Compare S1 and S2, ignoring case.
// Retorna 0 se S1 e S2 forem iguais.

// #include <string.h>
extern int strcasecmp(char *s1, char *s2);

int main() {
   return strcasecmp("tesTe", "teste");
}

