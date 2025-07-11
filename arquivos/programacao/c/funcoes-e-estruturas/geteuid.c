
// Get the effective user ID of the calling process.

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern unsigned int geteuid (void);

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

int main()
{
   fprintf(stdout, "euid = %u\n", geteuid());
   return(0);
}

