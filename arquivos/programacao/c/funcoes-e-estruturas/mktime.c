
// Return the `time_t' representation of TP and normalize TP.


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

extern long int mktime(struct tm *TP);
extern struct tm *localtime(const long int *TIMER);

typedef long int time_t; // precisão de um segundo

extern int printf(char *, ...);


int main()
{
   long int timer;
   char tm_zone[] = "UTF-8";
   struct tm *agora, antes;
   
   antes.tm_sec     = 30;         // Seconds.      [0-60] (1 leap second)
   antes.tm_min     = 30;         // Minutes.      [0-59]
   antes.tm_hour    = 14;         // Hours.        [0-23]
   antes.tm_mday    = 25;         // Day.          [1-31]
   antes.tm_mon     = 03;         // Month.        [0-11]
   antes.tm_year    = 120;        // Year- 1900.
   antes.tm_wday    = 00;         // Day of week.  [0-6]     Ignored
   antes.tm_yday    = 000;        // Days in year. [0-365]   Ignored
   antes.tm_isdst   = 01;         // DST.          [-1/0/1]
   antes.tm_gmtoff  = -7200;      // Seconds east of UTC.
   antes.tm_zone    = &tm_zone;   // Timezone abbreviation.

   timer = mktime(&antes);
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
   
   return 0;
}

