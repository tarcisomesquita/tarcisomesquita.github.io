
/*
The strndup() function returns a pointer to a new string which is a duplicate of the string s. If s is longer than n, only n characters are copied, and a terminating null byte ('\0') is added.
Memory for the new string is obtained with malloc and can be freed with free.

returns a pointer to the duplicated string, or NULL if insufficient memory was available and set errno to indicate the error. 
*/

typedef unsigned int size_t;


//#include <string.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
char *strndup(const char *s, size_t n);


//#include <stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(const char *, ...);


int main()
{
   char t[] = "Isso é um teste";
   char *pont;
   printf("t = %s\n", t);
   printf("strndup(t,7) = %s\n", strndup(t,7));
   printf("t = %p e strndup(t,7) = %p\n", &t, strndup(t,7));
   pont = t;
   printf("pont = t = %p %s\n", pont, pont);
   pont = strndup(t,7);
   printf("pont = strndup(t,7) = %p %s\n", pont, pont);
   return 0;
}

