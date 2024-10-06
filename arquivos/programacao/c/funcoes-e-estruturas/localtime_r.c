
// Return the `struct tm' representation of *TIMER in the local timezone.
// The result is placed in the object of type struct tm to which the parameter resultp points.
// If the conversion is successful the function returns a pointer to the object the result was written into, i.e., it returns resultp. 
// Return NULL for error

// #include<time.h>

// broken-down time is a binary representation of calendar time separated into year, month, day, and so on.

struct tm
{
   int tm_sec;          // Seconds.      [0-60] (1 leap second)
   int tm_min;          // Minutes.      [0-59]
   int tm_hour;         // Hours.        [0-23]
   int tm_mday;         // Day.          [1-31]
   int tm_mon;          // Month.        [0-11]
   int tm_year;         // Year- 1900.
   int tm_wday;         // Day of week.  [0-6]
   int tm_yday;         // Days in year. [0-365]
   int tm_isdst;        // DST.          [-1/0/1]
   long int tm_gmtoff;  // Seconds east of UTC.
   const char *tm_zone; // Timezone abbreviation.
};

extern struct tm *localtime_r(const long int *time, struct tm *resultp);
extern struct tm *localtime(const long int *__timer);
extern long int time(long int *TIMER);

typedef long int time_t; // precisão de um segundo

extern int printf(char *, ...);


int main()
{
   struct tm antes;
   long int timer;

   time(&timer);
   localtime_r(&timer, &antes);
   printf("\nsec    = %d\nmin    = %d\nhour   = %d\nmday   = %d\nmon    = %d\nyear   = %d\nwday   = %d\nyday   = %d\nisdst  = %d\ngmtoff = %ld\nzone   = %s\n\n", \
           antes.tm_sec,   \
           antes.tm_min,   \
           antes.tm_hour,  \
           antes.tm_mday,  \
           antes.tm_mon,   \
           antes.tm_year,  \
           antes.tm_wday,  \
           antes.tm_yday,  \
           antes.tm_isdst, \
           antes.tm_gmtoff,\
           antes.tm_zone   \
         );
   
   return 0;
}

