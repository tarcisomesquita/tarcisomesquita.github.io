
// Do the file control operation described by CMD on FD.
// The remaining arguments are interpreted depending on CMD.

// #include<fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int fcntl (int __fd, int __cmd, ...);

Para evitar que as funcoes recv() e accept() bloqueiem a entrada se nao houver dados:
sockfd = socket(PF_INET, SOCK_STREAM, 0);
fcntl(sockfd, F_SETFL, O_NONBLOCK);

If you try to read from a non-blocking socket and there's no data there, it's not allowed to block—it will return -1 and errno will be set to EWOULDBLOCK.

O_ASYNC Set the socket to do asynchronous I/O. When data is ready to be recv()'d on the socket, the signal SIGIO will be raised. This is rare to see, and beyond the scope of the guide. And I think it's only available on certain systems. 
