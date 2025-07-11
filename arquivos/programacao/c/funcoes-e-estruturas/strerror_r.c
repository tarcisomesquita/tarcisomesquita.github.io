
/* returns a pointer to a string describing the error code passed in the argument errnum */

/*
Veja as mensagens de erro em:
/usr/include/asm-generic/errno-base.h
/usr/include/asm-generic/errno.h
*/

typedef unsigned int size_t;

//#include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
extern int printf(char *, ...);

// #include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
extern char *strerror_r(int errnum, char *buf, size_t buflen);

int main()
{
   unsigned int i;
   char *s;
   char errbuf[1024];
   
   for(i=0;i<135;i++)
   {
      s = strerror_r(i, errbuf, sizeof errbuf);
      printf("errnum = %03u --> %s\n", i, s);
   }
   return 0;
}

