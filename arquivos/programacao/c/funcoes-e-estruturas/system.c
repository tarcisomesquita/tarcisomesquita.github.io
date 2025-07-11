
/*
system is a function used to execute subprocesses and commands, residing in stdlib.h.

a single string is passed to the system shell

the call will wait until the child process terminates and return its exit value

SIGCHLD will be blocked as system waits for the child to die; also, SIGINT and SIGQUIT are ignored

system will return -1 on failure prior to or at fork (e.g. process count limit reached) but will return 127 on failure after fork (e.g. unable to execute sh); 

Under POSIX, system forks and execs /bin/sh with two arguments: "-c" and command. While the behavior of sh is specified elsewhere, it is instructive to consider that command need not be a single command; it can in fact be a pipeline or even a series of pipelines. For example, consider a program that wishes to display a screenshot:

system ("pngtopnm \"My Screenshot.png\" | pnmtoxwd > out.xwd && xwud out.xwd");

This line exhibits an important consideration: since command will be parsed as a shell command line, quotes around e.g. file names must be escaped. This however raises security considerations, since if command is constructed from user-supplied data, an attacker may be able to break out of any quoting and execute an arbitrary command in the context of the parent; indeed, this is almost the canonical code injection exploit. It is thus considered sensible to only employ system on predetermined command strings, using other functions (spawn et al.) to pass user-supplied data in argv or passing such data through pipes or temporary files.

The child spawned by system inherits its parent's standard streams; thus the child can receive keyboard input and write to the terminal. Note that this means that the parent will not receive the child's output, except through the use of a redirection or tee.

*/


extern int system(const char *command);
extern int printf(const char *, ...);

int main()
{
   system("ls -a");
   printf("aqui\n");
   return 0;
}
