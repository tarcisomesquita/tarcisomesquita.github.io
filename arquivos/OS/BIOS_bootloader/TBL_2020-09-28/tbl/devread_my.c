extern void tbl_printf(const char *format,...);
extern int console_getkey(void);
extern void *grub_memmove(void *to, const void *from, int len);

#include "struct_geometry.c"
extern struct geometry buf_geom;

extern int int13_ah02(int coff, int hoff, int soff, int nsec, int segment);

int devread_my(int sector, int byte_len, char *buf) {
   int cylinder_offset, head_offset, sector_offset;
   int head, nsec;
   char *destino;
   int bytes;
   
   if (sector < 0)    { tbl_printf("ERRO: sector < 0\n");    console_getkey(); return 1; }
   if (byte_len <= 0) { tbl_printf("ERRO: byte_len <= 0\n"); console_getkey(); return 1; }
   
   destino = buf;
   bytes = byte_len - byte_len % 0x200;
   if (byte_len % 0x200) bytes = bytes + 0x200;
   for (;;) {
      if (bytes == 0) break;
      
      if ((bytes/0x200) > 0x40) {
         nsec = 0x40;
         bytes = bytes - 0x40 * 0x200;
      }
      else {
         nsec = bytes/0x200;
         bytes = 0;
      }
      
      // SECTOR_OFFSET is counted from one, while HEAD_OFFSET and CYLINDER_OFFSET are counted from zero.
      head = sector / buf_geom.sectors;
      
      sector_offset   = sector % buf_geom.sectors + 1;
      head_offset     = head % buf_geom.heads;
      cylinder_offset = head / buf_geom.heads;
      
      if (int13_ah02(cylinder_offset, head_offset, sector_offset, nsec, 0x0500)) {
         tbl_printf("CHS(%d,%d,%d) nsec = %d\n", cylinder_offset, head_offset, sector_offset, nsec);
         tbl_printf("ERRO: int13_ah02 falhou\n");
         console_getkey();
         return 1;
      }
      
      if (! grub_memmove((void *)destino, (void *)0x5000, nsec*0x200)) { tbl_printf("ERRO: grub_memmove() falhou\n"); console_getkey(); return 1; }
      
      destino = (destino + nsec * 0x200);
      sector = sector + nsec;
   }
   
   return 0;
}

