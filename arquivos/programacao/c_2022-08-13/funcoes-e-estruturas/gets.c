
/*
A função gets(nome) é usada para a entrada de string.
Está definida em stdio.h

o gcc diz: warning: the `gets' function is dangerous and should not be used.

The warning actually states that you should use the safer alternative that is not prone to Buffer Overflow Attacks.

You should always use fgets or getline instead.

*/


//#include<stdio.h>
int printf(char *, ...);
char *gets(char *);


int main()
{
   char nome[80];
   printf("\nDigite seu nome: ");
   gets(nome);
   printf("\nVoce digitou: %s\n", nome);
   return 0;
}


