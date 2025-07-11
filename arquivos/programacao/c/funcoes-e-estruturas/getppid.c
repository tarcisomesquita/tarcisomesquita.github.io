

/* Get the process ID of the calling process's parent.  */

//#include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int getppid(void);


extern int printf(const char *, ...);


int main()
{
   printf("%d\n", getppid());
   for(;;);
   return(0);
}

