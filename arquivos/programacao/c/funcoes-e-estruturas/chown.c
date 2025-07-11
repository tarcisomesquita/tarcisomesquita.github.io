
// changes the ownership of a file. New owner can be specified as numeric user ID, or as username (which is converted to a user ID by using getpwnam).

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   uid_t uid;
   struct passwd *pwd;
   char *endptr;
   
   if (argc != 3 || argv[1][0] == '\0') {
      fprintf(stderr, "%s <owner> <file>\n", argv[0]);
      return 1;
   }
   
   uid = strtol(argv[1], &endptr, 10);
   
   // Was not pure numeric string
   if (*endptr != '\0') {
      pwd = getpwnam(argv[1]);  // Try getting UID for username
      if (pwd == NULL) {
         perror("getpwnam");
         return 1;
      }
      uid = pwd->pw_uid;
   }
   
   if (chown(argv[2], uid, -1) == -1) {
      perror("chown");
      return 1;
   }
   
   return 0;
}

/*
CHOWN(2)
3.54 man-pages
http://www.kernel.org/doc/man-pages/
2010-11-22

SYNOPSIS
#include <unistd.h>

int chown(const char *path, uid_t owner, gid_t group);
int fchown(int fd, uid_t owner, gid_t group);
int lchown(const char *path, uid_t owner, gid_t group);

DESCRIPTION
These system calls change the owner and group of a file.  They differ only in how the file is specified:
* chown()  changes the ownership of the file specified by path, which is dereferenced if it is a symbolic link.
* fchown() changes the ownership of the file referred to by the open file descriptor fd.
* lchown() is like chown(), but does not dereference symbolic links.

RETURN VALUE
On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.

ERRORS
Depending on the filesystem, other errors can be returned.  The more general errors for chown() are listed below.
EACCES Search permission is denied on a component of the path prefix.  (See also path_resolution(7).)
EFAULT path points outside your accessible address space.
ELOOP  Too many symbolic links were encountered in resolving path.
ENAMETOOLONG
     path is too long.
ENOENT The file does not exist.
ENOMEM Insufficient kernel memory was available.
ENOTDIR
     A component of the path prefix is not a directory.
EPERM  The calling process did not have the required permissions (see above) to change owner and/or group.
EROFS  The named file resides on a read-only filesystem.

The general errors for fchown() are listed below:
EBADF  The descriptor is not valid.
EIO    A low-level I/O error occurred while modifying the inode.

NOTES
The original Linux chown(), fchown(), and lchown() system calls supported only 16-bit user and group IDs.  Subsequently, Linux 2.4 added chown32(), fchown32(), and lchown32(), supporting 32-bit IDs.  The glibc chown(), fchown(), and lchown() wrapper functions transparently deal with the variations across kernel versions.

SEE ALSO
chmod(2), fchownat(2), flock(2), path_resolution(7), symlink(7)

*/
