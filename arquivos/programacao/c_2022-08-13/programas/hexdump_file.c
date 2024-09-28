
// clear ; gcc -Wall find_header.c -o find_header.elf && ./find_header.elf ; echo $?

#include<stdio.h>
#include<stdlib.h>

// cache  => tem o endereço de onde está a string
// inicio => offset da string de onde começar a imprimir
// num    => número de bytes a imprimir
void hexdump_string(FILE *saida, unsigned char *cache, int inicio, int num)
{
   int i, n, inicio2, fim2;
   inicio2 = inicio%16;
   fim2 = (inicio+num)%16;
   
   if(inicio2 > 0)
   {
      fprintf(saida,"%08X  ", (unsigned int)(inicio-inicio2));
      for(n=0; n<inicio2; n++)
      {
         if(n == 8)
            fprintf(saida," ");
         fprintf(saida,"   ");
      }
      
      for(n=inicio; (n%16) != 0 && n < (inicio+num); n++)
      {
         if((n%16) == 8)
            fprintf(saida," ");
         fprintf(saida,"%02X ", cache[n]);
      }
      
      if((inicio2 + num) >= 16)
      {
         fprintf(saida," |");
         for(n=0; n<inicio2; n++)
         {
            fprintf(saida," ");
         }
         
         for(n=inicio; (n%16) != 0 && n < (inicio+num); n++)
         {
            if(cache[n] < 0x20 || cache[n] > 0x7E)
               fprintf(saida,"%c", 0x2E);
            else
               fprintf(saida,"%c", cache[n]);
         }
         
         fprintf(saida,"|\n");
      }
      else
      {
         for(n=(inicio+num); (n%16) !=0 ; n++)
         {
            if((n%8) == 0)
               fprintf(saida," ");
            fprintf(saida,"   ");
         }
         
         fprintf(saida," |");
         
         for(n=0; n<inicio2; n++)
         {
            fprintf(saida," ");
         }
         
         for(n=inicio; (n%16) != 0 && n < (inicio+num); n++)
         {
            if(cache[n] < 0x20 || cache[n] > 0x7E)
               fprintf(saida,"%c", 0x2E);
            else
               fprintf(saida,"%c", cache[n]);
         }
         
         for(n=(inicio+num); (n%16) !=0 ; n++)
         {
            fprintf(saida," ");
         }
         
         fprintf(saida,"|\n");
         
         return;
      }
      
      num = num - (16 - (inicio%16));
      inicio = inicio + 16 - (inicio%16);
   }
   
   // fprintf(saida, "\nnum = 0x%02X\n", num);
   // fprintf(saida, "inicio = 0x%02X\n", inicio);
   if(num >= 16)
   {
      for(i=inicio; (i+((inicio+num)%16))<(inicio+num); i=i+16)
      {
         fprintf(saida,"%08X  ", (unsigned int)i);
         for(n=i; n<(i+16); n++)
         {
            if(n == i+8)
               fprintf(saida," ");
            fprintf(saida,"%02X ", cache[n]);
         }
         fprintf(saida," |");
         for(n=i; n<(i+16); n++)
            if(cache[n] < 0x20 || cache[n] > 0x7E)
               fprintf(saida,"%c", 0x2E);
            else
               fprintf(saida,"%c", cache[n]);
         fprintf(saida,"|\n");
      }
      num = num - (i - inicio);
      inicio = i;
   }
   
   // fprintf(saida, "\nnum = 0x%02X\n", num);
   // fprintf(saida, "inicio = 0x%02X\n", inicio);
   if(num < 16)
   {
      fprintf(saida,"%08X  ", (unsigned int)inicio);
      for(n=inicio ; n < (inicio + num) ; n++)
      {
         if( n%16 == 8)
            fprintf(saida," ");
         fprintf(saida,"%02X ", cache[n]);
      }
      
      for(n=(inicio+num); (n%16) !=0 ; n++)
      {
         if((n%8) == 0)
            fprintf(saida," ");
         fprintf(saida,"   ");
      }
      
      fprintf(saida," |");
      
      for(n=inicio ; n < (inicio + num) ; n++)
      {
         if(cache[n] < 0x20 || cache[n] > 0x7E)
            fprintf(saida,"%c", 0x2E);
         else
            fprintf(saida,"%c", cache[n]);
      }
      
      for(n=(inicio+num); (n%16) !=0 ; n++)
      {
         fprintf(saida," ");
      }
      
      fprintf(saida,"|\n");
   }   
   return;
}

int main(int argc, char **argv)
{
   int filesize, n;
   unsigned char *cache;
   FILE *fd;
   
   if(argc != 2)
   {
      fprintf(stderr, "\nSintaxe:\n./find_header.elf file.bin\n\n");
      return 1;
   }
   
   fd = fopen(argv[1],"rb");
   if(fd <= 0x00)
   {
      fprintf(stderr, "\nERRO na abertura do arquivo \'%s\'\n\n", argv[1]);
      return 1;
   }
   
   for(filesize=0 ; fgetc(fd) != -1; filesize++);
   fprintf(stdout, "\nO arquivo \'%s\' tem %d bytes\n\n", argv[1], filesize);
   if(filesize == 0)
   {
      return 0;
   }
   rewind(fd);
   
   cache = malloc((long unsigned int)filesize);
   n = fread(cache, 1, filesize, fd);
   if(n != filesize)
   {
      fprintf(stderr, "\nERRO: fread leu menos bytes que o tamanho do arquivo.\nn = %d\n\n", n);
      return 1;
   }
   
   hexdump_string(stderr, cache, 0, filesize);
   
   
   
   
   return 0;
}

