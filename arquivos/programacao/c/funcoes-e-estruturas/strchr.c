
/*
Locate first occurrence of character in string str
Returns a pointer to the first occurrence of character in the C string str.
Returns a null pointer if character is not found
The terminating null-character is considered part of the C string. Therefore, it can also be located to retrieve a pointer to the end of a string.
*/

//#include<string.h>
const char *strchr(const char *str, int character);


//#include<stdio.h>
int printf(char *, ...); 


/* EXEMPLO */
int main()
{
  char str[] = "This is a sample string";
  char *pch;
  printf("Looking for the 's' character in \"%s\"...\n",str);
  pch = strchr(str,'s');
  while(pch!='\0')
  {
    printf("found at %d\n",pch-str+1);
    pch = strchr(pch+1,'s');
  }
  return 0;
}

