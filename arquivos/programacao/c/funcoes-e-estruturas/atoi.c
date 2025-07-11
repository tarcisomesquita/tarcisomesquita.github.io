
/*
Converte números na forma de caracteres de uma string em número inteiro.
Ignora os espaços do início.
Aceita sinal de + ou - antes do número.
Ignora os caracteres após o número.
Não deve haver caracteres antes do número. Caso contrário, retorna 0.
*/

//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int atoi(const char *);


/* EXEMPLO */

//#include <stdio.h>
int printf(char *, ...);


int main()
{
   char s[] = "  -025 reais.";
   int n;
   n = atoi(s);
   printf("%d\n", n+2);
   return 0;
}

