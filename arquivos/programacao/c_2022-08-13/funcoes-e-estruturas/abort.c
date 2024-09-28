
/* Abort execution and generate a core-dump.  */

//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void abort(void);

int main()
{
   abort();
   return 0;
}

