

/* locates a character in a string, searching from the end

Returns a pointer to the last occurrence of character in the C string str.

The terminating null-character is considered part of the C string. Therefore, it can also be located to retrieve a pointer to the end of a string.

If the value is not found, the function returns a null pointer.
*/


//#include<stdio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(const char *, ...);


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern char *strrchr(const char *, int);


int main()
{
   char str[] = "This is a sample string";
   char *pch;
   pch = strrchr(str, 's');
   printf("Last occurence of 's' found at %d \n", pch-str+1);
   return 0;
}

