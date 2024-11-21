
/*
SYSTEM CALL: dup();
PROTOTYPE: int dup( int oldfd );
  RETURNS: new descriptor on success
           -1 on error: errno = EBADF (oldfd is not a valid descriptor)
                                 EBADF (newfd is out of range)
                                 EMFILE (too many descriptors for the process)
NOTES: the old descriptor is not closed!   Both may be used interchangeab
*/

childpid = fork();
if(childpid == 0)
{
        /* Close up standard input of the child */
        close(0);
        /* Duplicate the input side of pipe to stdin */
        dup(fd[0]);
        execlp("sort", "sort", NULL);
        .
}




SYSTEM CALL: dup2();
PROTOTYPE: int dup2( int oldfd, int newfd );
  RETURNS: new descriptor on success
           -1 on error: errno = EBADF (oldfd is not a valid descriptor)
6.2. HALF-DUPLEX UNIX PIPES                                 23
                                   EBADF (newfd is out of range)
                                   EMFILE (too many descriptors for the process)
   NOTES: the old descriptor is closed with dup2()!


.
.
childpid = fork();
if(childpid == 0)
{
        /* Close stdin, duplicate the input side of pipe to stdin */
        dup2(0, fd[0]);
        execlp("sort", "sort", NULL);
        .
        .
}

