
/*
clear ; \
/usr/lib/gcc/i486-linux-gnu/4.3.3/cc1 -quiet -Wall -masm=intel -mtune=prescott -march=prescott --param l1-cache-size=16 --param l2-cache-size=2048 \
-o read_hex_byte.s read_hex_byte.c  && \
\
/usr/bin/as  -o read_hex_byte.o read_hex_byte.s && \
\
/usr/bin/ld \
-m elf_i386 \
-static \
-o read_hex_byte.elf \
-z relro \
/usr/lib/crt1.o \
/usr/lib/crti.o \
/usr/lib/gcc/i486-linux-gnu/4.3.3/crtbeginT.o \
-L/usr/lib/gcc/i486-linux-gnu/4.3.3 \
-L/usr/lib/ \
./read_hex_byte.o \
\
--start-group \
-lgcc \
-lgcc_eh \
-lc \
--end-group \
\
/usr/lib/gcc/i486-linux-gnu/4.3.3/crtend.o \
/usr/lib/crtn.o && \
\
./read_hex_byte.elf
*/

extern int printf(char *, ...);

// input: sbyte, contendo as duas letras do byte
// output: byte, contendo o byte
// return 1 para erro, 0 para ok
int _read_hex_byte(unsigned char *sbyte, unsigned char *byte) {
   unsigned char i;
   
   for (i=0; i<2; i++) {
      if      (sbyte[i] >= 0x30 && sbyte[i] <= 0x39 ) continue; // 0-9
      else if (sbyte[i] >= 0x41 && sbyte[i] <= 0x46 ) continue; // A-F
      else if (sbyte[i] >= 0x61 && sbyte[i] <= 0x66 ) continue; // a-f
      else {
         printf("\nERRO: Encontrei uma letra que não pertence ao alfabeto hexadecimal.\n\n");
         return 1;
      }
   }
   
   byte[0] = 0x00;
   
   for (i=0; i<2; i++) {
      switch(sbyte[i]) {
         case '0': byte[0] = byte[0] + (0<<((1-i)*4)); break;
         case '1': byte[0] = byte[0] + (1<<((1-i)*4)); break;
         case '2': byte[0] = byte[0] + (2<<((1-i)*4)); break;
         case '3': byte[0] = byte[0] + (3<<((1-i)*4)); break;
         case '4': byte[0] = byte[0] + (4<<((1-i)*4)); break;
         case '5': byte[0] = byte[0] + (5<<((1-i)*4)); break;
         case '6': byte[0] = byte[0] + (6<<((1-i)*4)); break;
         case '7': byte[0] = byte[0] + (7<<((1-i)*4)); break;
         case '8': byte[0] = byte[0] + (8<<((1-i)*4)); break;
         case '9': byte[0] = byte[0] + (9<<((1-i)*4)); break;
         case 'A': byte[0] = byte[0] + (10<<((1-i)*4)); break;
         case 'B': byte[0] = byte[0] + (11<<((1-i)*4)); break;
         case 'C': byte[0] = byte[0] + (12<<((1-i)*4)); break;
         case 'D': byte[0] = byte[0] + (13<<((1-i)*4)); break;
         case 'E': byte[0] = byte[0] + (14<<((1-i)*4)); break;
         case 'F': byte[0] = byte[0] + (15<<((1-i)*4)); break;
         case 'a': byte[0] = byte[0] + (10<<((1-i)*4)); break;
         case 'b': byte[0] = byte[0] + (11<<((1-i)*4)); break;
         case 'c': byte[0] = byte[0] + (12<<((1-i)*4)); break;
         case 'd': byte[0] = byte[0] + (13<<((1-i)*4)); break;
         case 'e': byte[0] = byte[0] + (14<<((1-i)*4)); break;
         case 'f': byte[0] = byte[0] + (15<<((1-i)*4)); break;
      }
   }
   
   return 0;
}

unsigned long int read_hex_byte(unsigned char *teste) {
   unsigned char sbyte[2], byte, i, *p;
   //unsigned char teste[] = "01020304";
   unsigned long int address;
   
   p = (unsigned char *)&address;
   for (i=0; i<3 ; i++) p++; // leva p para o final o último byte de address
   
   //printf("\n0x");
   for (i=0; i<4 ; i++) {
      sbyte[0] = teste[2*i]; sbyte[1] = teste[2*i+1];
      if (! _read_hex_byte(sbyte, &byte)) {
         //printf("%02X", byte);
         p[0] = byte;
         p--;
      }
      else return 0;
   }
   //printf("\n0x%08X\n\n", (unsigned int)address);
   
   return address;
}

