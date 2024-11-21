
// Make the process sleep for SECONDS seconds, or until a signal arrives and is not ignored.
// The function returns the number of seconds less than SECONDS which it actually slept (thus zero if it slept the full time).
//  If a signal handler does a `longjmp' or modifies the handling of the

// #include<unistd.h>
extern unsigned int sleep(unsigned int SECONDS);


