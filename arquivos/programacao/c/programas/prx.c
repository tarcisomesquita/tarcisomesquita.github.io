// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int write(int __fd, const void *__buf, unsigned long int __n);
extern int read(int __fd, void *__buf, unsigned long int __nbytes);

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdin;	
extern struct _IO_FILE *stdout;	
extern int fileno (FILE *__stream);

extern int printf(char *, ...);

int uppercase_to_lowcase(unsigned char *cache, unsigned long int len) {
   unsigned long int i;
   
   for (i=0; i < len; ) {
      // não coloquei o i++ no for() por que abaixo preciso de um i = i + 2;
      if      (cache[i] >= 0x41 && cache[i] <= 0x5A) { cache[i] = cache[i] + 0x20; i++; continue; }// A-Z
      else if (cache[i] >= 0x61 && cache[i] <= 0x7A) { i++; continue; } // a-z
      else if (cache[i] == 0x0A) { i++; continue; } // enter
      else if (cache[i] == 0x20) { i++; continue; } // espaço
      else if (cache[i] == 0x28) { i++; continue; } // (
      else if (cache[i] == 0x29) { i++; continue; } // )
      else if (cache[i] == 0x2C) { i++; continue; } // ,
      else if (cache[i] == 0x2D) { i++; continue; } // -
      else if (cache[i] == 0x2E) { i++; continue; } // ponto
      else if (cache[i] == 0x3A) { i++; continue; } // :
      
      else if (cache[i] == 0xC3) {
         if (! ((i+1) < len)) { i++; break; }
         switch (cache[i+1]) {
            case 0x81: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // Á
            case 0x89: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // É
            case 0x8d: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // Í
            case 0x93: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // Ó
            case 0x9a: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // Ú
            case 0xa1: i = i + 2; break; // á
            case 0xa9: i = i + 2; break; // é
            case 0xad: i = i + 2; break; // í
            case 0xb3: i = i + 2; break; // ó
            case 0xba: i = i + 2; break; // ú
            
            case 0x82: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // Â
            case 0x8a: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // Ê
            case 0x94: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // Ô
            case 0x80: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // À
            case 0xa2: i = i + 2; break; // â
            case 0xaa: i = i + 2; break; // ê
            case 0xb4: i = i + 2; break; // ô
            case 0xa0: i = i + 2; break; // à
            
            case 0x83: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // Ã
            case 0x95: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // Õ
            case 0xa3: i = i + 2; break; // ã
            case 0xb5: i = i + 2; break; // õ
            
            case 0x87: cache[i+1] = cache[i+1] + 0x20; i = i + 2; break; // Ç
            case 0xa7: i = i + 2; break; // ç
            
            default: return 1;
         }
      }
      else return 1;
   }

   return 0;
}


int main(int argc, char **argv) {
   char entrada[10000];
   int i, j, in, out;
   unsigned long int padrao_len, entrada_len;
   
   if (argc != 2) {
      write(out, "\nUsage:\n./prx.elf \"padrao\"\n\n", 32);
      return 1;
   }
   
   in = fileno(stdin);
   out = fileno(stdout);
   
   for (i=0; i < 10000; i++) entrada[i] = 0x00;
   
   padrao_len = 0;
   for (i=0; i < 161; i++) {
      if (argv[1][i] == 0x00) {
         padrao_len = i;
         break;
      }
   }
   
   if (i == 161) {
      write(out, "\nUsage:\n./prx.elf \"padrao\"\n'padrao' deve ser menor que 160 bytes\n\n", 75);
      return 1;
   }
   if (padrao_len == 0) return 0;
   
   for (i=0; i < 10000; i++) {
      read(in, &entrada[i], 1);
      if (entrada[i] == 0x0A) {
         entrada_len = i;
         break;
      }
   }
   if (padrao_len > entrada_len) return 0;
   
   if (uppercase_to_lowcase((unsigned char *)entrada, entrada_len)) return 1;
   
   for (i=0; i < (entrada_len - padrao_len + 1); i++) {
      for (j=0; j < padrao_len; j++) if (entrada[i+j] != argv[1][j]) break; // encontra o padrão na entrada
      if (j == padrao_len) break; // verifica se o padrão já foi encontrado
   }
   
   //printf("%d   %lu\n", i, (entrada_len - padrao_len + 1));
   if (i == (entrada_len - padrao_len + 1)) return 0; // padrão não encontrado
   
   i = i + j;
   
   if (entrada[i] == 0x20) i++; // espaço
   else return 0;
   
   j = i;
   
   for ( ; i < entrada_len; i++) {
      if (entrada[i] == 0x20) break;      // espaço
      else if (entrada[i] == 0x2E) break; // ponto
   }
   
   entrada[i] = 0x0A;
   write(out, &entrada[j], (i - j + 1));
   
   return 0;
}

