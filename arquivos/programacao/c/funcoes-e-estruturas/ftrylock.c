Streams can be used in multi-threaded applications in the same way they are used in single-threaded applications.

— Function: void flockfile (FILE *stream)

    The flockfile function acquires the internal locking object associated with the stream stream. This ensures that no other thread can explicitly through flockfile/ftrylockfile or implicit through a call of a stream function lock the stream. The thread will block until the lock is acquired. An explicit call to funlockfile has to be used to release the lock. 

— Function: int ftrylockfile (FILE *stream)

    The ftrylockfile function tries to acquire the internal locking object associated with the stream stream just like flockfile. But unlike flockfile this function does not block if the lock is not available. ftrylockfile returns zero if the lock was successfully acquired. Otherwise the stream is locked by another thread. 

— Function: void funlockfile (FILE *stream)

    The funlockfile function releases the internal locking object of the stream stream. The stream must have been locked before by a call to flockfile or a successful call of ftrylockfile. The implicit locking performed by the stream operations do not count. The funlockfile function does not return an error status and the behavior of a call for a stream which is not locked by the current thread is undefined. 


