// clear ; gcc -Wall strncpy.c -o strncpy.elf && ./strncpy.elf | hexdump -C

// Copia no máximo n caracteres de origem para destino.
// Não coloca \0 no final de destino.
// Retorna destino.

// #include<string.h> // = = = = = = = = = = = = = = = =
// Copy no more than N characters of SRC to DEST.
extern char *strncpy(char *dest, const char *src, unsigned long int n);

extern int printf(char *, ...);

int main() {
   char var1[] = "12345678901234567890";
   char var2[10];
   
   // tudo o que já existia em var2 é alterado
   strncpy(var2, var1, sizeof(var2) - 1);   var2[sizeof(var2) - 1] = 0x00;
   printf("%s", var2);
   
   return 0;
}

