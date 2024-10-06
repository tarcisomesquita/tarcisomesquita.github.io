// clear ; gcc -Wall print_ext2.c /usr/lib/libm.a -o print_ext2.elf && sudo ./print_ext2.elf /dev/loop1 > print_teste.txt

int fd;
unsigned int block_size = 0;
unsigned int blocks_count = 0;
unsigned int blocks_per_group = 0;
unsigned int inodes_per_group = 0;

// Structure of a directory entry
struct ext2_dir_entry {
   unsigned int inode;      // Inode number
   unsigned short rec_len;  // Directory entry length
   unsigned short name_len; // Name length
   char name[255];          // File name
};


// Ext2 directory file types.  Only the low 3 bits are used.  The other bits are reserved for now.
enum {
   EXT2_FT_UNKNOWN,
   EXT2_FT_REG_FILE,
   EXT2_FT_DIR,
   EXT2_FT_CHRDEV,
   EXT2_FT_BLKDEV,
   EXT2_FT_FIFO,
   EXT2_FT_SOCK,
   EXT2_FT_SYMLINK,
   EXT2_FT_MAX
};

extern int printf(char *, ...);
extern int open(const char *file, int oflag, ...);
extern int read(int __fd, void *__buf, unsigned long int __nbytes);
#define O_RDONLY           00
extern void *malloc(unsigned long int __size);
extern void free(void *__ptr);
extern unsigned int strlen(const char *str);
#define SEEK_SET 0 // Seek from beginning of file.
#define SEEK_CUR 1 // Seek from current position.
extern long int lseek(int fd, long int offset, int whence);
extern void sync(void);
extern double pow (double x, double y);


//#include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

// If BUF is NULL, make STREAM unbuffered.
// Else make it use buffer BUF, of size BUFSIZ.  */
extern void setbuf(FILE *stream, char *buf);


#include "print_super_block.c"
#include "print_group_desc.c"
#include "print_inode.c"
#include "print_dir_entry.c"

unsigned char *buffer = 0x00000000;


