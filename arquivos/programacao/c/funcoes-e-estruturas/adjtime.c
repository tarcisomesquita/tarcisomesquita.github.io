
// Adjust the current time of day by the amount in DELTA. (speeds up or slows down the system clock)
// If OLDDELTA is not NULL, it is filled in with the amount of time adjustment remaining to be done from the last `adjtime' call.
// This call is restricted to the super-user.
// return value is 0 on success and -1 on failure

// This function is typically used to synchronize the clocks of computers in a local network

// #include<bits/time.h>
struct timeval
{
    long int tv_sec;  // Seconds
    long int tv_usec; // Microseconds
};

// #include<sys/time.h>
extern int adjtime(const struct timeval *delta, struct timeval *olddelta);

