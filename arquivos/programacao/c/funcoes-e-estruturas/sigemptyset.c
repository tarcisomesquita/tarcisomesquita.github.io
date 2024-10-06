
// Clear all signals from SET.

typedef struct
{
   unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} sigset_t;

//#include<signal.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int sigemptyset(sigset_t *__set);

