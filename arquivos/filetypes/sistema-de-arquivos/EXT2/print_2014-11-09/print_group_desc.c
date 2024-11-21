
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



int print_group_desc(unsigned int i, unsigned int grupo) {
   unsigned int offset, n;
   
   if ( grupo >= (blocks_count / blocks_per_group)) { printf("\nERRO: O sistema não tem o grupo %u.\n\n", grupo); return 1; }
   if ( grupo != 0 && grupo != 1) {
      for (i = 1; ; i++) {
         if (grupo == pow(3, i)) break;
         if (grupo == pow(5, i)) break;
         if (grupo == pow(7, i)) break;
         if ((unsigned long int)pow(3, i) >= grupo) { printf("\nERRO: O grupo %u não tem backup do super bloco.\n\n", grupo); return 1; }
      }
   }
   
   offset = 1024 + block_size + grupo * blocks_per_group * block_size + i * sizeof(struct ext2_group_desc);
   n = lseek(fd, offset, SEEK_SET); // posiciona no início do super bloco
   if (n != offset) { printf("\nERRO: lseek.\n\n"); return 1; }
   
   group_desc = malloc((unsigned long int)sizeof(struct ext2_group_desc));
   if (! group_desc)  { printf("\nERRO: malloc.\n\n"); return 1; }
   
   n = read(fd, group_desc, (unsigned long int)sizeof(struct ext2_group_desc));
   if (n != (unsigned long int)sizeof(struct ext2_group_desc)) { printf("\nERRO: read.\n\n"); free(group_desc); return 1; }
   
   printf("\n");
   printf("Group description do grupo %u no grupo %u\n", i, grupo);
   printf("\n");
   printf("bg_block_bitmap:            dd 0x%08X    ; 0x%08X Blocks bitmap block\n", group_desc->bg_block_bitmap, offset);
   offset += 4;
   printf("bg_inode_bitmap:            dd 0x%08X    ; 0x%08X Inodes bitmap block\n", group_desc->bg_inode_bitmap, offset);
   offset += 4;
   printf("bg_inode_table:             dd 0x%08X    ; 0x%08X Inodes table block\n", group_desc->bg_inode_table, offset);
   offset += 4;
   printf("bg_free_blocks_count:       dw 0x%04X        ; 0x%08X Free blocks count\n", group_desc->bg_free_blocks_count, offset);
   offset += 2;
   printf("bg_free_inodes_count:       dw 0x%04X        ; 0x%08X Free inodes count\n", group_desc->bg_free_inodes_count, offset);
   offset += 2;
   printf("bg_used_dirs_count:         dw 0x%04X        ; 0x%08X Directories count\n", group_desc->bg_used_dirs_count, offset);
   offset += 2;
   printf("bg_pad:                     dw 0x%04X        ; 0x%08X \n", group_desc->bg_pad, offset);
   offset += 2;
   printf("bg_reserved:  times 3       dd 0x00000000    ; 0x%08X \n", offset);
   offset += 3*4;
   free(group_desc);
   return 0;
}

