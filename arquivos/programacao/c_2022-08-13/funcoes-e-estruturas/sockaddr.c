// #include <bits/socket.h> // = = = = = = = = = = = = = = = = = = = = = = = = 
// Structure describing a generic socket address.
struct sockaddr {
   unsigned short int sa_family; // Address family and length.
   char sa_data[14];             // Address data.
};

