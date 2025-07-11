
// minhas regras para arquivos o arquivos .c ou .js ou .java

// substituir '\t' por 0x20
// substituir 0x20 0x20 por 0x20
// substituir 0x0a 0x0a por 0x0a
// substituir 0x20 0x0a por 0x0a
// substituir 0x0a 0x20 por 0x0a

// substituir ' =' por '='
// substituir '= ' por '='
// substituir '=' por ' ='
// substituir '=' por '= '
// substituir '=  =' por '=='


// substituir 0x20 '{' por '{'
// substituir 0x0a '{' por '{'

// substituir 0x20 '(' por '('

// substituir 0x20 ','  por ','
// substituir ',' 0x20 por ','

// inserir 0x20 antes de '{'
// inserir 0x0a após de '{'

// inserir 0x0a antes de '}'
// inserir 0x0a após de '}'

// inserir 0x20 antes de '('

// inserir 0x20 após de ','

// para cada '{' acrescenta três espaços após a quebra de linha


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


// Retorna a "posicao" do "array2" no "array1"
// Retorna 0xFFFFFFFF para não localizado ou erro
unsigned long int localiza_array(unsigned char *array1, unsigned long int array1_size, unsigned char *array2, unsigned long int array2_size) {
   unsigned long int i, j;
   unsigned char ok;
   
   if (array1_size < array2_size ) return 0xFFFFFFFF;
   
   ok = 0x00;
   for(i = 0 ; i <= (array1_size - array2_size); i++) {
      for(j = 0 ; j < array2_size; j++) {
         if (array1[i+j] == array2[j]) ok = 0x01;
         else {
            ok = 0x00;
            break;
         }
      }
      
      if (ok == 0x01) return i;
   }
   return 0xFFFFFFFF;
}


