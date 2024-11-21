
/*
Retorna o nome do arquivo sem a raiz de diretórios.
*/

//#include<string.h>
extern char *basename(const char *);

/* EXEMPLO */

//#include <stdio.h>
int puts( const char *);


int main()
{
   char diretorio[] = "/home/tarciso/teste.txt";
   puts(basename(diretorio));
   return 0;
}

