
// Sets the current calendar time in the system clock. Time zone information is ignored if tzp is a null pointer.
// You must be a privileged user
// causes a sudden jump forwards or backwards, which can cause a variety of problems in a system. Use adjtime function to make a smooth transition from one time to another by temporarily speeding up or slowing down the clock.
// The return value is 0 on success and -1 on failure. 

// errno:
// EPERM This process cannot set the clock because it is not privileged.
// ENOSYS The operating system does not support setting time zone information, and tzp is not a null pointer.

// #include<bits/time.h>
struct timeval
{
    long int tv_sec;  // Seconds
    long int tv_usec; // Microseconds
};


// #include<sys/time.h>
struct timezone  // OBSOLETE
{
   int tz_minuteswest; // Minutes west of GMT(Greenwich Mean Time) (UTC - Coordinated Universal Time).
   int tz_dsttime;     // Nonzero if DST is ever in effect. (Daylight Saving Time applies during some part of the year. )
};

extern int settimeofday (const struct timeval *tp, const struct timezone *tzp);


