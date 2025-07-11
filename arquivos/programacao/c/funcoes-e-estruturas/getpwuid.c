// #include<pwd.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// The passwd structure.
struct passwd
{
  char *pw_name;         // Username.
  char *pw_passwd;       // Password.
  unsigned int pw_uid;   // User ID.
  unsigned int pw_gid;   // Group ID.
  char *pw_gecos;        // Real name.
  char *pw_dir;          // Home directory.
  char *pw_shell;        // Shell program.
};

// Search for an entry with a matching user ID.
extern struct passwd *getpwuid (unsigned int __uid);


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


int main()
{
   struct passwd *teste;
   teste = getpwuid(999);
   fprintf(stdout, "teste->pw_name = %s\n", teste->pw_name);
   fprintf(stdout, "teste->pw_passwd = %s\n", teste->pw_passwd);

   fprintf(stdout, "teste->pw_uid = %u\n", teste->pw_uid);
   fprintf(stdout, "teste->pw_gid = %u\n", teste->pw_gid);

   fprintf(stdout, "teste->pw_gecos = %s\n", teste->pw_gecos);
   fprintf(stdout, "teste->pw_dir = %s\n", teste->pw_dir);
   fprintf(stdout, "teste->pw_shell = %s\n", teste->pw_shell);
   return 0;
}

