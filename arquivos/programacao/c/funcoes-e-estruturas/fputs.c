
/*
Write string to stream
Writes the string pointed by str to the stream.
The function begins copying from the address specified (str) until it reaches the terminating null character ('\0'). This final null-character is not copied to the stream.

Parameters

str
    An array containing the null-terminated sequence of characters to be written.
stream
    Pointer to a FILE object that identifies the stream where the string is to be written.



Return Value
On success, a non-negative value is returned.
On error, the function returns EOF.

Escreve uma string em um arquivo. Retorna o último caracter gravado ou EOF em caso de erro.
*/


#include <stdio.h>

//int fputs(const char *, FILE *);

int main ()
{
   FILE * pFile;
   char sentence [256];

   printf ("Enter sentence to append: ");
   fgets (sentence,255,stdin);
   pFile = fopen ("mylog.txt","a");
   fputs (sentence,pFile);
   fclose (pFile);
   return 0;
}

