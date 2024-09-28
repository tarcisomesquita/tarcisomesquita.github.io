
// Get shared memory segment.

//#include<sys/shm.h>
extern int shmget (int key, long unsigned int size, int shmflg);

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern struct _IO_FILE *stderr;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

struct INSTANCE
{
   int pid;
   char debug;
   char version;
   short interval;
   char Last_IP_Addr[16];
   char cfilename[256];
   char args[256 - (2 *16)];
} *my_instance = ((void *)0);

int main()
{
   int xid;
   xid = shmget(0x50494f4e, (4 * sizeof(struct INSTANCE)), 0);
   fprintf(stdout,"xid = 0x%08X\n",xid);

   return(0);
}

