
/*
atexit faz com que uma função seja chamada quando o programa terminar normalmente o que pode ocorrer via exit(3) ou quando for dado return na função main.
As funções registradas por último  são  chamadas primeiro e não recebem argumentos.
Retorna  0  se  tiver  êxito. Caso contrário, retorna -1 sem colocar um código de erro em errno.
*/

//#include <stdlib.h> = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int atexit(void (*function)(void));


/* EXEMPLO */

//#include <stdio.h> = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
int printf(char *, ...);


void teste()
{
   printf("Estou aqui também.\n\n");
}


void teste2()
{
   printf("E mais uma vez aqui.\n\n");
}


int main()
{
   atexit(teste);
   printf("Estou aqui.\n\n");
   atexit(teste2);
   return 0;
}

