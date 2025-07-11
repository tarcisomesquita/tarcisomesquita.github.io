void hexdump_string(unsigned long int file_offset, unsigned char *cache, int num) {
   int n, i, inicio2, fim2;
   
   if (num == 0) return;
   
   inicio2 = file_offset % 16;
   fim2 = 16 - (file_offset + num) % 16;
   
   // Se não começar no início da linha
   if (inicio2 > 0) {
      printf("%08X  ", (unsigned int)(file_offset - file_offset % 16));
      
      for(n=0; n < inicio2; n++) {
         if(n == 8) printf(" ");
         printf("   ");
      }
      
      for(n=0; ((n + inicio2) %16) != 0 && n < num; n++) {
         if(((n + inicio2)%16) == 8) printf(" ");
         printf("%02X ", cache[n]);
      }
      
      if ((inicio2 + num) < 16 ) {
         for(n=fim2; n > 0 ; n--) {
            if((n%8) == 0) printf(" ");
            printf("   ");
         }
      }
      
      printf(" |");
      for(n=0; n < inicio2; n++) printf(" ");
      for(n=0; ((n + inicio2) % 16) != 0 && n < num; n++) {
         if(cache[n] < 0x20 || cache[n] > 0x7E) printf("%c", 0x2E);
         else printf("%c", cache[n]);
      }
      
      if ((inicio2 + num) < 16) {
         for(n=0; n < fim2 ; n++) printf(" ");
         printf("|\n");
         return;
      }
      printf("|\n");
   }
   
   
   file_offset = file_offset + (16 - inicio2);
   num = num - (16 - inicio2);
   i = (16 - inicio2);
   for (;;) {
      printf("%08X  ", (unsigned int)file_offset);
      
      for(n=0; n < 16 && n < num; n++) {
         if( (n % 16) == 8) printf(" ");
         printf("%02X ", cache[i + n]);
      }
      
      if (num < 16 ) {
         for(n=fim2; n > 0 ; n--) {
            if((n%8) == 0) printf(" ");
            printf("   ");
         }
      }
      
      printf(" |");
      for(n=0; n < 16 && n < num; n++) {
         if(cache[i + n] < 0x20 || cache[i + n] > 0x7E) printf("%c", 0x2E);
         else printf("%c", cache[i+ n]);
      }
      
      if (num < 16) {
         for(n=0; n < fim2 ; n++) printf(" ");
         printf("|\n");
         return;
      }
      printf("|\n");
      
      i = i + 16;
      num = num - 16;
      file_offset = file_offset + 16;
   }
   
   return;
}

