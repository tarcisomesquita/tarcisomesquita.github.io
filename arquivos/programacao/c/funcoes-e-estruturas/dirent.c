// #include<bits/dirent.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// The name of the file for each entry is stored in the d_name.
struct dirent {
   unsigned long int d_ino;       // está relacionado aos atributos do arquivo
   long int d_off;                // 
   unsigned short int d_reclen;   // length of filename sem o zero.
   unsigned char d_type;          // type of file. Veja a lista abaixo.
   char d_name[256];              // null terminated file name componte
};

// File types for `d_type'.
enum {
    DT_UNKNOWN = 0,
# define DT_UNKNOWN	DT_UNKNOWN
    DT_FIFO = 1,
# define DT_FIFO	DT_FIFO
    DT_CHR = 2,
# define DT_CHR		DT_CHR
    DT_DIR = 4,   // diretório
# define DT_DIR		DT_DIR
    DT_BLK = 6,
# define DT_BLK		DT_BLK
    DT_REG = 8,   // arquivo comum
# define DT_REG		DT_REG
    DT_LNK = 10,   // link simbólico
# define DT_LNK		DT_LNK
    DT_SOCK = 12,
# define DT_SOCK	DT_SOCK
    DT_WHT = 14
# define DT_WHT		DT_WHT
};

