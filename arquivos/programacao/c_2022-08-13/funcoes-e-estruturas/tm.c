// gcc -Wall tm.c -o tm.elf && ./tm.elf

// #include<time.h>
struct tm {
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

extern struct tm *localtime(long int *);
extern long int time(long int *TIMER);
extern char *asctime (const struct tm *tp);

extern int __daylight;
extern long int __timezone;

extern int printf(char *, ...);


int main() {
   struct tm *agora;
   long int timer;
   
   time(&timer);
   agora = localtime(&timer);
   printf("\n"
          "sec     = %d\n"
          "min     = %d\n"
          "hour    = %d\n"
          "mday    = %d\n"
          "mon     = %d\n"
          "year    = %d\n"
          "wday    = %d\n"
          "yday    = %d\n"
          "isdst   = %d\n"
          "gmtoff  = %ld\n"
          "tm_zone = %s\n"
          "\n", \
           agora[0].tm_sec,   \
           agora[0].tm_min,   \
           agora[0].tm_hour,  \
           agora[0].tm_mday,  \
           agora[0].tm_mon  + 1,   \
           agora[0].tm_year + 1900,  \
           agora[0].tm_wday + 1,  \
           agora[0].tm_yday + 1,  \
           agora[0].tm_isdst, \
           agora[0].tm_gmtoff, \
           agora[0].tm_zone \
         );
   printf("%s\n\n", asctime(agora));
   
   printf("daylight = %d   timezone = %ld\n\n", __daylight, __timezone);
   
   printf("%d/%d/%d %d:%d:%d %ld\n\n", agora[0].tm_mday, agora[0].tm_mon  + 1, agora[0].tm_year + 1900, \
                                      agora[0].tm_hour, agora[0].tm_min, agora[0].tm_sec, agora[0].tm_gmtoff);
   
   return 0;
}

