
// gcc -Wall scandir.c -o scandir.elf && ./scandir.elf

// scans the contents of the directory
// dir: o diretório a ser listado
// *namelist is an array of pointers to structure of type struct dirent
// struct dirent describe all directory entries
// *selector is a function that decide which entries are in the result. Only the entries for which selector returns a non-zero value are selected.
// *cmp is a function that sort entries in *namelist. See the functions alphasort and versionsort.
// Return the number of entries placed in *namelist.
// Return -1 for error.


//#include<dirent.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = 
struct dirent {
   unsigned long int d_ino;
   long int d_off;
   unsigned short int d_reclen;
   unsigned char d_type;
   char d_name[256];
};

extern int scandir (const char *dir, struct dirent ***namelist, int (*selector) (const struct dirent *), int (*cmp) (const void *, const void *));

extern int alphasort (const void *e1, const void *e2);
// Compare e1 and e2.
// retorna -1 e1[n] <= e2[n]
// retorna  0 e1[n] == e2[n]
// retorna  1 e1[n] >= e2[n]

#include <stdio.h>

static int one (const struct dirent *unused) {
   return 1;
}

int main () {
   struct dirent **eps;
   int n;
   
   n = scandir ("./", &eps, one, alphasort);
   
   if (n >= 0) {
      printf("\n");
      int cnt;
      for (cnt = 0; cnt < n; ++cnt) {
         printf ("eps[%d]->d_ino = %lu\n", cnt, eps[cnt]->d_ino);
         printf ("eps[%d]->d_off = %d\n", cnt, eps[cnt]->d_off);
         printf ("eps[%d]->d_reclen = %u\n", cnt, eps[cnt]->d_reclen);
         printf ("eps[%d]->d_type = %u\n", cnt, eps[cnt]->d_type);
         printf ("eps[%d]->d_name = %s\n", cnt, eps[cnt]->d_name);
         printf("\n");
      }
   }
   else perror ("Couldn't open the directory");
   
   return 0;
}

