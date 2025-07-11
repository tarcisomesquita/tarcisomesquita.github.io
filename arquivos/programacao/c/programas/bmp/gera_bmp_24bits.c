
// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
FILE *fopen(char *nome_do_arquivo, char *modo_de_abertura);
extern int fprintf(FILE *stream, const char *formatted_output, ...);
extern int fclose(FILE *ponteiro_para_o_arquivo);

//#include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int sprintf (char *__restrict __s, const char *__restrict __format, ...);


//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *malloc(unsigned long int __size);
extern void free (void *__ptr);

void bmp_24bits(char *bmpfilename, \
                unsigned long int width_Horizontal, \
                unsigned long int width_Vertical, \
                char *buffer
               )
{
   FILE *fp;
   unsigned long int filesize, \
                     bitmap_offset = 0x00000036, \
                     BitMapInfoHeader_length = 0x00000028, \
                     Compression = 0x00000000, \
                     picture_Size, \
                     resolution_Horizontal = 0x00000000, \
                     resolution_Vertical = 0x00000000, \
                     colors_used = 0x00000000, \
                     colors_important = 0x00000000, \
                     origem, i, j, z;
   
   unsigned short int planes_Number = 0x0001, \
                      Bits_per_pixel = 0x0018 ;
   
   unsigned char *pointer;
   char name[50];
   
   picture_Size = (width_Horizontal*3 + width_Horizontal%4) * width_Vertical;
   filesize = 0x0E + BitMapInfoHeader_length + picture_Size;

   sprintf(name,"%s.bmp",bmpfilename);
   if((fp = fopen(name,"wb")) == '\0')
   {
      fprintf(stdout, "Não posso abrir o Arquivo file_bmp.bmp.\n");
      return;
   }
   
   fprintf(fp, "BM");
   pointer = (unsigned char *)&filesize;
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   fprintf(fp, "%c%c%c%c", 0x00, 0x00, 0x00, 0x00);
   pointer = (unsigned char *)&bitmap_offset;
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   pointer = (unsigned char *)&BitMapInfoHeader_length;  // é fixo para windows.
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   pointer = (unsigned char *)&width_Horizontal;
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   pointer = (unsigned char *)&width_Vertical;
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   pointer = (unsigned char *)&planes_Number;
   fprintf(fp, "%c%c", pointer[0], pointer[1]);
   pointer = (unsigned char *)&Bits_per_pixel;
   fprintf(fp, "%c%c", pointer[0], pointer[1]);
   pointer = (unsigned char *)&Compression;
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   pointer = (unsigned char *)&picture_Size;
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   pointer = (unsigned char *)&resolution_Horizontal;
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   pointer = (unsigned char *)&resolution_Vertical;
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   pointer = (unsigned char *)&colors_used;
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   pointer = (unsigned char *)&colors_important;
   fprintf(fp, "%c%c%c%c", pointer[0], pointer[1], pointer[2], pointer[3]);
   
   for(j = width_Vertical ; j > 0; j--)
   {
      origem = (unsigned long int)buffer + width_Horizontal * 3 * (j - 1);
      
      for(i = 0 ; i < width_Horizontal * 3 - 1; i = i + 3)
      {
         pointer = (unsigned char *)(origem + i);
         fprintf(fp, "%c%c%c", pointer[0], pointer[1], pointer[2]);
      }
      
      if((width_Horizontal * 3)%4)
      {
         for(z = 0; z < (width_Horizontal%4); z++)
         {
            fprintf(fp, "%c", 0x00);
         }
      }
   }
   
   fclose(fp);
}

int main() {
   char bmpfilename[] = "teste";
   unsigned long int width_Horizontal, width_Vertical;
   
   width_Horizontal = 100;
   width_Vertical   = 100;

//   buffer = (char *)main;
   char *buffer;
   buffer = malloc(width_Horizontal * 3 * width_Vertical);

/*
   char buffer[] = { 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, \
                     0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, \
                     0x00, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0x00, \
                     0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, \
                     0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, \
            };

*/
   bmp_24bits(bmpfilename, width_Horizontal, width_Vertical, (char *)buffer);
   return(0);
}

