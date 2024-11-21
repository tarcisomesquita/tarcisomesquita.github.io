extern int console_getkey(void);
extern void tbl_printf(const char *format,...);
extern int int13_ah08(int drive, unsigned int *cylinders, unsigned int *heads, unsigned int *sectors);

extern unsigned int current_drive;

#include "struct_geometry.c"
struct geometry buf_geom;


// Return the geometry of DRIVE in GEOMETRY. If an error occurs, return non-zero, otherwise zero.
int get_diskinfo() {
   
//   tbl_printf("> get_diskinfo(0x%X)\n", current_drive);
   
   buf_geom.sector_size = 0x200;  // 512 bytes
   buf_geom.flags = 0;
   
   if ( ! (current_drive & 0x80) ) {
      tbl_printf("ERRO: ! (current_drive & 0x80)\n");
      return 1;
   }

   if (int13_ah08(current_drive, &buf_geom.cylinders, &buf_geom.heads, &buf_geom.sectors)) {
      tbl_printf("ERRO: int13_ah08() falhou\n");
      return 1;
   }
   
   // int 13 AH 02 não lê o último cilindro do disco. Um jeito de evitar erro é deixar livre 8MiB no final do disco
   //tbl_printf("CHS(%d, %d, %d)\n", buf_geom.cylinders, buf_geom.heads, buf_geom.sectors);
   buf_geom.total_sectors = buf_geom.cylinders * 255 * 63 + buf_geom.heads * 63 + buf_geom.sectors * 1;
   //tbl_printf("buf_geom.total_sectors = %d\n", buf_geom.total_sectors);
   
   if (buf_geom.sectors > 63 || buf_geom.sectors == 0) {
      tbl_printf("buf_geom.sectors = %d\n", buf_geom.sectors);
      tbl_printf("O número de setores por trilha nao pode ser maior que 63, nem zero.\n");
      return 1;
   }

   return 0;
}