int main(int argc, char **argv) {
   unsigned long int n;
   
   if (argc != 2) {
      printf("\nUso: %s file-ext2\n\n", argv[0]);
      return 1;
   }
   
   fd = open(argv[1], O_RDONLY);
   if (fd == -1) {
      printf("\nNão foi possível abrir o arquivo \"%s\"\n\n", argv[1]);
      return 1;
   }
   
   setbuf(stdout, 0x00);

   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   // super bloco
   
   n = lseek(fd, 0x00000400, SEEK_SET); // posiciona no início do super bloco
   if (n != 0x00000400) {
      printf("\nERRO: lseek não posicionou em 0x00000400.\n\n");
      return 1;
   }
   
   if (! (super_block = malloc((unsigned long int)sizeof(struct ext2_super_block)))) {
      printf("\nERRO não foi possível alocar %d bytes para o struct ext2_super_block.\n\n", sizeof(struct ext2_super_block));
      return 1;
   }
   
   n = read(fd, super_block, (unsigned long int)sizeof(struct ext2_super_block));
   if (n != (unsigned long int)sizeof(struct ext2_super_block)) {
      printf("\nErro na leitura do ext2_super_block.\n\n");
      free(super_block);
      return 1;
   }
   
   if (super_block->s_rev_level != 1)      { printf("\nrev_level != 1\n\n");        free(super_block); return 1; }
   if (super_block->s_blocks_count == 0)   { printf("\nblocks_count == 0\n\n");     free(super_block); return 1; }
   if (super_block->s_blocks_per_group == 0) { printf("\nblocks_per_group == 0\n\n"); free(super_block); return 1; }
   if (super_block->s_inodes_per_group == 0) { printf("\ninodes_per_group == 0\n\n"); free(super_block); return 1; }
   
   block_size = 1024 << super_block->s_log_block_size;
   blocks_count = super_block->s_blocks_count;
   blocks_per_group = super_block->s_blocks_per_group;
   inodes_per_group = super_block->s_inodes_per_group;
   
   free(super_block); 
   //s_inode_size
   printf("\n");
   printf("Um bloco tem %u bytes.\n", block_size);
   printf("Por grupo há %u blocos e %u inodes.\n", blocks_per_group, inodes_per_group);
   printf("O sistema tem %u grupos.\n", blocks_count/blocks_per_group);
   printf("\n");
   
//   if (print_super_block((unsigned long int)0)) return 1; printf("\n");
//   if (print_group_desc(0, 0)) return 1; printf("\n");
   if (print_inode((unsigned int)0x2)) return 1; printf("\n");
//   if (print_dir_entry((unsigned int)0x5201)) return 1; printf("\n");
   
   /*
   
   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   // block bitmap
   
   n = lseek(fd, group_desc[0]->bg_block_bitmap * block_size, SEEK_SET); // posiciona no início do super bloco
   if (n != (group_desc[0]->bg_block_bitmap * block_size)) {
      printf("\nERRO: lseek não posicionou em 0x%08X.\n\n", group_desc[0]->bg_block_bitmap * block_size);
      fechar();
   }
   
   if (! (buffer = malloc(block_size))) {
      printf("\nERRO não foi possível alocar %d bytes para o cache.\n\n", block_size);
      fechar();
   }
   
   n = read(fd, buffer, block_size);
   if (n != block_size) {
      printf("\nErro na leitura do block bitmap.\n\n");
      fechar();
   }
   
   printf("\n; block bitmap       offset 0x%08X\ndb ", group_desc[0]->bg_block_bitmap * block_size);
   for (i=0 ; i < block_size ; i++) {
      printf("0x%02X", buffer[i]);
      if ((i+1)%16) printf(", ");
      else  {
         if ((i+1) < block_size) printf("\ndb ");
         else printf("\n\n");
      }
   }
   free(buffer); buffer = 0x00000000;
   
   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   // inode bitmap
   
   n = lseek(fd, group_desc[0]->bg_inode_bitmap * block_size, SEEK_SET); // posiciona no início do super bloco
   if (n != (group_desc[0]->bg_inode_bitmap * block_size)) {
      printf("\nERRO: lseek não posicionou em 0x%08X.\n\n", group_desc[0]->bg_inode_bitmap * block_size);
      fechar();
   }
   
   if (! (buffer = malloc(block_size))) {
      printf("\nERRO não foi possível alocar %d bytes para o cache.\n\n", block_size);
      fechar();
   }
   
   n = read(fd, buffer, block_size);
   if (n != block_size) {
      printf("\nErro na leitura do inode bitmap.\n\n");
      fechar();
   }
   
   printf("\n; inode bitmap       offset 0x%08X\ndb ", group_desc[0]->bg_inode_bitmap * block_size);
   
   for (i=0 ; i < block_size ; i++) {
      printf("0x%02X", buffer[i]);
      if ((i+1)%16) printf(", ");
      else  {
         if ((i+1) < block_size) printf("\ndb ");
         else printf("\n\n");
      }
   }
   free(buffer); buffer = 0x00000000;
   */
   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   // inode table
   
   /*
   if (inode->i_mode & 0x4000 && inode->i_size != 0) {
      n = lseek(fd, inode->i_block[0] * 1024, SEEK_SET); // posiciona no início do super bloco
      if (n != inode->i_block[0] * 1024) {
         printf("\nERRO: lseek não posicionou em 0x%08X.\n\n", inode->i_block[0] * 1024);
         fechar();
      }
      
      if (! (dir_entry = malloc((unsigned long int)sizeof(struct ext2_dir_entry_2)))) {
         printf("\nERRO não foi possível alocar %d bytes para o struct dir_entry.\n\n", sizeof(struct ext2_dir_entry_2));
         fechar();
      }
      
      n = read(fd, dir_entry, sizeof(struct ext2_dir_entry_2));
      if (n != sizeof(struct ext2_dir_entry_2)) {
         printf("\nErro na leitura do dir_entry.\n\n");
         fechar();
      }
      
      //print_inode() ;
      
      
   }
   */
   return 0;
}

