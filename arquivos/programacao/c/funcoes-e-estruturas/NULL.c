
//#include<linux/stddef.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define NULL ((void *)0)


/* EXEMPLO */

//#include <stdio.h>
int puts( const char *);


int main()
{
   char string[2];
   puts(" = = = = = = = = = = = = = = = = = = = = = = = = = = =");
   string[0] = 'T';
   puts(string);
   puts(" = = = = = = = = = = = = = = = = = = = = = = = = = = =");
   puts("Uma string tem que terminar com um caractere NULL = 0x00");
   string[1] = NULL;
   puts(string);
   puts(" = = = = = = = = = = = = = = = = = = = = = = = = = = =");
   string[1] = '\0';
   puts(string);
   puts(" = = = = = = = = = = = = = = = = = = = = = = = = = = =");
   return 0;
}

