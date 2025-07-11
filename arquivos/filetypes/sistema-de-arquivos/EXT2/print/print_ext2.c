// clear ; gcc -Wall print_ext2.c sair.S -o print_ext2.elf && ./print_ext2.elf test-20MiB.bin > print_teste.txt

// Structure of a blocks group descriptor
struct ext2_group_desc {
   unsigned int bg_block_bitmap;        // Blocks bitmap block
   unsigned int bg_inode_bitmap;        // Inodes bitmap block
   unsigned int bg_inode_table;         // Inodes table block
   unsigned short bg_free_blocks_count; // Free blocks count
   unsigned short bg_free_inodes_count; // Free inodes count
   unsigned short bg_used_dirs_count;   // Directories count
   unsigned short bg_pad;
   unsigned int bg_reserved[3];
} *group_desc = 0x00000000;

// Structure of a directory entry
struct ext2_dir_entry {
   unsigned int inode;      // Inode number
   unsigned short rec_len;  // Directory entry length
   unsigned short name_len; // Name length
   char name[255];          // File name
};

struct ext2_dir_entry_2 {
   unsigned int inode;      // Inode number
   unsigned short rec_len;  // Directory entry length
   unsigned char name_len;  // Name length
   unsigned char file_type;
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

#include "print_super_block.c"
#include "print_inode.c"

unsigned char *buffer = 0x00000000;

extern void sair();

void fechar() {
   if (inode) free(inode);
   if (buffer) free(buffer);
   if (group_desc) free(group_desc);
   if (super_block) free(super_block);
   
   sair();
   return;
}


int main(int argc, char **argv) {
   int fd;
   unsigned int n, n0, i, block_size;
   
   if (argc != 2) {
      printf("\nUso: %s file-ext2\n\n", argv[0]);
      return 1;
   }
   
   fd = open(argv[1], O_RDONLY);
   if (fd == -1) {
      printf("\nNão foi possível abrir o arquivo \"%s\"\n\n", argv[1]);
      return 1;
   }
   
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
      fechar();
   }
   
   print_super_block();
   
   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   // group description
   
   if (! (group_desc = malloc((unsigned long int)sizeof(struct ext2_group_desc)))) {
      printf("\nERRO não foi possível alocar %d bytes para o struct ext2_group_desc.\n\n", sizeof(struct ext2_group_desc));
      fechar();
   }
   
   for (i=0; i < (super_block->s_blocks_count/super_block->s_blocks_per_group + 1); i++) {
      n = read(fd, group_desc, (unsigned long int)sizeof(struct ext2_group_desc));
      if (n != (unsigned long int)sizeof(struct ext2_group_desc)) {
         printf("\nErro na leitura do ext2_group_desc.\n\n");
         fechar();
      }
      
      printf("\n; Group description\n\n");
      printf("bg_block_bitmap:            dd 0x%08X    ; 0x00000800 Blocks bitmap block\n", group_desc->bg_block_bitmap);
      printf("bg_inode_bitmap:            dd 0x%08X    ; 0x00000804 Inodes bitmap block\n", group_desc->bg_inode_bitmap);
      printf("bg_inode_table:             dd 0x%08X    ; 0x00000808 Inodes table block\n", group_desc->bg_inode_table);
      printf("bg_free_blocks_count:       dw 0x%04X        ; 0x0000080C Free blocks count\n", group_desc->bg_free_blocks_count);
      printf("bg_free_inodes_count:       dw 0x%04X        ; 0x0000080E Free inodes count\n", group_desc->bg_free_inodes_count);
      printf("bg_used_dirs_count:         dw 0x%04X        ; 0x00000810 Directories count\n", group_desc->bg_used_dirs_count);
      printf("bg_pad:                     dw 0x%04X        ; 0x00000812 \n", group_desc->bg_pad);
      printf("bg_reserved:  times 3       dd 0x00000000    ; 0x00000814 \n");
   }
   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   // block bitmap
   
   block_size = 1024 << super_block->s_log_block_size ;
   
   n = lseek(fd, group_desc->bg_block_bitmap * block_size, SEEK_SET); // posiciona no início do super bloco
   if (n != (group_desc->bg_block_bitmap * block_size)) {
      printf("\nERRO: lseek não posicionou em 0x%08X.\n\n", group_desc->bg_block_bitmap * block_size);
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
   
   printf("\n; block bitmap       offset 0x%08X\ndb ", group_desc->bg_block_bitmap * block_size);
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
   
   n = lseek(fd, group_desc->bg_inode_bitmap * block_size, SEEK_SET); // posiciona no início do super bloco
   if (n != (group_desc->bg_inode_bitmap * block_size)) {
      printf("\nERRO: lseek não posicionou em 0x%08X.\n\n", group_desc->bg_inode_bitmap * block_size);
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
   
   printf("\n; inode bitmap       offset 0x%08X\ndb ", group_desc->bg_inode_bitmap * block_size);
   
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
   // inode table
   
   printf("\n; inode table\n");
   n = lseek(fd, group_desc->bg_inode_table * block_size, SEEK_SET); // posiciona no início do super bloco
   if (n != group_desc->bg_inode_table * block_size) {
      printf("\nERRO: lseek não posicionou em 0x%08X.\n\n", group_desc->bg_inode_table * block_size);
      fechar();
   }
   
   if (! (inode = malloc((unsigned long int)sizeof(struct ext2_inode)))) {
      printf("\nERRO não foi possível alocar %d bytes para o struct inode.\n\n", sizeof(struct ext2_inode));
      fechar();
   }
   
   n = 0;
   n0 = group_desc->bg_inode_table * block_size;
   for (i=0; i<13; i++) {
      n0 = n0 + n;
      printf("\n; offset 0x%08X", n0);
      
      n = read(fd, inode, sizeof(struct ext2_inode));
      if (n != sizeof(struct ext2_inode)) {
         printf("\nErro na leitura do inode.\n\n");
         fechar();
      }
      
      print_inode() ;
   }
   
   fechar();
   return 0;
}

