
#include <math.h>
#include <stdio.h>

int
main (void)
{
  double x = sqrt (2.0);
  printf ("The square root of 2.0 is %f\n", x);
  return 0;
}

/*
$ gcc -Wall calc.c /usr/lib/libm.a -o calc


To avoid the need to specify long paths on the command line, the compiler provides a short-cut option ‘-l’ for linking against libraries. For example, the following command,

$ gcc -Wall calc.c -lm -o calc

is equivalent to the original command above using the full library name ‘/usr/lib/libm.a’. 
*/

