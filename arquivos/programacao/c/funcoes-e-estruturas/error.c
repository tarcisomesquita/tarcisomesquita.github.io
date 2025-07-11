
/* Print a message with `fprintf (stderr, FORMAT, ...)';
   if ERRNUM is nonzero, follow it with ": " and strerror (ERRNUM).
   If STATUS is nonzero, terminate the program with `exit (STATUS)'.  */

// If error returns the global variable error_message_count is incremented by one to keep track of the number of errors reported.

// #include<error.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void error (int __status, int __errnum, const char *__format, ...);

int main()
{
   error(0,1,"isso é um teste %u \n", 5); // veja errnum em strerror.c
   return(0);
}

