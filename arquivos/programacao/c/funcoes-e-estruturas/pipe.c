
// Create a one-way communication channel (pipe).
//   If successful, two file descriptors are stored in PIPEDES;
//   bytes written on PIPEDES[1] can be read from PIPEDES[0].
//   Returns 0 if successful, -1 if not.

// errno = EMFILE (no free descriptors)
//         EMFILE (system file table is full)
//         EFAULT (fd array is not valid)


// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = =
extern int pipe (int __pipedes[2]);

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
   int     fd[2], nbytes;
   pid_t   childpid;
   char    string[] = "Hello, world!\n";
   char    readbuffer[80];
   pipe(fd);
   if((childpid = fork()) == -1)
   {
      perror("fork");
      exit(1);
   }
   if(childpid == 0)
   {
      /* Child process closes up input side of pipe */
      close(fd[0]);
      /* Send "string" through the output side of pipe */
      write(fd[1], string, strlen(string));
      exit(0);
   }
   else
   {
      /* Parent process closes up output side of pipe */
      close(fd[1]);
      /* Read in a string from the pipe */
      nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
      printf("Received string: %s", readbuffer);
   }
   return(0);
}

    If the parent wants to receive data from the child, it should close fd1, and the child
should close(fd[0]);. If the parent wants to send data to the child, it should close fd0, and
the child should close fd1. Since descriptors are shared between the parent and child


