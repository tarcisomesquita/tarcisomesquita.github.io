// gcc -Wall clock_gettime.c -o clock_gettime.elf -lrt && ./clock_gettime.elf

// #include<time.h>
// POSIX.1b structure for a time value. This is like a `struct timeval' but has nanoseconds instead of microseconds.
struct timespec {
   long int tv_sec;  // Seconds since the Epoch.
   long int tv_nsec; // Nanoseconds.
};

// #include<time.h>
// Get current value of clock CLOCK_ID and store it in TP.
extern int clock_gettime(int clock_id, struct timespec *tp);

// Return clock ID for CPU-time clock.
extern int clock_getcpuclockid(int pid, int *clock_id);


// #include<bits/time.h>
#define CLOCK_REALTIME           0   // Identifier for system-wide realtime clock.
#define CLOCK_MONOTONIC          1   // Monotonic system-wide clock.
#define CLOCK_PROCESS_CPUTIME_ID 2   // High-resolution timer from the CPU.
#define CLOCK_THREAD_CPUTIME_ID  3   // Thread-specific CPU-time clock.

extern int printf(char *, ...);

int main() {
   struct timespec tp;
   
   clock_gettime(CLOCK_REALTIME, &tp);
   
   printf("\ntp.tv_sec  = %+ld", tp.tv_sec);
   printf("\ntp.tv_nsec = %+ld\n\n", tp.tv_nsec);
   
   return 0;
}

