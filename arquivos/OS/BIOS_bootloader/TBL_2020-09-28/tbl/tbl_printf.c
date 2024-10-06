// definida em asm.S
extern void stop(void);

unsigned int x = 14;
unsigned int y = 0;
int tbl_puts(char *);

void tbl_putc(unsigned char c) {
   char *vidmem;
   int pos;
   
   vidmem = (char *)0xB8000;    // pointer to video memory
   pos = ( y * 160 ) + x;        // Get the position
   
   if (c == 0x0A) {
      y = y + 1;
      x = 0;
   }
   else {
      vidmem[pos] = c;          // print the character
      pos++;
      vidmem[pos] = 0x07;       // Set the color gray text on a black background
      
      x = x + 2;                // 2 bytes per char
      if (x >= 160) { y++; x = 0; }
   }
}


int tbl_puts(char *message) {
   int length = 0;
   
   while(*message) {
      tbl_putc(*message);
      message++;
      length++;
   }
   return length;
}


void convert_to_ascii (char *buf, int c, unsigned int num) {
   unsigned int mult;
   char *ptr;
   char *ptr1, *ptr2;
   
   ptr = buf;
   mult = 10;
   
   if (c == 'x' || c == 'X') mult = 16;
   
   if ((num & 0x80000000uL) && c == 'd') {
      num = (~num) + 1;
      ptr[0] = '-';
      ptr++;
      buf++;
   }
   
   do {
      int dig;
      dig = num % mult;
      ptr[0] = ((dig > 9) ? dig + 'a' - 10 : '0' + dig);
      ptr++;
      num = num / mult;
   } while (num);
   
   if (c == 'x' || c == 'X') while( (ptr - buf) < 8) { ptr[0] = '0' ; ptr++; }
   
   // reorder to correct direction!!
   ptr1 = ptr - 1;
   ptr2 = buf;
   while (ptr1 > ptr2) {
      unsigned char tmp;
      tmp = *ptr1;
      *ptr1 = *ptr2;
      *ptr2 = tmp;
      ptr1--;
      ptr2++;
   }
   
   ptr[0] = 0x00;
   
   return;
}

void tbl_printf(const char *format,...) {
   int *dataptr;
   char c, str[16];
   
   dataptr = (int *)&format;
   dataptr++;
   
   while ((c = *(format++)) != 0) {
      if (c != '%') tbl_putc(c);
      else {
         switch (c = *(format++)) {
            case 'x':
            case 'X':
            case 'd':
            case 'u':
               convert_to_ascii(str, c, *((unsigned int *)dataptr++));
               tbl_puts(str);
               break;
            
            case 'c':
               tbl_putc((*(dataptr++)) & 0xff);
               break;
            
            case 's':
               tbl_puts((char *)*(dataptr++));
               break;
            
            default:
               tbl_printf("tbl_printf nao reconhece o formato \"%c\"", c); stop();
         }
      }
   }
}

