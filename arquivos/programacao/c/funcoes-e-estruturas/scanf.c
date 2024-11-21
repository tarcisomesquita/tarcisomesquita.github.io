
int printf(char *__restrict, ...);
int scanf (const char *, ...);

int main(int argc, char **argv)
{
   int vari;
   float varf;
   printf("\nDigite um numero inteiro: ");
   scanf("%d", &vari);
   printf("Digite um numero real: ");
   scanf("%f", &varf);
   printf("\nVoce digitou %d e %f\n\n", vari, varf);
   return(0);
}

/*
A função scanf() deve ser utilizada para a entrada de variáveis numéricas (int, float e double).
O modo de utilizar é semelhante à função printf, porém, obrigatoriamente, deve colocar o símbolo & em frente ao nome da variável a ser lida.
Está definida em stdio.h

Com a função scanf deve-se utilizar os seguintes especificadores de formato:
Formato  Tipo
%d 	 int
%ld      long int
%u 	 unsigned int
%f 	 float
%lf 	 double

*/
