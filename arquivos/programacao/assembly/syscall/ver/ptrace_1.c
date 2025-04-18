#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
//#include <asm/ptrace-abi.h>   /* For constants ORIG_EAX etc */

int main() {
   pid_t child;
   long orig_eax;
   
   child = fork();
   if(child == 0) {
      ptrace(PTRACE_TRACEME, 0, NULL, NULL);
      execl("/bin/ls", "ls", NULL);
   }
   else {
      wait(NULL);
      // When the system call occurs, the kernel saves the original contents of the eax register, which contains the system call number.
      orig_eax = ptrace(PTRACE_PEEKUSER, child, sizeof(long) * 11, NULL);
      printf("The child made a system call %ld\n", orig_eax);
      ptrace(PTRACE_CONT, child, NULL, NULL);
  }
  return 0;
}

