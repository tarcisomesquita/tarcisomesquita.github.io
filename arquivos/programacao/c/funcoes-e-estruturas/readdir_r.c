
// Reentrant version of `readdir'.
// Return in RESULT a pointer to the next entry.
// returns zero and sets *result to entry

// #include<bits/dirent.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// The name of the file for each entry is stored in the d_name.
struct dirent
{
   unsigned long int d_ino;       // está relacionado aos atributos do arquivo
   long int d_off;                // 
   unsigned short int d_reclen;   // length of filename sem o zero.
   unsigned char d_type;          // type of file. Veja a lista abaixo.
   char d_name[256];              // null terminated file name componte
};

// File types for `d_type'.
enum
{
    DT_UNKNOWN = 0,
# define DT_UNKNOWN	DT_UNKNOWN
    DT_FIFO = 1,
# define DT_FIFO	DT_FIFO
    DT_CHR = 2,
# define DT_CHR		DT_CHR
    DT_DIR = 4,
# define DT_DIR		DT_DIR
    DT_BLK = 6,
# define DT_BLK		DT_BLK
    DT_REG = 8,
# define DT_REG		DT_REG
    DT_LNK = 10,
# define DT_LNK		DT_LNK
    DT_SOCK = 12,
# define DT_SOCK	DT_SOCK
    DT_WHT = 14
# define DT_WHT		DT_WHT
};


// #include<dirent.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/// This is the data type of directory stream objects.
//   The actual structure is opaque to users.
typedef struct __dirstream DIR;

// #include<dirent.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern struct dirent *readdir(DIR *__dirp);
extern DIR *opendir (const char *__name);
extern int readdir_r (DIR *__restrict __dirp, struct dirent *__restrict __entry, struct dirent **__restrict result);


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


// #include<fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int open (const char *file, int oflag, ...);

// #include<bits/fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define O_RDONLY	     00


// #include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
extern char *strerror(int errnum);


// #include<errno.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int *__errno_location(void);
#define errno (*__errno_location())


int main()
{
   DIR *a;
   struct dirent entry, *result;

   a = (DIR *)opendir("/home/ubuntu/Desktop/teste");

   fprintf(stdout,"\n");
   for(;;)
   {
      readdir_r(a, &entry, &result);
      if(result == 0)
         break;
      fprintf(stdout,"entry.d_ino    = %lu\n", entry.d_ino);
      fprintf(stdout,"entry.d_off    = %ld\n", entry.d_off);
      fprintf(stdout,"entry.d_reclen = %hu\n", entry.d_reclen);
      fprintf(stdout,"entry.d_type   = %02X\n", entry.d_type);
      fprintf(stdout,"entry.d_name   = %s\n", entry.d_name);
      fprintf(stdout,"\n");
   }
   fprintf(stdout,"\n");
   
   return 0;
}


