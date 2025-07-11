
#include <sys/io.h>

/*
static __inline unsigned char inb (unsigned short int port)
{
   unsigned char _v;
   __asm__ __volatile__ ("inb %w1,%0":"=a" (_v):"Nd" (port));
   return _v;
}
*/

#define LPT1 0x378


   ioperm(LPT1,3,1);  // Libera acesso para os endereços: 0x378, 0x379, 0x37A

   int entrada = inb(0x379);

/* Read from the status port (BASE+1) and display the result */
  printf("status: %d\n", inb(BASEPORT + 1));

