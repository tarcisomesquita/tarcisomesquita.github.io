
/*
va_start(va_list ap, paramN);
Initializes the object of type va_list passed as argument ap to hold the information needed to retrieve the additional arguments after parameter paramN with function va_arg.
A function that executes va_start, shall also execute va_end before it returns.


type va_arg(va_list ap, type)
Retrieve next argument
This macro expands to an expression that has the type type and the value of the next argument in the variable arguments list.

Notice also that va_arg does not determine either whether the retrieved argument is the last argument passed to the function (or even if it is an element past the end of that list). The function should be designed in such a way that the amount of parameters can be inferred in some way by the values of either the named parameters or the additional arguments already read.

type expression to be suitable for its use with va_arg it must be such that when an asterisk (*) would be appended to its right the resulting expression would be a valid pointer type to a type object.


Return Value
Returns the next additional argument as an expression of type type.
*/



//#include<stdarg.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)

//#include <stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
int printf(char *, ...);


void PrintFloats(int amount, ...)
{
   int i;
   double val;
   printf("Floats passed: ");
   va_list vl;
   va_start(vl,amount);
   for (i=0;i<amount;i++)
   {
      val = va_arg(vl,double);
      printf("\t%.2f",val);
   }
   va_end(vl);
   printf ("\n");
}

int main()
{
   PrintFloats(3,3.14159,2.71828,1.41421);
   return 0;
}



/*
//#include<stdarg.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)

//#include <stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
int printf(char *, ...);

void PrintLines(char *first, ...)
{
   char *str;
   va_list vl;
   
   str = first;
   
   va_start(vl,first);
   
   do
   {
      printf ("%s\n",str);
      str = va_arg(vl,char *);
   } while(str != '\0');
   
   va_end(vl);
}

int main()
{
   PrintLines("First","Second","Third","Fourth",'\0');
   return 0;
}
*/


/*
//#include<stdarg.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)


//#include <stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
int printf(char *, ...);


int FindMax(int amount, ...)
{
   int i, val, greater;
   va_list vl;
   va_start(vl, amount);
   greater = va_arg(vl, int);
   for(i=1;i<amount; i++)
   {
      val = va_arg(vl, int);
      greater = (greater>val)?greater:val;
   }
   va_end(vl);
   return greater;
}


int main()
{
   int m;
   m = FindMax(7, 702, 422, 631, 834, 892, 104, 772);
   printf("The greatest one is: %d\n",m);
   return 0;
}
*/
