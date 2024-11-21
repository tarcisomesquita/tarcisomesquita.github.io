
// Shut down all or part of the connection open on socket FD. Not close the file descriptor.
// Returns 0 on success, -1 for errors.

// #include <sys/socket.h> // = = = = = = = = = = = = = = = = = = = = = =
extern int shutdown(int FD, int HOW);

// HOW
enum {
   SHUT_RD   = 0,  // No more receptions. If further data arrives, reject it.
   SHUT_WR   = 1,  // No more transmissions. Discard any data waiting to be sent. Stop looking for acknowledgement of data already sent.
   SHUT_RDWR = 2   // No more receptions or transmissions. Equal close()
};

   shutdown(sock, 2);
   close(sock);

