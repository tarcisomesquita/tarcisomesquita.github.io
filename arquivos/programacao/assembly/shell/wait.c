// clear ; gcc -Wall wait.c -o wait.elf && ./wait.elf

//#include<bits/waitstatus.h>
union wait {
   int w_status;
   struct {
      unsigned int __w_termsig:7;  // Terminating signal.
      unsigned int __w_coredump:1; // Set if dumped core.
      unsigned int __w_retcode:8;  // Return code if exited normally.
      unsigned int:16;
   } __wait_terminated;
   struct {
      unsigned int __w_stopval:8; // W_STOPPED if stopped.
      unsigned int __w_stopsig:8; // Stopping signal.
      unsigned int:16;
   } __wait_stopped;
};

// This works in GCC 2.6.1 and later.
typedef union {
   union wait *__uptr;
   int *__iptr;
} __WAIT_STATUS;

typedef int __pid_t; // Type of process identifications.

//#include<sys/wait.h>
// Wait for a child to die.  When one does, put its status in *STAT_LOC and return its process ID.  For errors, return (pid_t) -1.
extern __pid_t wait(__WAIT_STATUS stat_loc);

extern int printf(char *, ...);

int main() {
   __WAIT_STATUS status;
   
   wait(status);
   
   printf("\n");
   printf("status.__iptr[0] = %d\n", status.__iptr[0]);
   printf("\n");
   printf("status.__uptr[0].w_status = %d\n", status.__uptr[0].w_status);
   printf("status.__uptr[0].__wait_terminated.__w_termsig  = %03u", status.__uptr[0].__wait_terminated.__w_termsig);
   printf("   // Terminating signal.\n");
   printf("status.__uptr[0].__wait_terminated.__w_coredump = %03u", status.__uptr[0].__wait_terminated.__w_coredump);
   printf("   // Set if dumped core.\n");
   printf("status.__uptr[0].__wait_terminated.__w_retcode  = %03u", status.__uptr[0].__wait_terminated.__w_retcode);
   printf("   // Return code if exited normally.\n");
   printf("\n");
   printf("status.__uptr[0].__wait_stopped.__w_stopval = %03u", status.__uptr[0].__wait_stopped.__w_stopval);
   printf("   // W_STOPPED if stopped.\n");
   printf("status.__uptr[0].__wait_stopped.__w_stopsig = %03u", status.__uptr[0].__wait_stopped.__w_stopsig);
   printf("   // Stopping signal.\n");
   printf("\n");
   
   return 0;
}

