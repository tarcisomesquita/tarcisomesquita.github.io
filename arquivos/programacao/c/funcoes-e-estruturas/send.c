
// Send N bytes of BUF to socket FD.
// Returns the number sent or -1.

// #include <sys/socket.h>
extern int send (int __fd, __const void *__buf, size_t __n, int __flags);

flags
MSG_OOB
	

Send as "out of band" data. TCP supports this, and it's a way to tell the receiving system that this data has a higher priority than the normal data. The receiver will receive the signal SIGURG and it can then receive this data without first receiving all the rest of the normal data in the queue.

MSG_DONTROUTE
	

Don't send this data over a router, just keep it local.

MSG_DONTWAIT
	

If send() would block because outbound traffic is clogged, have it return EAGAIN. This is like a "enable non-blocking just for this send." See the section on blocking for more details.



MSG_NOSIGNAL If you send() to a remote host which is no longer recv()ing, you'll typically get the signal SIGPIPE. Adding this flag prevents that signal from being raised.

int spatula_count = 3490;
char *secret_message = "The Cheese is in The Toaster";

int stream_socket, dgram_socket;
struct sockaddr_in dest;
int temp;

// first with TCP stream sockets:

// assume sockets are made and connected
//stream_socket = socket(...
//connect(stream_socket, ...

// convert to network byte order
temp = htonl(spatula_count);
// send data normally:
send(stream_socket, &temp, sizeof temp, 0);

// send secret message out of band:
send(stream_socket, secret_message, strlen(secret_message)+1, MSG_OOB);

// now with UDP datagram sockets:
//getaddrinfo(...
//dest = ...  // assume "dest" holds the address of the destination
//dgram_socket = socket(...

// send secret message normally:
sendto(dgram_socket, secret_message, strlen(secret_message)+1, 0, 
       (struct sockaddr*)&dest, sizeof dest);
