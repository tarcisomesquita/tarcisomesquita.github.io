
// Read a character from stdin

//#include<stdio.h>  // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int getchar(void);
extern int printf(const char *, ...);

int main()
{
   char val_c;
   for(;;)
   {
      printf("Digite uma letra\n");
      val_c = getchar();
      printf("Voce digitou [%c]\n",val_c);
      while(getchar() != '\n'); //limpa o buffer de stdin
   }
   return(0);
}

