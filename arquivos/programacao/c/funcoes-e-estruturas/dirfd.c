
// Return the file descriptor used by DIRP (directory stream dirstream).

// #include<dirent.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int dirfd (DIR *__dirp) __THROW __nonnull ((1));

// This descriptor can be used until the directory is closed with closedir.
// If the directory stream implementation is not using file descriptors the return value is -1.

// veja a função fdopendir


