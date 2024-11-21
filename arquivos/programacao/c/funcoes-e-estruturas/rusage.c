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

