
/*
Escreve bytes em um arquivo na posição onde aponta o ponteiro.
A função retorna o número de itens realmente gravados e avança o ponteiro de arquivo tamanho*num bytes.

buffer : Ponteiro para uma área de memória, geralmente uma estrutura ou um vetor, onde estão armazenados os dados a serem gravados no arquivo.
tamanho: Numero de bytes a gravar. Geralmente sizeof(buffer).
num : Numero de itens a gravar. Geralmente 1.
arquivo: Ponteiro FILE para um arquivo aberto anteriormente por fopen().
*/

// #include<stdio.h>  // = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;

struct _IO_marker
{
   struct _IO_marker *_next;
   struct _IO_FILE *_sbuf;
   int _pos;
};

struct _IO_FILE
{
   int _flags;		// High-order word is _IO_MAGIC; rest is flags.
   
   // The following pointers correspond to the C++ streambuf protocol.
   // Note:  Tk uses the _IO_read_ptr and _IO_read_end fields directly.
   char* _IO_read_ptr;	// Current read pointer 
   char* _IO_read_end;	// End of get area. 
   char* _IO_read_base;	// Start of putback+get area.
   char* _IO_write_base;	// Start of put area.
   char* _IO_write_ptr;	// Current put pointer.
   char* _IO_write_end;	// End of put area. 
   char* _IO_buf_base;	// Start of reserve area.
   char* _IO_buf_end;	// End of reserve area.
   // The following fields are used to support backing up and undo.
   char *_IO_save_base; // Pointer to start of non-current get area.
   char *_IO_backup_base;  // Pointer to first valid character of backup area
   char *_IO_save_end; // Pointer to end of non-current get area.
   
   struct _IO_marker *_markers;
   
   struct _IO_FILE *_chain;
   
   int _fileno;
   
   int _flags2;
   
   long int _old_offset; // This used to be _offset but it's too small.
   
   unsigned short _cur_column;
   signed char _vtable_offset;
   char _shortbuf[1];
   
   void *_lock;
   long long int _offset;
   void *__pad1;
   void *__pad2;
   void *__pad3;
   void *__pad4;
   long unsigned int  __pad5;
   int _mode;
   char _unused2[15 * sizeof(int) - 4 * sizeof(void *) - sizeof(long unsigned int )];
};


typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
FILE *fopen(char *nome_do_arquivo, char *modo_de_abertura);
extern int fclose(FILE *ponteiro_para_o_arquivo);
extern long unsigned int fwrite (const void *buffer, long unsigned int size, long unsigned int n, FILE *arquivo);
extern int fprintf(FILE *saida, const char *string_com_formatos, ...);


int main()
{
   FILE *fp;
   unsigned char string[2]= {'s','a'};

   if ((fp=fopen("teste.txt","w")) == '\0')
   {
      fprintf(stdout,"\nArquivo não pode ser criado.\n\n");
      return(1);
   }
   
   fprintf(stdout, "\n%d\n\n", fp->_IO_write_base);
   fp->_IO_write_base += 10;
   fprintf(stdout, "\n%d\n\n", fp->_IO_write_base);

   fwrite(&string,sizeof(string),1,fp);
   fclose(fp);
   
   return(0);
}

