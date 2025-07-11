
para limpar buffer do teclado

#include<stdio_ext.h>

main()
{
   __fpurge(stdin);
   /* ...
   restante do programa */
} 


/*
 *  This C implementation will clear the input buffer.
 *  The chances are that the buffer will already be empty,
 *  so the program will wait until you press [Enter].
 */

#include <stdio.h> 

int main(void)
{
  int   ch;
  char  buf[BUFSIZ], a;
  
  a = getchar();
  puts("Flushing input");
  
  while ((ch = getchar()) != '\n' && ch != EOF);
  
  printf ("Enter some text: ");
  
  if (fgets(buf, sizeof(buf), stdin))
  {
    printf ("You entered: %s", buf);
  }
  
  return 0;
}

/*
 * Program output:
 *
 Flushing input
 blah blah blah blah
 Enter some text: hello there
 You entered: hello there
 *
 */


