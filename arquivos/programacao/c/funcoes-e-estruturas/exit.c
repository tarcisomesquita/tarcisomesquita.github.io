
/*

void exit(int status);

Terminate calling process
Terminates the process normally, performing the regular cleanup for terminating processes.

First, all functions registered by calls to atexit are executed in the reverse order of their registration. Then, all streams are closed and the temporary files deleted, and finally the control is returned to the host environment.

The status argument is returned to the host environment.

*/


//#include <stdlib.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0
extern void exit(int );


/* EXEMPLO */ 

int main(void)
{
    exit(EXIT_SUCCESS);
}



/* EXEMPLO */ 

/*
int main(void)
{
    return EXIT_SUCCESS;
}
*/

