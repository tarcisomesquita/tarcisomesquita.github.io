
// Convert Internet host address from numbers-and-dots notation in CP into binary data and store the result in the structure INP
// returns nonzero if the address is valid, zero if not.

// #include <sys/socket.h>
struct in_addr {
   unsigned long int s_addr; // Internet address
};

// #include <arpa/inet.h>
extern int inet_aton(const char *CP, struct in_addr *INP);

// #include <stdio.h>
extern int printf(const char *, ...);

int main(int argc, char *argv[]) {
   char numero[] = "192.168.0.100";  // C0.A8.00.64
   struct in_addr endereco;          // endereco.s_addr = 0x6400A8C0
   int resultado;
   
   resultado = inet_aton(numero, &endereco);
   printf("\nresultado = %d    endereco.s_addr = %08X\n\n", resultado, (unsigned int)endereco.s_addr);
   
   return 0;
}

