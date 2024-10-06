
//#include<sys/cdefs.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define __STRING(x)	#x

extern int printf(const char *, ...);

int main()
{
   
   printf(__STRING(dst != NULL));
   return(0);
}

