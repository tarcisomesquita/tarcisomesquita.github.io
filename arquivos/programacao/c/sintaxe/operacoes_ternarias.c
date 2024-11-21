
/*
Sintaxe:
   (exp1)?exp2:exp3

A expressão exp1 é avaliada, se for verdadeira o conjunto assume o valor da expressão exp2 senão assume o valor da expressão exp3.
*/

#include <stdio.h>

int main(void)
{
   int n1=5, n2=20, maior;
   
   maior = (n1>n2)?n1:n2;
   printf("%03d",maior);
   printf("O maior e' %s", (maior==n1)?"N1":"N2");
}
