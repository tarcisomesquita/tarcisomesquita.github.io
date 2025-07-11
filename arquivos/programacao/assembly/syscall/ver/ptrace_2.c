#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int do_child(int argc, char **argv);
int do_trace(pid_t child);

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s prog args\n", argv[0]);
        exit(1);
    }
    
    pid_t child = fork();
    if (child == 0) {
        return do_child(argc-1, argv+1);
    } else {
        return do_trace(child);
    }
}

int do_child(int argc, char **argv) {
    char *args [argc+1];
    memcpy(args, argv, argc * sizeof(char*));
    args[argc] = NULL;
    
    ptrace(PTRACE_TRACEME);
    kill(getpid(), SIGSTOP);
    return execvp(args[0], args);
}

int wait_for_syscall(pid_t child);

int do_trace(pid_t child) {
    long int syscall;
    int status;
    waitpid(child, &status, 0);

/*
PTRACE_SETOPTIONS lets us set a number of options for how we want to trace the child. We use it here to set PTRACE_O_TRACESYSGOOD, which means that when the child stops for a syscall-related reason, we'll actually see it stopped with signal number SIGTRAP | 0x80, so we can easily distinguish syscall stops from other stops. */
    ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
    while(1) {
        if (wait_for_syscall(child) != 0) break;
        syscall = ptrace(PTRACE_PEEKUSER, child, sizeof(long)*11);
        fprintf(stderr, "syscall(%ld) = \n", syscall);
     }
    return 0;
}

int wait_for_syscall(pid_t child) {
    int status;
    while (1) {
        ptrace(PTRACE_SYSCALL, child, 0, 0);
        
        waitpid(child, &status, 0);
        if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80) return 0;
        if (WIFEXITED(status)) return 1;
    }
}

/*
char *read_string(pid_t child, unsigned long addr) {
    char *val = malloc(4096);
    int allocated = 4096, read;
    unsigned long tmp;

    while (1) {
        if (read + sizeof tmp > allocated) {
            allocated *= 2;
            val = realloc(val, allocated);
        }

        // PTRACE_PEEKDATA returns data from the child at the specified offset.
        tmp = ptrace(PTRACE_PEEKDATA, child, addr + read);
        if(errno != 0) { val[read] = 0; break; }
        
        memcpy(val + read, &tmp, sizeof tmp);
        if (memchr(&tmp, 0, sizeof tmp) != NULL) break;
        read += sizeof tmp;
    }
    return val;
}
*/

