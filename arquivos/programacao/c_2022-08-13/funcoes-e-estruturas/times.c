
// Store the CPU time used by this process and all its dead children (and their dead children) in BUFFER.
// Return the elapsed real time, or (long int) -1 for errors.
// All times are in CLK_TCKths of a second.

// #include<sys/times.h>
struct tms                // Structure describing CPU time used by a process and its children.
{                         // CPU time of:
    long int tms_utime;     // User
    long int tms_stime;     // System
                          // CPU time of dead children of:
    long int tms_cutime;    // User
    long int tms_cstime;    // System
};
extern long int times(struct tms *__buffer);

typedef long int clock_t;

extern int printf(char *, ...);

int main()
{
   struct tms tempo;
   int i;
   for(i=0;i<1000000000;i++); // the work.
   times(&tempo);
   printf("\ntempo.tms_utime  = %ld\ntempo.tms_stime  = %ld\ntempo.tms_cutime = %ld\ntempo.tms_cstime = %ld\n\n", \
              tempo.tms_utime, tempo.tms_stime, tempo.tms_cutime, tempo.tms_cstime);
   
   return 0;
}

