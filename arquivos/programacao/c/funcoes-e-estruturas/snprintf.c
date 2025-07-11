
// Maximum chars of output to write in MAXLEN

// #include<stdio.h>
extern int snprintf (char *s, unsigned long int MAXLEN, const char *format, ...);
extern int printf(char *, ...);

int main()
{
   char s[20];
   unsigned long int MAXLEN = 15;
   char teste1[] = "1234567890";
   
   
   snprintf (s, MAXLEN, "1234567890%s", teste1);
   printf("\n%s\n\n", s);
   return 0;
}

