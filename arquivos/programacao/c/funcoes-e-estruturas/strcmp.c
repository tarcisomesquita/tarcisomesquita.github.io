/*
strcmp

Sua forma geral é:

 strcmp (string1,string2);

 A função strcmp() compara a string 1 com a string 2. Se as duas forem idênticas a função retorna zero. Se elas forem diferentes a função retorna não-zero. Um exemplo da sua utilização: 

compara duas strings retomando
0- se iguais
1-	se a 1a. for maior que 2a.
2-	se a 2a. for maior que 1a.

*/

#include <stdio.h>

// #include <string.h>
extern int strcmp(const char *s1, const char *s2);

int main ()
{
	char str1[100],str2[100];
	printf ("Entre com uma string: ");
	gets (str1);
	printf ("\n\nEntre com outra string: ");
	gets (str2);
	if (strcmp(str1,str2))
        	printf ("\n\nAs duas strings são diferentes.");
	else printf ("\n\nAs duas strings são iguais.");
	return(0);
}
