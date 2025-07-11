// clear ; gcc -Wall getrusage.c -o getrusage.elf && ./getrusage.elf

// #include<bits/time.h>
struct timeval {
   long int tv_sec;  // Seconds
   long int tv_usec; // Microseconds
};

// #include<bits/resource.h>
// Structure which says how much of each resource has been used. 
struct rusage {
   struct timeval ru_utime;   // Total amount of user time used. 
   struct timeval ru_stime;   // Total amount of system time used. 
   long int ru_maxrss;        // Maximum resident set size (in kilobytes). 
   long int ru_ixrss;         // Amount of sharing of text segment memory with other processes (kilobyte-seconds). 
   long int ru_idrss;         // Amount of data segment memory used (kilobyte-seconds). 
   long int ru_isrss;         // Amount of stack memory used (kilobyte-seconds). 
   long int ru_minflt;        // Number of soft page faults
   long int ru_majflt;        // Number of hard page faults (i.e. those that required I/O). 
   long int ru_nswap;         // Number of times a process was swapped out of physical memory. 
   long int ru_inblock;       // Number of input operations via the file system.
   long int ru_oublock;       // Number of output operations via the file system. 
   long int ru_msgsnd;        // Number of IPC messages sent. 
   long int ru_msgrcv;        // Number of IPC messages received. 
   long int ru_nsignals;      // Number of signals delivered. 
   long int ru_nvcsw;         // Number of voluntary context switches
   long int ru_nivcsw;        // Number of involuntary context switches
};

// Whose usage statistics do you want?
enum __rusage_who {
   RUSAGE_SELF = 0,       // The calling process.
   RUSAGE_CHILDREN = -1   // All of its terminated child processes.
};

// #include<sys/resource.h>
// Return resource usage information on process indicated by WHO and put it in *USAGE.
// Returns 0 for success, -1 for failure. 
extern int getrusage(int who, struct rusage *usage);

extern int printf(char *, ...);

// Returns number of seconds between b and a.
double calculate(const struct rusage *b, const struct rusage *a) {
   if (b == 0x00000000 || a == 0x00000000) return 0;
   else
      return ((
               ((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) - (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
               ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) - (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec))
              ) / 1000000.0);
}

int main() {
   struct rusage before, after;   // structs for timing data
   double time = 0.0; // for benchmarks
   int i;
   
   getrusage(RUSAGE_SELF, &before);
   for(i=0; i < 0x0FFFFFFF; i++);
   getrusage(RUSAGE_SELF, &after);
   
   // calculate time to load dictionary
   time = calculate(&before, &after);
   
   printf("TIME: %.2f s\n", time);
   
   return 0;
}

