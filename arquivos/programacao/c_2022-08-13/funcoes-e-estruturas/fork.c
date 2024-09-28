
// Clone the calling process, creating an exact copy.
// Return -1 for errors, 0 to the new process, and the process ID of the new process to the old process.
// A special zombie process state is introduced to represent terminated processes: a process remains in that state until its parent process executes a wait( ) system call on it. 
// waitpid( ) system call, which allows a process to wait for a specific child process
// When a process terminates, the kernel changes the appropriate process descriptor pointers of all the existing children of the terminated process to make them become children of init. This process monitors the execution of all its children and routinely issues wait( ) system calls, whose side effect is to get rid of all zombies.


// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int fork (void);

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

int main()
{
   int x;
   x = fork();
   fprintf(stdout, "x = %d\n Veja a lista de processos\n", x);
   for(;;);
   return(0);
}

