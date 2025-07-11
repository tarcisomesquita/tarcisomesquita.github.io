
// Return the `struct tm' representation of *TIMER in the local timezone.
// Return NULL for error

// #include<time.h>localtime((long int *)&(ttystat.st_atim.tv_sec));

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

extern struct tm *localtime(const long int *__timer);
extern long int time(long int *TIMER);


/* Defined in localtime.c.  */
extern char *__tzname[2];	/* Current timezone names.  */
extern int __daylight;		/* If daylight-saving time is ever in use.  */
extern long int __timezone;	/* Seconds west of UTC.  */



typedef long int time_t; // precisão de um segundo

extern int printf(char *, ...);


int main()
{
   struct tm *agora;
   long int timer;
   time(&timer);
   agora = localtime(&timer);
   printf("\nsec    = %d\nmin    = %d\nhour   = %d\nmday   = %d\nmon    = %d\nyear   = %d\nwday   = %d\nyday   = %d\nisdst  = %d\ngmtoff = %ld\n\n", \
           agora->tm_sec,   \
           agora->tm_min,   \
           agora->tm_hour,  \
           agora->tm_mday,  \
           agora->tm_mon,   \
           agora->tm_year,  \
           agora->tm_wday,  \
           agora->tm_yday,  \
           agora->tm_isdst, \
           agora->tm_gmtoff \
         );
   printf("\nThe time is %04d/%02d/%02d  %02d:%02d:%02d\n\n", \
            agora->tm_year+1900, agora->tm_mon + 1, agora->tm_mday, agora->tm_hour, agora->tm_min, agora->tm_sec);
   
   return 0;
}

