
/*
the running process is replaced by the program passed as an argument
the process ID (PID) does not change across an execute
the data, heap and stack of the calling process are replaced by those of the new process.
Files open when an exec call is made remain open in the new process.
*/

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
// Execute PATH with all arguments after PATH until a NULL pointer and environment from `environ'.
extern int execl (const char *path, const char *arg, ...);
int main()
{
   execl("teste2.elf", "zero", "um", "dois", (char *)0);
   // em teste2.elf temos argv[0] = "zero", argv[1] = "um", etc.
   return(0);
}


/*

// Execute PATH with all arguments after PATH until a NULL pointer, and the argument after that for environment.
extern int execle(const char *path, const char *arg, ...);

// Replace the current process, executing PATH with arguments ARGV and environment ENVP.
// ARGV and ENVP are terminated by NULL pointers.
extern int execve (const char *path, const char *argv[], const char *envp[]);
In Unix, the loader is the handler for the system call execve().[1] The Unix loader's tasks include:
   1. validation (permissions, memory requirements etc.);
   2. copying the program image from the disk into main memory;
   3. copying the command-line arguments on the stack;
   4. initializing registers (e.g., the stack pointer);
   5. jumping to the program entry point (_start).


// Execute the file FD refers to, overlaying the running program image.
//   ARGV and ENVP are passed to the new program, as for `execve'.
extern int fexecve (int __fd, char *const __argv[], char *const __envp[]);

// Execute PATH with arguments ARGV and environment from `environ'.
extern int execv (const char *__path, char *const __argv[]);



// Execute FILE, searching in the `PATH' environment variable if it contains no slashes, with arguments ARGV and environment from `environ'.
extern int execvp (const char *__file, char *const __argv[]);

// Execute FILE, searching in the `PATH' environment variable if it contains no slashes, with all arguments after FILE until a NULL pointer and environment from `environ'. 
extern int execlp (const char *file, const char *arg, ...);


    int execl(char const *path, char const *arg0, ...);
    int execle(char const *path, char const *arg0, ..., char const * const *envp);
    int execlp(char const *path, char const *arg0, ...);
    int execlpe(char const *path, char const *arg0, ...);
    int execv(char const *path, char const * const * argv);
    int execve(char const *path, char const * const *argv, char const * const *envp);
    int execvp(char const *path, char const * const *argv);
    int execvpe(char const *path, char const * const *argv, char const * const *envp); 


Function names

The base of each function is exec, followed by one or more letters:

    e - An array of pointers to environment arguments is explicitly passed to the new process image.
    l - Command-line arguments are passed individually to the function.
    p - Uses the path environment variable to find the file named in the path argument to be executed.
    v - Command-line arguments are passed to the function as an array of pointers.

[edit] path

The path argument specifies the path name of the file to execute as the new process image. Arguments arg0 through argn are a list of pointers to arguments to be passed to the new process image. argv is an array of pointers to arguments.
[edit] arg0

The first argument arg0 should be the name of the executable file. Usually it is the same value as the path argument. Some programs may incorrectly rely on this argument providing the location of the executable, but there is no guarantee of this nor is it standardized across platforms.
[edit] envp

Argument envp is an array of pointers to environment settings. The execle, execlpe, execve, and execvpe calls alter the environment for the new process image by passing a list of environment settings through the envp argument. This argument is an array of character pointers; each element (except for the final element) points to a null-terminated string defining an environment variable.

Each null-terminated string has the form:

    name=value

where name is the environment variable name, and value is the value of that that variable. The final element of the envp array must be null. If envp itself is null, the new process inherits the current environment settings.
[edit] Return Value

The exec functions do not normally return to the calling process. If an exec function returns, an error occurred, the return value is -1, and errno is set to one of the following values:
Name 	Notes
E2BIG 	The argument list exceeds the system limit.
EACCES 	The specified file has a locking or sharing violation.
ENOENT 	The file or path name not found.
ENOMEM 	Not enough memory is available to execute the new process image.

*/
