
// #include <ctype.h>
extern int tolower (int);

extern int printf(char *, ...);

int main()
{
   int i;
   for (i = 65; i <= 90; i++)
   {
      printf("%d = %c ==> %c\n",i, i, tolower(i));
   }
   return(0);
}

