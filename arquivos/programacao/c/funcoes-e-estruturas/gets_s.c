
// char *gets_s(char *buffer, unsigned int sizeInCharacters);

#include <stdio.h> // gets_s não está definida aqui

int main()
{
   char stringArray[10] ;
   
   printf("please enter some text");
   gets_s(stringArray, sizeof(stringArray));
   return(0);
}

