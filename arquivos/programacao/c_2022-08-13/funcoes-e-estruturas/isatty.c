
/*
Return 1 if FD is a valid descriptor associated with a terminal, zero if not.
*/
// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int isatty(int __fd);

// Standard file descriptors.
#define	STDIN_FILENO	0	// Standard input.
#define	STDOUT_FILENO	1	// Standard output.
#define	STDERR_FILENO	2	// Standard error output.

int main()
{
   return isatty(STDIN_FILENO);
}

