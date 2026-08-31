#include <stdio.h>
#include <unistd.h>
#include <pty.h>
#include <utmp.h>

extern char *environ[];

int main(void) {
    int master;
    int slave;
    openpty(&master, &slave, NULL, NULL, NULL);
    
    pid_t pid = fork();
    if (pid == 0) {
        login_tty(slave);
        
        char* path = "/usr/bin/bash";
        char* argv[] = { path, NULL };
        execve(path, argv, environ);
    } else {
        printf("hello world: %d\n", pid);
    }
    return 0;
}
