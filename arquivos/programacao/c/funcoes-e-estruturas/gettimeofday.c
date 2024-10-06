// gcc -Wall gettimeofday.c -o gettimeofday.elf  && ./gettimeofday.elf 

// #include<bits/time.h>
// A time value that is accurate to the nearest microsecond but also has a range of years.
struct timeval {
   long int tv_sec;  // Seconds
   long int tv_usec; // Microseconds
};

// #include<sys/time.h>
// Structure crudely representing a timezone. This is obsolete and should never be used.
struct timezone {
   int tz_minuteswest; // Minutes west of GMT.
   int tz_dsttime;     // Nonzero if DST is ever in effect.
};

// #include<sys/time.h>
// Get the current time of day and timezone information, putting it into *TV and *TZ.
// If TZ is NULL, *TZ is not filled.
// Returns 0 on success, -1 on errors.
// NOTE: This form of timezone information is obsolete.
extern int gettimeofday(struct timeval *tv, struct timezone *tz);

extern int printf(char *, ...);

int main() {
   struct timeval tv;
   
   gettimeofday(&tv, 0x00000000);
   
   printf("\ntv.tv_sec  = %+ld", tv.tv_sec);
   printf("\ntv.tv_usec = %+ld\n\n", tv.tv_usec);
   
   printf("time = %ld.%ld\n\n", tv.tv_sec, tv.tv_usec);
   
   return 0;
}

//extern int ntp_gettime (struct ntptimeval *__ntv) __THROW;


// #include<sys/timex.h>


