// gcc crc.c -o crc; echo -n IEND | ./crc

#include <stdio.h>
#include <unistd.h>

// Table of CRCs of all 8-bit messages.
unsigned long crc_table[256];

// Flag: has the table been computed? Initially false.
int crc_table_computed = 0;

// Make the table for a fast CRC.
void make_crc_table(void) {
     unsigned long c;
     int n, k;
   
     for (n = 0; n < 256; n++) {
       c = (unsigned long) n;
       for (k = 0; k < 8; k++) {
         if (c & 1)
           c = 0xedb88320L ^ (c >> 1);
         else
           c = c >> 1;
       }
       crc_table[n] = c;
     }
     crc_table_computed = 1;
   }
  

/* Update a running CRC with the bytes buf[0..len-1]--the CRC
      should be initialized to all 1's, and the transmitted value
      is the 1's complement of the final running CRC (see the
      crc() routine below). */
   
   unsigned long update_crc(unsigned long crc, unsigned char *buf,
                            int len)
   {
     unsigned long c = crc;
     int n;
   
     if (!crc_table_computed)
       make_crc_table();
     for (n = 0; n < len; n++) {
       c = crc_table[(c ^ buf[n]) & 0xff] ^ (c >> 8);
     }
     return c;
   }
   
// Return the CRC of the bytes buf[0..len-1].
unsigned long crc(unsigned char *buf, int len) {
  return update_crc(0xffffffffL, buf, len) ^ 0xffffffffL;
}

#define BUFFER_SIZE 4194304
// 4194304 = 4 MiB é suficiente para uma captura de tela 1366*768

int main() {
  unsigned char buf[BUFFER_SIZE];
  ssize_t byte = 0;
  unsigned int r, i, n = 0;
  
  for (;;) {
    byte = getchar();
    if (byte != -1) {
      buf[n] = byte;
      n++;
      if (n == BUFFER_SIZE) return 1;
    }
    else break;
  }
  
  r = (unsigned int)crc(buf, n);
  printf("\\\\x%02X\\\\x%02X\\\\x%02X\\\\x%02X\n", (r&0xFF000000)>>24, (r&0x00FF0000)>>16, (r&0x0000FF00)>>8, (r&0x000000FF));
  return 0;
}