// substitui o array2 pelo array3 no array1
// Retorna o número de substituições
unsigned long int substitui_array(unsigned char *array1, unsigned long int *array1_size,
                                  unsigned char *array2, unsigned long int array2_size,
                                  unsigned char *array3, unsigned long int array3_size) {
   unsigned long int posicao, posicao_old, substituicoes;
   unsigned char *array1_temp;
   unsigned long int array1_size_temp;
   
   if (*array1_size < array2_size || *array1_size < array3_size) return 0;
   
   array1_temp = array1;
   array1_size_temp = *array1_size;
   posicao_old = 0;
   substituicoes = 0;
   for ( ; ; ) {
      posicao = localiza_array(array1_temp, array1_size_temp, array2, array2_size);
      if (posicao == 0xFFFFFFFF) return substituicoes;
      substituicoes++;
      posicao = posicao + posicao_old;
      //fprintf(stdout,"\n*array1_size = %lu\n", *array1_size);
      apaga_array(array1, array1_size, posicao, array2_size);
      //fprintf(stdout,"\n*array1_size = %lu\n", *array1_size);
      if (! acrescenta_array(array1, array1_size, array3, &array3_size, posicao)) return substituicoes;
      //fprintf(stdout,"\n*array1_size = %lu\n", *array1_size);
      
      posicao_old = posicao + array3_size;
      array1_temp = &array1[posicao_old];
      array1_size_temp = *array1_size - posicao_old;
   }
   return 0;
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
   
   //size_file++;
   cache = malloc((long unsigned int)size_file);
   n = fread(cache, 1, size_file, fd);
   if(n != size_file) {
      fprintf(stderr, "\nERRO: fread leu menos bytes que o tamanho do arquivo.\nn = %lu\n\n", n);
      fclose(fd);
      return 1;
   }
   fclose(fd);
   //cache[size_file - 1] = 0x00;
   
   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   
   
   // substituir '\t' por 0x20
   substitui_array(cache, &size_file, (unsigned char *)"\t", 1, (unsigned char *)" ", 1);
   
   // substituir 0x20 0x20 por 0x20
   while(substitui_array(cache, &size_file, (unsigned char *)"  ", 2, (unsigned char *)" ", 1));
   
   // substituir 0x0a 0x0a por 0x0a
   while(substitui_array(cache, &size_file, (unsigned char *)"\n\n", 2, (unsigned char *)"\n", 1));
   
   // substituir 0x20 0x0a por 0x0a
   substitui_array(cache, &size_file, (unsigned char *)" \n", 2, (unsigned char *)"\n", 1);
   
   // substituir 0x0a 0x20 por 0x0a
   substitui_array(cache, &size_file, (unsigned char *)"\n ", 2, (unsigned char *)"\n", 1);
   
   
   // substituir ' =' por '='
   substitui_array(cache, &size_file, (unsigned char *)" =", 2, (unsigned char *)"=", 1);
   
   // substituir '= ' por '='
   substitui_array(cache, &size_file, (unsigned char *)"= ", 2, (unsigned char *)"=", 1);
   
   // substituir '=' por ' ='
   substitui_array(cache, &size_file, (unsigned char *)"=", 1, (unsigned char *)" =", 2);
   
   // substituir '=' por '= '
   substitui_array(cache, &size_file, (unsigned char *)"=", 1, (unsigned char *)"= ", 2);
   
   // substituir '=  =' por '=='
   while(substitui_array(cache, &size_file, (unsigned char *)"=  =", 4, (unsigned char *)"==", 2));
   
   
   // substituir ' +' por '+'
   substitui_array(cache, &size_file, (unsigned char *)" +", 2, (unsigned char *)"+", 1);
   
   // substituir '+ ' por '+'
   substitui_array(cache, &size_file, (unsigned char *)"+ ", 2, (unsigned char *)"+", 1);
   
   // substituir '+' por ' +'
   substitui_array(cache, &size_file, (unsigned char *)"+", 1, (unsigned char *)" +", 2);
   
   // substituir '+' por '+ '
   substitui_array(cache, &size_file, (unsigned char *)"+", 1, (unsigned char *)"+ ", 2);
   
   // substituir ' +  + ' por '++'
   while(substitui_array(cache, &size_file, (unsigned char *)" +  + ", 6, (unsigned char *)"++", 2));
   
   // substituir '+ =' por '+='
   substitui_array(cache, &size_file, (unsigned char *)"+ =", 3, (unsigned char *)"+=", 2);
   
   
   // substituir ' -' por '-'
   substitui_array(cache, &size_file, (unsigned char *)" -", 2, (unsigned char *)"-", 1);
   
   // substituir '- ' por '-'
   substitui_array(cache, &size_file, (unsigned char *)"- ", 2, (unsigned char *)"-", 1);
   
   // substituir '-' por ' -'
   substitui_array(cache, &size_file, (unsigned char *)"-", 1, (unsigned char *)" -", 2);
   
   // substituir '-' por '- '
   substitui_array(cache, &size_file, (unsigned char *)"-", 1, (unsigned char *)"- ", 2);
   
   // substituir ' -  - ' por '--'
   while(substitui_array(cache, &size_file, (unsigned char *)" -  - ", 6, (unsigned char *)"--", 2));
   
   // substituir '- =' por '-='
   substitui_array(cache, &size_file, (unsigned char *)"- =", 3, (unsigned char *)"-=", 2);
   
   
   // substituir ' *' por '*'
   substitui_array(cache, &size_file, (unsigned char *)" *", 2, (unsigned char *)"*", 1);
   
   // substituir '* ' por '*'
   substitui_array(cache, &size_file, (unsigned char *)"* ", 2, (unsigned char *)"*", 1);
   
   // substituir '*' por ' *'
   substitui_array(cache, &size_file, (unsigned char *)"*", 1, (unsigned char *)" *", 2);
   
   // substituir '*' por '* '
   substitui_array(cache, &size_file, (unsigned char *)"*", 1, (unsigned char *)"* ", 2);
   
   // substituir ' *  * ' por '**'
   while(substitui_array(cache, &size_file, (unsigned char *)" * * ", 5, (unsigned char *)"**", 2));
   
   // substituir '* =' por '*='
   substitui_array(cache, &size_file, (unsigned char *)"* =", 3, (unsigned char *)"*=", 2);
   
   
   // substituir ' /' por '/'
   substitui_array(cache, &size_file, (unsigned char *)" /", 2, (unsigned char *)"/", 1);
   
   // substituir '/ ' por '/'
   substitui_array(cache, &size_file, (unsigned char *)"/ ", 2, (unsigned char *)"/", 1);
   
   // substituir '/' por ' /'
   substitui_array(cache, &size_file, (unsigned char *)"/", 1, (unsigned char *)" /", 2);
   
   // substituir '/' por '/ '
   substitui_array(cache, &size_file, (unsigned char *)"/", 1, (unsigned char *)"/ ", 2);
   
   // substituir ' / / ' por '//'
   while(substitui_array(cache, &size_file, (unsigned char *)" /  / ", 6, (unsigned char *)"//", 2));
   
   
   // substituir ' / * ' por '/*'
   substitui_array(cache, &size_file, (unsigned char *)" / * ", 5, (unsigned char *)"/*", 2);
   
   // substituir ' * / ' por '*/'
   substitui_array(cache, &size_file, (unsigned char *)" * / ", 5, (unsigned char *)"*/", 2);
   
   
   // substituir ' &' por '&'
   substitui_array(cache, &size_file, (unsigned char *)" &", 2, (unsigned char *)"&", 1);
   
   // substituir '& ' por '&'
   substitui_array(cache, &size_file, (unsigned char *)"& ", 2, (unsigned char *)"&", 1);
   
   // substituir '&' por ' &'
   substitui_array(cache, &size_file, (unsigned char *)"&", 1, (unsigned char *)" &", 2);
   
   // substituir '&' por '& '
   substitui_array(cache, &size_file, (unsigned char *)"&", 1, (unsigned char *)"& ", 2);
   
   // substituir '&  &' por '&&'
   while(substitui_array(cache, &size_file, (unsigned char *)"&  &", 4, (unsigned char *)"&&", 2));
   
   
   // substituir ' |' por '|'
   substitui_array(cache, &size_file, (unsigned char *)" |", 2, (unsigned char *)"|", 1);
   
   // substituir '| ' por '|'
   substitui_array(cache, &size_file, (unsigned char *)"| ", 2, (unsigned char *)"|", 1);
   
   // substituir '|' por ' |'
   substitui_array(cache, &size_file, (unsigned char *)"|", 1, (unsigned char *)" |", 2);
   
   // substituir '|' por '| '
   substitui_array(cache, &size_file, (unsigned char *)"|", 1, (unsigned char *)"| ", 2);
   
   // substituir '|  |' por '||'
   while(substitui_array(cache, &size_file, (unsigned char *)"|  |", 4, (unsigned char *)"||", 2));
   
   
   // substituir ' <' por '<'
   substitui_array(cache, &size_file, (unsigned char *)" <", 2, (unsigned char *)"<", 1);
   
   // substituir '< ' por '<'
   substitui_array(cache, &size_file, (unsigned char *)"< ", 2, (unsigned char *)"<", 1);
   
   // substituir '<' por ' <'
   substitui_array(cache, &size_file, (unsigned char *)"<", 1, (unsigned char *)" <", 2);
   
   // substituir '<' por '< '
   substitui_array(cache, &size_file, (unsigned char *)"<", 1, (unsigned char *)"< ", 2);
   
   // substituir '<  <' por '<<'
   while(substitui_array(cache, &size_file, (unsigned char *)"<  <", 4, (unsigned char *)"<<", 2));
   
   
   // substituir ' >' por '>'
   substitui_array(cache, &size_file, (unsigned char *)" >", 2, (unsigned char *)">", 1);
   
   // substituir '> ' por '>'
   substitui_array(cache, &size_file, (unsigned char *)"> ", 2, (unsigned char *)">", 1);
   
   // substituir '>' por ' >'
   substitui_array(cache, &size_file, (unsigned char *)">", 1, (unsigned char *)" >", 2);
   
   // substituir '>' por '> '
   substitui_array(cache, &size_file, (unsigned char *)">", 1, (unsigned char *)"> ", 2);
   
   // substituir '>  >' por '>>'
   while(substitui_array(cache, &size_file, (unsigned char *)">  >", 4, (unsigned char *)">>", 2));
   
   
   // substituir ' - > ' por '->'
   substitui_array(cache, &size_file, (unsigned char *)" - > ", 5, (unsigned char *)"->", 2);
   
   // substituir ' = > ' por '=>'
   substitui_array(cache, &size_file, (unsigned char *)" = > ", 5, (unsigned char *)" => ", 4);
   
   // substituir ' > = ' por '>='
   substitui_array(cache, &size_file, (unsigned char *)" > = ", 5, (unsigned char *)" >= ", 4);
   
   // substituir '= <' por '=<'
   substitui_array(cache, &size_file, (unsigned char *)"= <", 3, (unsigned char *)"=<", 2);
   
   // substituir '< =' por '<='
   substitui_array(cache, &size_file, (unsigned char *)"< =", 3, (unsigned char *)"<=", 2);
   
   
   // substituir '!' por '! '
   substitui_array(cache, &size_file, (unsigned char *)"!", 1, (unsigned char *)"! ", 2);
   
   
   // substituir 0x20 ";\n" por ";"
   substitui_array(cache, &size_file, (unsigned char *)";\n", 2, (unsigned char *)";", 1);
   
   // substituir 0x20 ";" por ";\n"
   substitui_array(cache, &size_file, (unsigned char *)";", 1, (unsigned char *)";\n", 2);
   
   
   // substituir 0x20 '{' por '{'
   substitui_array(cache, &size_file, (unsigned char *)" {", 2, (unsigned char *)"{", 1);
   
   // substituir 0x0a '{' por '{'
   substitui_array(cache, &size_file, (unsigned char *)"\n{", 2, (unsigned char *)"{", 1);
   
   // substituir 0x20 '(' por '('
   substitui_array(cache, &size_file, (unsigned char *)" (", 2, (unsigned char *)"(", 1);
   
   // substituir ' ,'  por ','
   substitui_array(cache, &size_file, (unsigned char *)" ,", 2, (unsigned char *)",", 1);
   
   // substituir ',' 0x20 por ','
   substitui_array(cache, &size_file, (unsigned char *)", ", 2, (unsigned char *)",", 1);
   
   // inserir 0x20 antes de '{'
   substitui_array(cache, &size_file, (unsigned char *)"{", 1, (unsigned char *)" {", 2);
   
   
   // substituir "{\n" por "{"
   substitui_array(cache, &size_file, (unsigned char *)"{\n", 2, (unsigned char *)"{", 1);
   
   // substituir "{" por "{\n"
   substitui_array(cache, &size_file, (unsigned char *)"{", 1, (unsigned char *)"{\n", 2);
   
   
   // substituir "}\n" por "}"
   substitui_array(cache, &size_file, (unsigned char *)"}\n", 2, (unsigned char *)"}", 1);
   
   // substituir "}" por "}\n"
   substitui_array(cache, &size_file, (unsigned char *)"}", 1, (unsigned char *)"}\n", 2);
   
   
   // substituir "\n}" por "}"
   substitui_array(cache, &size_file, (unsigned char *)"\n}", 2, (unsigned char *)"}", 1);
   
   // substituir "}" por "\n}"
   substitui_array(cache, &size_file, (unsigned char *)"}", 1, (unsigned char *)"\n}", 2);
   
   
   // substituir }\n; por };
   substitui_array(cache, &size_file, (unsigned char *)"}\n;", 3, (unsigned char *)"};", 2);
   
   // substituir }\n, por },\n
   substitui_array(cache, &size_file, (unsigned char *)"}\n,", 3, (unsigned char *)"},\n", 3);
   
   
   // substituir ') ' por ')'
   substitui_array(cache, &size_file, (unsigned char *)") ", 2, (unsigned char *)")", 1);
   
   // substituir ')' por ') '
   substitui_array(cache, &size_file, (unsigned char *)")", 1, (unsigned char *)") ", 2);
   
   // substituir ') ;' por ');'
   substitui_array(cache, &size_file, (unsigned char *)") ;", 3, (unsigned char *)");", 2);
   
   // substituir ') ,' por '),'
   substitui_array(cache, &size_file, (unsigned char *)") ,", 3, (unsigned char *)"),", 2);
   
   // substituir ') .' por ').'
   substitui_array(cache, &size_file, (unsigned char *)") .", 3, (unsigned char *)").", 2);
   
   
   // inserir 0x20 antes de '('
   substitui_array(cache, &size_file, (unsigned char *)"(", 1, (unsigned char *)" (", 2);
   
   // inserir 0x20 após de ','
   substitui_array(cache, &size_file, (unsigned char *)",", 1, (unsigned char *)", ", 2);
   
   //for(n=0; n < size_file ; n++) fprintf(stdout, "%c", cache[n]); fprintf(stdout, "\n");
   
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

