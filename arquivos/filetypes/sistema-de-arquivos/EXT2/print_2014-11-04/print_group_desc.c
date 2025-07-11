
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
} **group_desc = 0x00000000;



void print_group_desc(unsigned int i) {
   unsigned int offset;
   
   offset = 0x400 + i * sizeof(struct ext2_group_desc);
   
   printf("\n; Group description\n\n");
   printf("bg_block_bitmap:            dd 0x%08X    ; 0x%08X Blocks bitmap block\n", group_desc[i]->bg_block_bitmap, offset);
   offset += 4;
   printf("bg_inode_bitmap:            dd 0x%08X    ; 0x%08X Inodes bitmap block\n", group_desc[i]->bg_inode_bitmap, offset);
   offset += 4;
   printf("bg_inode_table:             dd 0x%08X    ; 0x%08X Inodes table block\n", group_desc[i]->bg_inode_table, offset);
   offset += 4;
   printf("bg_free_blocks_count:       dw 0x%04X        ; 0x%08X Free blocks count\n", group_desc[i]->bg_free_blocks_count, offset);
   offset += 2;
   printf("bg_free_inodes_count:       dw 0x%04X        ; 0x%08X Free inodes count\n", group_desc[i]->bg_free_inodes_count, offset);
   offset += 2;
   printf("bg_used_dirs_count:         dw 0x%04X        ; 0x%08X Directories count\n", group_desc[i]->bg_used_dirs_count, offset);
   offset += 2;
   printf("bg_pad:                     dw 0x%04X        ; 0x%08X \n", group_desc[i]->bg_pad, offset);
   offset += 2;
   printf("bg_reserved:  times 3       dd 0x00000000    ; 0x%08X \n", offset);
   offset += 3*4;
   
   return;
}

