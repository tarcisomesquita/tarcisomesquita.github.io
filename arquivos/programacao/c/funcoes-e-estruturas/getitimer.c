
veja setitimer.c

int getitimer (int which, struct itimerval *old)

    The getitimer function stores information about the timer specified by which in the structure pointed at by old.

    The return value and error conditions are the same as for setitimer. 

ITIMER_REAL
    This constant can be used as the which argument to the setitimer and getitimer functions to specify the real-time timer.
ITIMER_VIRTUAL
    This constant can be used as the which argument to the setitimer and getitimer functions to specify the virtual timer.
ITIMER_PROF
    This constant can be used as the which argument to the setitimer and getitimer functions to specify the profiling timer. 

