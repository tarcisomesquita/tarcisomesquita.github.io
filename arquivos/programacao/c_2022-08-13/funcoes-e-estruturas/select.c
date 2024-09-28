
// blocks the program until input or output is ready on a specified set of file descriptors, or until a timer expires

/*
   Check the first NFDS descriptors each in:       // NFDS é o número N em __fds_bits[N] no struct fd_set
   READFDS (if not 0x00) for read readiness,
   WRITEFDS (if not 0x00) for write readiness
   EXCEPTFDS (if not 0x00) for exceptional conditions.
   If TIMEOUT is not 0x00, time out after waiting the interval specified therein.

   Returns the number of ready descriptors, or -1 for errors.
   Any signal will cause select to return immediately.
   errno:
      EBADF One of the file descriptor sets specified an invalid file descriptor.
      EINTR The operation was interrupted by a signal.
      EINVAL The timeout argument is invalid; one of the components is negative or too large
*/

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout, *stderr, *stdin;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

// #include<bits/time.h>
struct timeval {
   long int tv_sec;  // Seconds
   long int tv_usec; // Microseconds
};

// #include<sys/select.h> // = = = = = = = = = = = = = = = = = = = = = =
typedef struct {
   long int __fds_bits[512];
} fd_set;

#define	FD_SETSIZE 1024 // Number of descriptors that can fit in an `fd_set'.

extern int select (int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);


// initializes the file descriptor set set to be the empty set. 
#define FD_ZERO(s) {               \
   unsigned int __i;               \
   fd_set *__arr = s;	           \
   for (__i = 0; __i < 512; ++__i) \
   (__arr->__fds_bits)[__i] = 0;   \
}

// removes filedes from the file descriptor set set. 
#define __FD_CLR(d, s)     (((s)->__fds_bits)[((d) / 2)] &= ~((long int) 1 << ((d) % 2)))
#define	FD_CLR(fd, fdsetp)	__FD_CLR (fd, fdsetp)

// returns a nonzero value (true) if filedes is a member of the file descriptor set set, and zero (false) otherwise.
#define __FD_ISSET(d, s)   ((((s)->__fds_bits)[((d) / 2)] & ((long int) 1 << ((d) % 2))) != 0)
#define	FD_ISSET(fd, fdsetp)	__FD_ISSET (fd, fdsetp)

// adds filedes to the file descriptor set set. 
#define __FD_SET(d, s)     (((s)->__fds_bits)[((d) / 2)] |= ((long int) 1 << ((d) % 2)))
#define	FD_SET(fd, fdsetp)	__FD_SET (fd, fdsetp)


// Standard file descriptors.
#define	STDIN_FILENO	0 // Standard input.
#define	STDOUT_FILENO	1 // Standard output.
#define	STDERR_FILENO	2 // Standard error output.


// A server socket is considered ready for reading if there is a pending connection which can be accepted with accept
// A client socket is ready for writing when its connection is fully established

int main() {
   int i;
   struct {
      unsigned long int __fds_bits[512];
   } set;
   struct timeval timeout;
   
   for (i = 0; i < 512; i++) set.__fds_bits[i] = 0; // FD_ZERO(&set);
   set.__fds_bits[(STDIN_FILENO / 2)] |= ((long int) 1 << (STDIN_FILENO % 2)); // FD_SET(STDIN_FILENO, &set);
   
   timeout.tv_sec = 5; // espera por 5,5 segundos
   timeout.tv_usec = 500000;
   
   fprintf(stdout, "select returned %d.\n", select (FD_SETSIZE, (fd_set *)&set, 0x00, 0x00, &timeout));
   
   if ( (set.__fds_bits[(STDIN_FILENO / 2)] & (1 << (STDIN_FILENO % 2))) != 0 ) fprintf(stdout, "A key was pressed!\n"); // FD_ISSET(STDIN_FILENO, &set);
   else fprintf(stdout, "Timed out.\n");
   
   return 0;
}

