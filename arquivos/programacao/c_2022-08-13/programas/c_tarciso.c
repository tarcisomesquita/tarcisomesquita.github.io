
// minhas regras:
// '\t' deve ser substituido por 0x20
// '{' deve ser obrigatoriamente seguido de 0x0a
// '}' deve ser obrigatoriamente seguido de 0x0a
// garantir o formato ') {'
// garantir o formato 'else {'
// para cada '{' acrescenta três espaços após a quebra de linha
// substituir 'if(' por 'if ('
// substituir 'for(' por 'for ('

// garantir o formato 'do {'
// substituir ',*' por ', *'
// substituir ' ,*' por ',*'
// substituir 'while (' por 'while('
// substituir 'switch (' por 'switch('
// substituir /**/ por //

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// insere o "array2" na "posicao" em "array1"
unsigned char *acrescenta_array(unsigned char *array1, unsigned long int *array1_size, \
                                unsigned char *array2, unsigned long int *array2_size, unsigned long int posicao) {
   unsigned long int i;
   
   if(posicao > (*array1_size + 1)) return 0x00000000;
   
   array1 = realloc(array1, (*array1_size + *array2_size));
   if(array1 == 0x00000000) {
      fprintf(stderr, "\nERRO Falhou alocação de memória na função acrescenta_array()\n\n");
      return 0x00000000;
   }
   *array1_size = *array1_size + *array2_size;
   
   for(i = (*array1_size - 1); i > (posicao + *array2_size - 1); i--) array1[i] = array1[i - *array2_size];
   for(i = posicao; i < (posicao + *array2_size); i++) array1[i] = array2[i - posicao];
   
   return array1;
}


// Apaga uma "quantidade" de bytes do "array1" a partir da "posicao"
void apaga_array(unsigned char *array1, unsigned long int *array1_size, unsigned long int posicao, unsigned long int quantidade) {
   unsigned long int i;
   for(i = posicao; i < *array1_size; i++) array1[i] = array1[i + quantidade];
   *array1_size = *array1_size - quantidade;
   return;
}


