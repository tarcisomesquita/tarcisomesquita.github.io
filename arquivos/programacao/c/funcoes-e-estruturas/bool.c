
//#include<stdbool.h> = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define bool	_Bool
#define true	1
#define false	0
#define __bool_true_false_are_defined	1


/* EXEMPLO */

//#include<stdbool.h>
int printf(char *, ...);


int main()
{
   bool display_return = true;
   printf("display_return = %d\n\n", display_return);
   return 0;
}

