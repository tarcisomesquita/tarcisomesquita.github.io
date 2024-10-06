
// #include <sys/socket.h> // = = = = = = = = = = = = = = = = = = = = = =
// Prepare to accept connections on socket FD. To accept each incoming connection use function accept
// N connection requests will be queued before further requests are refused.
// Returns 0 on success, -1 for errors.
extern int listen(int fd, int n);


