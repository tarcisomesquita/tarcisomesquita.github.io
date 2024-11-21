
/*
Many programs that don't read input from the terminal are designed to exit if any system call fails.
By convention, the error message from such a program should start with the program's name, sans directories.

You can find that name in the variable program_invocation_short_name;
the full file name is stored the variable program_invocation_name.
*/

// The library initialization code sets up both of these variables before calling main.

extern char *program_invocation_name;        // is the name that was used to invoke the program. It is the same as argv[0].
extern char *program_invocation_short_name;  // is the name that was used to invoke the program with directory names removed.

extern int printf(char *, ...);

int main()
{
   printf("%s\n",program_invocation_name);
   printf("%s\n",program_invocation_short_name);
   return(0);
}

