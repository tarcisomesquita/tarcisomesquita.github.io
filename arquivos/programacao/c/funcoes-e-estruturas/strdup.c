
/*
The strdup() function returns a pointer to a new string which is a duplicate of the string s.
Memory for the new string is obtained with malloc and can be freed with free.

returns a pointer to the duplicated string, or NULL if insufficient memory was available and set errno to indicate the error. 
*/

//#include <string.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern char *strdup(const char *s);


//#include <stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(const char *, ...);


int main()
{
   char t[] = "Isso é um teste";
   char *pont;
   printf("t = %s\n", t);
   printf("strdup(t) = %s\n", strdup(t));
   printf("t = %p e strdup(t) = %p\n", &t, strdup(t));
   pont = t;
   printf("pont = t = %p %s\n", pont, pont);
   pont = strdup(t);
   printf("pont = strdup(t) = %p %s\n", pont, pont);
   return 0;
}

