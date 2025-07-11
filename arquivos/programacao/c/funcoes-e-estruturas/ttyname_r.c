
// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

int ttyname_r (int filedes, char *buf, size_t len)

    The ttyname_r function is similar to the ttyname function except that it places its result into the user-specified buffer starting at buf with length len.

    The normal return value from ttyname_r is 0. Otherwise an error number is returned to indicate the error. The following errno error conditions are defined for this function:

    EBADF
        The filedes argument is not a valid file descriptor.
    ENOTTY
        The filedes is not associated with a terminal.
    ERANGE
        The buffer length len is too small to store the string to be returned. 
