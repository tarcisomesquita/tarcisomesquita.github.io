
// Change the process's working directory to PATH.

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int chdir(const char *__path);
extern char *getcwd(char *__buf, unsigned long int __size);


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

int main()
{
   char *mydirectory;
   
   mydirectory = getcwd(0x00000000, 0x00000000);
   fprintf(stdout, "mydirectory = %s\n", mydirectory);

   chdir("../");
   mydirectory = getcwd(0x00000000, 0x00000000);
   fprintf(stdout, "mydirectory = %s\n", mydirectory);
   
   chdir("/media/arq_blue");
   mydirectory = getcwd(0x00000000, 0x00000000);
   fprintf(stdout, "mydirectory = %s\n", mydirectory);
   
   return 0;
}

