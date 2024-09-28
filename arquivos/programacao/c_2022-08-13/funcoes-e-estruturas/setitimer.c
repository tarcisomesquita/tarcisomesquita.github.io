
// Set the timer WHICH to *NEW.  If OLD is not NULL, set *OLD to the old value of timer WHICH.
// Returns 0 on success, -1 on errors.
// errno: EINVAL The timer period is too large. 

// #include<bits/time.h>
struct timeval
{
    long int tv_sec;  // Seconds
    long int tv_usec; // Microseconds
};

// #include<sys/time.h>
struct itimerval
{
   struct timeval it_interval; // Value to put into `it_value' when the timer expires. period between successive timer interrupts
   struct timeval it_value;    // Time to the next timer expiration. If zero, the alarm is disabled
};
extern int setitimer(int WHICH, const struct itimerval *NEW, struct itimerval *OLD);


enum __itimer_which // Values for the first argument to `getitimer' and `setitimer'.
{
   ITIMER_REAL = 0,    // Timers run in real time.
   ITIMER_VIRTUAL = 1, // Timers run only when the process is executing.
   ITIMER_PROF = 2     // Timers run when the process is executing and when the system is executing on behalf of the process.
};

unsigned int alarm (unsigned int seconds)
{
   struct itimerval old, new;
   new.it_interval.tv_usec = 0;
   new.it_interval.tv_sec = 0;
   new.it_value.tv_usec = 0;
   new.it_value.tv_sec = (long int) seconds;
   if (setitimer(ITIMER_REAL, &new, &old) < 0)
      return 0;
   else
      return old.it_value.tv_sec;
}

