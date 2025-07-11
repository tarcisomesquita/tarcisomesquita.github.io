// gcc -Wall -Werror fat32_dir.c -o fat32_dir.elf && ./fat32_dir.elf fat32.bin

// #include<linux/msdos_fs.h>

struct msdos_dir_entry {
   unsigned char  name[11];          // maximum name length];// name and extension
   unsigned char  attr;              // attribute bits
   unsigned char  lcase;             // Case for base and extension
   unsigned char  ctime_cs;          // Creation time, centiseconds (0-199)
   unsigned short ctime;             // Creation time
   unsigned short cdate;             // Creation date
   unsigned short adate;             // Last access date
   unsigned short starthi;           // High 16 bits of cluster in FAT32
   unsigned short time,date,start;   // time, date and first cluster
   unsigned int   size;              // file size (in bytes)
};

// Up to 13 characters of the name
struct msdos_dir_slot {
   unsigned char  id;                // sequence number for slot
   unsigned char  name0_4[10];       // first 5 characters in name
   unsigned char  attr;              // attribute byte
   unsigned char  reserved;          // always 0
   unsigned char  alias_checksum;    // checksum for 8.3 alias
   unsigned char  name5_10[12];      // 6 more characters in name
   unsigned short start;             // starting cluster number, 0 in long slots
   unsigned char  name11_12[4];      // last 2 characters in name
};

// #include<fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int open(const char *file, int oflag, ...);

// #include<bits/fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define O_RDONLY           00

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int read (int fd, void *buf, unsigned long int nbytes);
extern int close (int fd);

//#include<stdio.h>
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	

extern int setvbuf(FILE *stream, char *buf, int modes, long unsigned intn);
#define _IOFBF 0 // Fully buffered.
#define _IOLBF 1 // Line buffered.
#define _IONBF 2 // No buffering.

extern int printf(char *, ...);

//  #include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern long unsigned int strlen(char *);

int main(int argc, char **argv, char **argenv) {
   unsigned char cache[512], *db;
   int i, n, fd;
   struct msdos_dir_entry *dir;
   
   setvbuf(stdout, 0, _IONBF, 0);
   printf("\033[2J\033[0;0H");   // clear
   
   fd = open(argv[1], O_RDONLY);
   if (fd < 0) {
      printf("\n");
      printf("ERRO:  Não foi possivel abrir o ARQUIVO \"%s\"\n", argv[1]);
      printf("\n");
      return 1;
   }
   
/*
   reserved = 0x0020
   fats:          db 0x02
   length:        dd 0x00000080         ; 0x00000024   sectors/FAT

   (0x20+2*0x80)*0x200 = offset do cluster 2 (root_cluster)
   
*/
   
   for (i=0; i < (0x0020 + 2 * 0x00000080);i++) {
      n = read(fd, (void *)cache, 512);
      if (n != 512) {
         printf("\nERRO na leitura do arquivo %s\n\n", argv[1]);
         close(fd);
         return 1;
      }
   } 
   
   // 6 é o número do cluster, 0x1000 é o tamanho de um cluster
   for (i=0; i < (6 - 2)*0x1000/512 ;i++) {
      n = read(fd, (void *)cache, 512);
      if (n != 512) {
         printf("\nERRO na leitura do arquivo %s\n\n", argv[1]);
         close(fd);
         return 1;
      }
   } 
   
   n = read(fd, (void *)cache, 512);
   if (n != 512) {
      printf("\nERRO na leitura do arquivo %s\n\n", argv[1]);
      close(fd);
      return 1;
   }
   dir = (struct msdos_dir_entry *)&cache[0];
   db = (unsigned char *)dir;
   
   while (*db != 0x00) {
      if (*db == 0xE5 || *db == 0x2E) {
         dir++;
         db = (unsigned char *)dir;
         continue;
      }
      printf("\nname: ");
      db = (unsigned char *)dir->name;
      for (i=0; i < 11;i++) { printf("%c", *db); db++; }
      printf("\n");
      
      if((dir->attr & 0x01) && (dir->attr & 0x02) && (dir->attr & 0x04) && (dir->attr & 0x08)) printf("attr: long name\n");
      else {
         if(dir->attr & 0x01) printf("attr: read only\n");
         if(dir->attr & 0x02) printf("attr: hidden\n");
         if(dir->attr & 0x04) printf("attr: system\n");
         if(dir->attr & 0x08) printf("attr: volume id\n");
      }
      if(dir->attr & 0x10) printf("attr: directory\n");
      if(dir->attr & 0x20) printf("attr: archive\n");
   
      printf("lcase: 0x%02X       ; Case for base and extension\n", dir->lcase);
      
      printf("ctime_cs: 0x%02X    ; Creation time, centiseconds (0-199)\n", dir->ctime_cs);
      printf("ctime: 0x%04X     ; Creation time    ", dir->ctime);
      printf("%02d:%02d:%02d.%03d\n", dir->ctime >> 11, (dir->ctime >> 5) && 0x003F, (dir->ctime && 0x001F)*2, dir->ctime_cs);
   
      printf("cdate: 0x%04X     ; Creation date    ", dir->cdate);
      printf("%04d/%02d/%02d\n", (dir->cdate >> 9) + 1980, (dir->cdate >> 5) && 0x000F, dir->cdate && 0x001F);
   
      printf("adate: 0x%04X     ; Last access date   ", dir->adate);
      printf("%04d/%02d/%02d\n", (dir->adate >> 9) + 1980, (dir->adate >> 5) && 0x000F, dir->adate && 0x001F);
   
      printf("starthi: 0x%04X   ; high word of cluster\n", dir->starthi);
      
      printf("mtime: 0x%04X     ; Last modified Time   ", dir->time);
      printf("%02d:%02d:%02d\n", dir->time >> 11, (dir->time >> 5) && 0x003F, dir->time && 0x001F);
      printf("mdate: 0x%04X     ; Last modified Date   ", dir->date);
      printf("%04d/%02d/%02d\n", (dir->date >> 9) + 1980, (dir->date >> 5) && 0x000F, dir->date && 0x001F);
      
      printf("start: 0x%04X     ; low word of first cluster\n", dir->start);
      printf("size:  0x%08X ; file size (in bytes)\n", dir->size);
      
      dir++;
      db = (unsigned char *)dir;
   }
   close(fd);
   
   return 0;
}

