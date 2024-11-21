
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void imprima_o_estado_sugerido()
{
   int x, y;
   
   printf("\n");
   for(x=0; x<5 ; x++)
   {
      for(y=0; y<4 ; y++)
      {
         printf("%02X ", a[x][y]);
      }
      printf("\n");
   }
   
   return;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void imprima_o_estado(int num)
{
   int x, y;
   unsigned char     *pont_estado;
   unsigned long int *pont_galho;
   
   pont_estado = (unsigned char *)estado[num];
   pont_galho  = (unsigned long int *)&pont_estado[24];
   
   for(x = 0; x < 5 ; x++)
   {
      printf("\n");
      for(y = 0; y < 4 ; y++)
      {
         printf("%02X ", pont_estado[(4*x)+y]);
      }
   }
   printf("\n\n");
   
   // o objetivo é imprimir os números dos estados dos galhos no formato abaixo
   //esq_dir    dir_esq    cima_baixo baixo_cima | esq_dir    dir_esq    cima_baixo baixo_cima | anterior
   //FFFFFFFF   FFFFFFFF   FFFFFFFF   FFFFFFFF   | FFFFFFFF   FFFFFFFF   FFFFFFFF   FFFFFFFF   | FFFFFFFF
                 
   for(x = 0 ; x < 8 ; x++)
   {
      if( (pont_estado[20] & (0b10000000 >> x)) )
      {
         switch(x)
         {
            case 0: printf("esq_dir    "); break;
            case 1: printf("dir_esq    "); break;
            case 2: printf("cima_baixo "); break;
            case 3: printf("baixo_cima "); break;
            case 4: printf("esq_dir    "); break;
            case 5: printf("dir_esq    "); break;
            case 6: printf("cima_baixo "); break;
            case 7: printf("baixo_cima "); break;
         } // Fim switch
      }
      else
      {
         printf("           "); // Se um movimento não é possível, não imprime o nome do galho
      }
      
      if(x == 3)
      {
         printf("| ");
      }
      
      if(x == 7)
      {
         printf("| anterior");
      }
   }
   printf("\n");
   
   for(x = 0; x < 8 ; x++)
   {
      if( (pont_estado[20] & (0b10000000 >> x)) ) printf("%08X   ", (unsigned int)pont_galho[x]);
      else                                        printf("           ");
      
      if(x == 3)
      {
         printf("| ");
      }
   }
   printf("| ");
   
   for(y = 3; y >= 0 ; y--)
      printf("%02X", pont_estado[56+y]);
   printf("\n");
   
   return;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void imprima_todos_os_estados()
{
   int k;
   
   for(k=0; k < n_total ; k++)
   {
      printf("\n\nestado[%08X]", k);
      imprima_o_estado(k);
   }
   return;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void imprima_os_estados_do_tronco_do_estado_atual()
{
   unsigned char *pont_estado;
   unsigned long int *pont_tronco;
   unsigned long int *estados_do_tronco, n_estado_temp;
   int x, y;
   
   estados_do_tronco = 0x00000000; // a memória será alocada dinamicamente
   n_estado_temp = n_estado;
   
   for(x=0; ;x++)
   {
      estados_do_tronco = realloc(estados_do_tronco, (x+1)*sizeof(unsigned long int));
      
      estados_do_tronco[x] = n_estado_temp;
      
      pont_estado = (unsigned char *)estado[n_estado_temp];
      pont_tronco = (unsigned long int *)&pont_estado[56];
      n_estado_temp = pont_tronco[0];
      if(n_estado_temp == 0xFFFFFFFF) break;
   }
   
   for(y=x; y>=0 ; y--)
   {
      printf("\n\nestado[%08X]", (unsigned int)estados_do_tronco[y]);
      imprima_o_estado(estados_do_tronco[y]);
      
      if(y == n_estado) break;
   }
   
   free(estados_do_tronco);
   return;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

int quantos_movimentos_usei_para_chegar_no_estado(int num)
{
   int x;
   unsigned char     *pont_estado;
   unsigned long int *pont_tronco;
   
   x = 0;
   if(num == 0xFFFFFFFF)
   {
      return x;
   }
   
   for(;;)
   {
      //printf("num = %d\n", num);
      //if(num == 0)
      //{
      //   break;
      //}
      pont_estado = (unsigned char *)estado[num];
      pont_tronco = (unsigned long int *)&pont_estado[56];
      num = pont_tronco[0];
      if(num == 0xFFFFFFFF)
      {
         return x;
      }
      x++;
   }
   //printf("Passei x = %d\n", x);
   return x;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void quanto_de_memoria()
{
   unsigned long int memoria;
   register unsigned long int diferenca;
   
   memoria = (60*n_total)/(1024*1024);
   if(memoria > 1)
   {
      diferenca = memoria - memoria_usada;
      if(diferenca > 1)
      {
         memoria_usada = memoria_usada + diferenca;
         printf("Estou usando %lu MiB de RAM\n", memoria_usada);
      }
   }
}

