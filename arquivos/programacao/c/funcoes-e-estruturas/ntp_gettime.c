// gcc -Wall ntp_gettime.c -o ntp_gettime.elf  && ./ntp_gettime.elf 


// #include<bits/time.h>
struct timeval {
   long int tv_sec;  // Seconds
   long int tv_usec; // Microseconds
};

// #include<sys/timex.h>
struct ntptimeval {
   struct timeval time; // current time
   long int maxerror;   // maximum error
   long int esterror;   // estimated error
};

extern int ntp_gettime(struct ntptimeval *ntv);


extern int printf(char *, ...);

int main() {
   struct ntptimeval ntv;
   
   ntp_gettime(&ntv);
   
   printf("\n");
   printf("tv.time.tv_sec   = %+ld\n", ntv.time.tv_sec);
   printf("ntv.time.tv_usec = %+ld\n", ntv.time.tv_usec);
   printf("ntv.maxerror     = %+ld\n", ntv.maxerror);
   printf("ntv.esterror     = %+ld\n", ntv.esterror);
   printf("\n");
   
   printf("time = %ld.%ld\n\n", ntv.time.tv_sec, ntv.time.tv_usec);
   
   return 0;
}

