
/* Get the process ID of the calling process.  */


//#include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int getpid(void);


extern int printf(const char *, ...);


int main()
{
   printf("%d\n", getpid());
   for(;;);
   return(0);
}

