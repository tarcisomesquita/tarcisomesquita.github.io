
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// quando é alocada memória para um estado, é escrito indefinido nos dados dele. Depois as funções gravam os valores reais dele .
void escreva_indefinido_no_estado(int num)
{
   int x, y;
   unsigned char *pont_estado;
   
   pont_estado = (unsigned char *)estado[num];
   
   for(x=0; x<5 ; x++)
   {
      for(y=0; y<4 ; y++)
      {
         pont_estado[(4*x)+y] = 0xFF;       // peça = 0xFF = indefinido
      }
   }
   
   for(x=0; x<4 ; x++)
      pont_estado[20+x] = 0xFF;             // mov_byte = 0xFF = indefinido
   
   for(x=0; x<8 ; x++)
   {
      for(y=0; y<4 ; y++)
         pont_estado[24+(4*x)+y] = 0xFF;    // n_galho = 0xFFFFFFFF = indefinido
   }
   
   for(x=0; x<4 ; x++)
      pont_estado[56+x] = 0xFF;             // n_tronco = 0xFFFFFFFF = indefinido
   
   return;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


int escreva_estado_novo_na_arvore()
{
   int x, y;
   unsigned char *pont_estado;
   unsigned long int *pont_galho;
   unsigned long int *pont_tronco;
   
   // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
   // Cria novo estado
   n_total++;
   estado = realloc(estado, n_total*4);
   
   estado[n_total-1] = malloc(sizeof(struct arvore));
   
   escreva_indefinido_no_estado(n_total - 1);
   
   // Aqui devo colocar para imprimir a quantidade de memória usada
   
   // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
   // Escreve dados no estado onde estou atualmente
   pont_estado = (unsigned char *)estado[n_estado];
   pont_galho  = (unsigned long int *)&pont_estado[24];
   pont_tronco = (unsigned long int *)&pont_estado[56];
   if(n_total  != 1) pont_galho[n_galho] = n_total - 1; // Para onde vai
   
   
   // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
   // Muda para o estado novo e escreve dados nele
   pont_estado = (unsigned char *)estado[n_total - 1];
   pont_galho  = (unsigned long int *)&pont_estado[24];
   pont_tronco = (unsigned long int *)&pont_estado[56];
   if((n_total - 1) != 0) pont_tronco[0] = n_estado;  // De onde veio
   
   for(x=0; x<5 ; x++)  // Escreve a nova disposição das peças
   {
      for(y=0; y<4 ; y++)
      {
         pont_estado[(4*x)+y] = a[x][y];
      }
   }
   
   if((pont_estado[1] == 0x44) && (pont_estado[2] == 0x44)) return 1;
   else return 0;
}