int main(int argc, char **argv) {
   unsigned long int size_file, n, i, n_ch, espacos, tenho_esp, temp_size;
   unsigned char *cache, *temp;
   char nome[100];
   FILE *fd;
   
   if(argc != 2) {
      fprintf(stderr, "\nSintaxe:\n./c_tarciso.elf file.c\n\n");
      return 1;
   }
   
   fd = fopen(argv[1],"rb");
   if(fd <= 0x00) {
      fprintf(stderr, "\nERRO na abertura do arquivo \'%s\'\n\n", argv[1]);
      return 1;
   }
   
   for(size_file=0 ; fgetc(fd) != -1; size_file++);
   fprintf(stdout, "\nO arquivo \'%s\' tem %lu bytes\n\n", argv[1], size_file);
   if(size_file == 0) {
      fclose(fd);
      return 0;
   }
   rewind(fd);
   
   cache = malloc((long unsigned int)size_file);
   n = fread(cache, 1, size_file, fd);
   if(n != size_file) {
      fprintf(stderr, "\nERRO: fread leu menos bytes que o tamanho do arquivo.\nn = %lu\n\n", n);
      fclose(fd);
      return 1;
   }
   fclose(fd);
   
   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   
   // '\t' deve ser substituido por 0x20
   for(n=0; n < size_file ; n++) if(cache[n] == '\t') cache[n] = 0x20;  // '\t' = 0x09 
   
   // '{' deve ser obrigatoriamente seguido de 0x0a
   temp_size = 1;
   temp = malloc(temp_size);
   temp[0] = 0x0a;
   for(n=0; n < (size_file-1) ; n++) {
      if(cache[n] == '{' && cache[n+1] != 0x0a) {  // '{' = 0x7b  '}' = 0x7d
         cache = acrescenta_array(cache, &size_file, temp, &temp_size, n+1);
         if(cache == 0x00000000) {
            printf("\n\nERRO: não foi possível inserir string\n\n");
            return 1;
         }
      }
   }
   free(temp);
   
   // '}' deve ser obrigatoriamente seguido de 0x0a
   temp_size = 1;
   temp = malloc(temp_size);
   temp[0] = 0x0a;
   for(n=0; n < (size_file-1) ; n++) {
      if(cache[n] == '}' && cache[n+1] != 0x0a) {  // '{' = 0x7b  '}' = 0x7d 
         cache = acrescenta_array(cache, &size_file, temp, &temp_size, n+1);
         if(cache == 0x00000000) {
            printf("\n\nERRO: não foi possível inserir string\n\n");
            return 1;
         }
      }
   }
   free(temp);
   
   // garantir o formato ') {'
   temp_size = 1;
   temp = malloc(temp_size);
   temp[0] = ' ';
   for(n=0; n < (size_file-1) ; n++) {
      if(cache[n] == ')') {
         for(i=(n+1); i < size_file ; i++) {
            if(cache[i] != ' ' && cache[i] != 0x0a && cache[i] != '{') break;
            if(cache[i] == '{') {
               if(i != (n+1)) apaga_array(cache, &size_file, n+1, i-n-1);
               cache = acrescenta_array(cache, &size_file, temp, &temp_size, n+1);
               if(cache == 0x00000000) {
                  printf("\n\nERRO: não foi possível inserir string\n\n");
                  return 1;
               }
            }
         }
      }
   }
   free(temp);
   
   // garantir o formato 'else {'
   temp_size = 1;
   temp = malloc(temp_size);
   temp[0] = ' ';
   for(n=0; n < (size_file-4) ; n++) {
      if(cache[n] == 'e' && cache[n+1] == 'l' && cache[n+2] == 's' && cache[n+3] == 'e') {
         for(i=(n+4); i < size_file ; i++) {
            if(cache[i] != ' ' && cache[i] != 0x0a && cache[i] != '{') break;
            if(cache[i] == '{') {
               if(i != (n+4)) apaga_array(cache, &size_file, n+4, i-(n+4));
               cache = acrescenta_array(cache, &size_file, temp, &temp_size, n+4);
               if(cache == 0x00000000) {
                  printf("\n\nERRO: não foi possível inserir string\n\n");
                  return 1;
               }
            }
         }
      }
   }
   free(temp);
   
   // para cada '{' acrescenta três espaços após a quebra de linha
   n_ch = 0;
   for(n=0; n < size_file ; n++) {
      if(cache[n] == 0x0a && n_ch != 0) {
         for(i = n+1; i < size_file; i++) {
            if(cache[i] != 0x20) break;
         }
         
         tenho_esp = i - n - 1;
         
         if(cache[i] == '}') espacos = 3*n_ch - 3;
         else espacos = 3*n_ch;
         
         if(tenho_esp < espacos) {
            temp_size = espacos - tenho_esp;
            temp = malloc(temp_size);
            for(i=0; i < temp_size; i++) temp[i] = 0x20;
            cache = acrescenta_array(cache, &size_file, temp, &temp_size, n+1);
            if(cache == 0x00000000) {
               printf("\n\nERRO: não foi possível inserir string\n\n");
              return 1;
            }
            free(temp);
         }
         
         if(tenho_esp > espacos) {
            apaga_array(cache, &size_file, n+1, tenho_esp - espacos);
         }
      }
      
      if(cache[n] == '{') n_ch++;
      if(cache[n] == '}') n_ch--;
   }
   
   // substituir 'if(' por 'if ('
   for(n=0; n < (size_file-2) ; n++) {
      unsigned char espaco = 0x20;
      unsigned long int comp = 1;
      if(cache[n] == 'i' && cache[n+1] == 'f' && cache[n+2] == '(') acrescenta_array(cache, &size_file, &espaco, &comp, n+2);
   }
   
   // substituir 'for(' por 'for ('
   for(n=0; n < (size_file-3) ; n++) {
      unsigned char espaco = 0x20;
      unsigned long int comp = 1;
      if(cache[n] == 'f' && cache[n+1] == 'o' && cache[n+2] == 'r' && cache[n+3] == '(') acrescenta_array(cache, &size_file, &espaco, &comp, n+3);
   }
   
   // substituir 'while(' por 'while ('
   for(n=0; n < (size_file-5) ; n++) {
      unsigned char espaco = 0x20;
      unsigned long int comp = 1;
      if(cache[n] == 'w' && cache[n+1] == 'h' && cache[n+2] == 'i' && cache[n+3] == 'l' && cache[n+4] == 'e' && cache[n+5] == '(') \
                                                                                      acrescenta_array(cache, &size_file, &espaco, &comp, n+5);
   }
   
   // substituir 'switch(' por 'switch ('
   for(n=0; n < (size_file-6) ; n++) {
      unsigned char espaco = 0x20;
      unsigned long int comp = 1;
      if(cache[n] == 's' && cache[n+1] == 'w' && cache[n+2] == 'i' && cache[n+3] == 't' && cache[n+4] == 'c' && cache[n+5] == 'h' && cache[n+6] == '(') \
                                                                                      acrescenta_array(cache, &size_file, &espaco, &comp, n+6);
   }
   
   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   
   if(strlen(argv[1]) > 100 - 11) {
      fprintf(stderr, "\nERRO O nome do arquivo \'%s\' é muito longo\n\n", nome);
      return 1;
   }
   
   sprintf(nome, "%s%s", argv[1], "_tarciso.c");
   
   fd = fopen(nome,"wb");
   if(fd <= 0x00) {
      fprintf(stderr, "\nERRO na criação do arquivo \'%s\'\n\n", nome);
      return 1;
   }
   
   fwrite(cache, size_file, 1, fd);
   
   fclose(fd);
   free(cache);
   
   return 0;
}

