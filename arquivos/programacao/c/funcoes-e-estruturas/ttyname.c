

// Return the pathname of the terminal FD is open on, or NULL on errors.

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern char *ttyname (int __fd);

// Standard file descriptors.
#define	STDIN_FILENO	0	// Standard input.
#define	STDOUT_FILENO	1	// Standard output.
#define	STDERR_FILENO	2	// Standard error output.

extern int printf(char *, ...);

int main()
{
   printf("ttyname(0) = \"%s\"\n", ttyname(0));
   return 0;
}

