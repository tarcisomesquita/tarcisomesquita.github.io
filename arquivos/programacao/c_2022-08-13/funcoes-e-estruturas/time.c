
// Return the current time and put it in *TIMER if TIMER is not NULL.
// Return -1 for error
// Calendar time value: represents the number of seconds elapsed since 00:00:00 on January 1, 1970, Coordinated Universal Time.

// #include<time.h>
extern long int time(long int *TIMER);

typedef long int time_t; // precisão de um segundo


