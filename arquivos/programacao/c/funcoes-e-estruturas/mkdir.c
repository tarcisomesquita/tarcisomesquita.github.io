// clear ; gcc -Wall -Werror mkdir.c -o mkdir.elf && ./mkdir.elf TESTE ; echo $?

// Create a new directory named PATH, with permission bits MODE.

// #include<bits/stat.h>
// Protection bits.  
#define	S_ISUID	04000	// Set user ID on execution.  
#define	S_ISGID	02000	// Set group ID on execution.  
#define	S_ISVTX	01000	// Save swapped text after use (sticky).  
#define	__S_IREAD	0400	// Read by owner.  
#define	__S_IWRITE	0200	// Write by owner.  
#define	__S_IEXEC	0100	// Execute by owner.  

// #include<sys/stat.h>
extern int mkdir (const char *path, unsigned int mode);

#define	S_IRUSR	__S_IREAD	// Read by owner.  
#define	S_IWUSR	__S_IWRITE	// Write by owner.  
#define	S_IXUSR	__S_IEXEC	// Execute by owner.  
// Read, write, and execute by owner.  
#define	S_IRWXU	(__S_IREAD|__S_IWRITE|__S_IEXEC)

#define	S_IRGRP	(S_IRUSR >> 3)	// Read by group.  
#define	S_IWGRP	(S_IWUSR >> 3)	// Write by group.  
#define	S_IXGRP	(S_IXUSR >> 3)	// Execute by group.  
// Read, write, and execute by group.  
#define	S_IRWXG	(S_IRWXU >> 3)

#define	S_IROTH	(S_IRGRP >> 3)	// Read by others.  
#define	S_IWOTH	(S_IWGRP >> 3)	// Write by others.  
#define	S_IXOTH	(S_IXGRP >> 3)	// Execute by others.  
// Read, write, and execute by others.  
#define	S_IRWXO	(S_IRWXG >> 3)

// Macros for common mode bit masks.  
# define ACCESSPERMS (S_IRWXU|S_IRWXG|S_IRWXO) // 0777 
# define ALLPERMS (S_ISUID|S_ISGID|S_ISVTX|S_IRWXU|S_IRWXG|S_IRWXO)// 07777 
# define DEFFILEMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)// 0666


int main(int argc, char **argv) {
   if (argc != 2) return 1;
   
   return mkdir(argv[1], 0777);;
}

