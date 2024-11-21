
/*
   If TURN_ON is TRUE, request for permission to do direct i/o on the port numbers in the range [FROM,FROM+NUM-1].
   Otherwise, turn I/O permission off for that range.
   This call requires root privileges.
   
   ioperm() can only give access to ports 0x000 through 0x3ff;
   for higher ports, you need to use iopl() (which gives you access to all ports at once).
*/

#include<sys/io.h>

extern int ioperm (unsigned long int __from, unsigned long int __num, int __turn_on);

exemplo:
#define LPT1 0x378
ioperm(LPT1,3,1);  // Libera acesso para os endereços: 0x378, 0x379, 0x37A

