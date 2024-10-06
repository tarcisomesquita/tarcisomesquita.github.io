
// TYPEDEF É usado para criar um novo tipo de variável. Pode ser usado inclusive com struct.

extern int printf(char *, ...);

typedef int integer;
typedef int *ptr_int;
typedef char linha[80];

int main() {
   integer numero;
   ptr_int ponteiro;
   linha frase = "Isso funciona?";
   
   printf("frase = %s\n", frase);
   
   ponteiro = (int *)frase;
   numero = (int)ponteiro;
   
   printf("ponteiro = 0x%08X\n", (unsigned int)ponteiro);
   printf("numero   = 0x%08X\n", (unsigned int)numero);
   
   return 0;
}
