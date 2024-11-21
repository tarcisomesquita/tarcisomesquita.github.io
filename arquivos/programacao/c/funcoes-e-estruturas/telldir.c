
 Function: long int telldir (DIR *dirstream)

    The telldir function returns the file position of the directory stream dirstream. You can use this value with seekdir to restore the directory stream to that position. 

— Function: void seekdir (DIR *dirstream, long int pos)

    The seekdir function sets the file position of the directory stream dirstream to pos. The value pos must be the result of a previous call to telldir on this particular stream; closing and reopening the directory can invalidate values returned by telldir. 

