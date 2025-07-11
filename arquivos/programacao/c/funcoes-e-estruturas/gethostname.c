// gcc -Wall -Werror gethostname.c -o gethostname.elf && ./gethostname.elf

// It returns the name of the computer that your program is running on. Use gethostbyname() to determine the IP address of your local machine.

// hostname receive the hostname
// size is the length in bytes of the hostname array
// returns 0 on successful completion, and -1 on error

//#include <unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int gethostname(char *hostname, unsigned long int size); 

extern int printf(char *, ...);

//#include <linux/limits.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define PATH_MAX        4096	// # chars in a path name including nul

int main() {
   char hostname[PATH_MAX];
   
   if (gethostname(hostname, sizeof(hostname) - 1)) {
      printf("\nERRO: unable to get hostname\n\n");
      return 1;
   }
   
   hostname[sizeof(hostname) - 1] = 0x00;
   printf("\nhostname = \"%s\"\n\n", hostname);
   return 0;
}

