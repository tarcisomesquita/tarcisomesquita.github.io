
#include <sys/io.h>
/*
static __inline void outb(unsigned char value, unsigned short int port)
{
   __asm__ __volatile__ ("outb %b0,%w1": :"a" (value), "Nd" (port));
}
*/

#define LPT1 0x378


   ioperm(LPT1,3,1);  // Libera acesso para os endereços: 0x378, 0x379, 0x37A

   outb(0x00, 0x378); // Desliga todos os pinos do Registro de Dados do DB2

