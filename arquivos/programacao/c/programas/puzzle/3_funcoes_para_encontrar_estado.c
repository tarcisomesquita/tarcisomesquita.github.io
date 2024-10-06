
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// = = = = = = = = funções que movem as peças = = = = = = = = = = = = = = = = =

int mova_da_esquerda_para_direita()
{
   if((j < 1) || (j > 3)) return 0;
   
   if(a[i][j-1] == 0x11)
   {
      a[i][j]   = 0x11;
      a[i][j-1] = 0x00;
      j = j - 1;
      return 1;
   }
   
   if((a[i][j-1] == 0x12) && (j > 1) && (a[i][j-2] == 0x12))
   {
      a[i][j-2] = 0x00;   a[i][j] = 0x12;
      j = j - 2;
      return 1;
   }
   
   if((a[i][j-1] == 0x21) && (i != 4) && (a[i+1][j] == 0x00) && (a[i+1][j-1] == 0x21))
   {
      a[i][j]   = 0x21;   a[i][j-1]   = 0x00;
      a[i+1][j] = 0x21;   a[i+1][j-1] = 0x00;
      j = j - 1;
      return 1;
   }
   
   if(            (a[i][j-1]   == 0x44) && (j > 1) && (a[i][j-2]   == 0x44) && \
      (i != 4) && (a[i+1][j-1] == 0x44) &&            (a[i+1][j-2] == 0x44) && (a[i+1][j] == 0x00))
   {
      a[i][j-2]   = 0x00;   a[i][j]   = 0x44;
      a[i+1][j-2] = 0x00;   a[i+1][j] = 0x44;
      j = j - 2;
      return 1;
   }
   
   return 0;
}

int mova_da_direita_para_esquerda()
{
   if((j < 0) || (j > 2)) return 0;
   
   if(a[i][j+1] == 0x11)
   {
      a[i][j]   = 0x11;
      a[i][j+1] = 0x00;
      j = j + 1;
      return 1;
   }
   
   if((a[i][j+1] == 0x12) && (j != 2) && (a[i][j+2] == 0x12))
   {
      a[i][j] = 0x12;   a[i][j+2] = 0x00;
      j = j + 2;
      return 1;
   }
   
   if((a[i][j+1] == 0x21) && (i != 4) && (a[i+1][j] == 0x00) && (a[i+1][j+1] == 0x21))
   {
      a[i][j]   = 0x21;   a[i][j+1]   = 0x00;
      a[i+1][j] = 0x21;   a[i+1][j+1] = 0x00;
      j = j + 1;
      return 1;
   }
   
   if(            (a[i][j+1]   == 0x44) && (j != 2) && (a[i][j+2]   == 0x44) && \
      (i != 4) && (a[i+1][j+1] == 0x44) &&             (a[i+1][j+2] == 0x44) && (a[i+1][j] == 0x00))
   {
      a[i][j]   = 0x44;   a[i][j+2]   = 0x00;
      a[i+1][j] = 0x44;   a[i+1][j+2] = 0x00;
      j = j + 2;
      return 1;
   }
   return 0;
}

int mova_de_cima_para_baixo()
{
   if((i < 1) || (i > 5)) return 0;
   
   if(a[i-1][j] == 0x11)
   {
      a[i][j]   = 0x11;
      a[i-1][j] = 0x00;
      i = i - 1;
      return 1;
   }
   
   if((a[i-1][j] == 0x12) && (j != 3) && (a[i-1][j+1] == 0x12) && (a[i][j+1] == 0x00))
   {
      a[i-1][j] = 0x00;   a[i-1][j+1] = 0x00;
      a[i][j]   = 0x12;   a[i][j+1]   = 0x12;
      i = i - 1;
      return 1;
   }
   
   if((a[i-1][j] == 0x21) && (i != 1) && (a[i-2][j] == 0x21))
   {
      a[i-2][j] = 0x00;
      a[i][j]   = 0x21;
      i = i - 2;
      return 1;
   }
   
   if(            (a[i-1][j] == 0x44) && (j != 3) && (a[i-1][j+1] == 0x44) && \
      (i != 1) && (a[i-2][j] == 0x44) &&             (a[i-2][j+1] == 0x44) && (a[i][j+1] == 0x00) )
   {
      a[i-2][j] = 0x00;   a[i-2][j+1] = 0x00;
      a[i][j]   = 0x44;   a[i][j+1]   = 0x44;
      i = i - 2;
      return 1;
   }
   
   return 0;
}

int mova_de_baixo_para_cima()
{
   if((i < 0) || (i > 3)) return 0;
   
   if(a[i+1][j] == 0x11)
   {
      a[i][j]   = 0x11;
      a[i+1][j] = 0x00;
      i = i + 1;
      return 1;
   }
   
   if((a[i+1][j] == 0x12) && (j != 3) && (a[i+1][j+1] == 0x12) && (a[i][j+1] == 0x00))
   {
      a[i][j]   = 0x12;   a[i][j+1]   = 0x12;
      a[i+1][j] = 0x00;   a[i+1][j+1] = 0x00;
      i = i + 1;
      return 1;
   }
   
   if((a[i+1][j] == 0x21) && (i != 3) && (a[i+2][j] == 0x21))
   {
      a[i][j]   = 0x21;
      a[i+2][j] = 0x00;
      i = i + 2;
      return 1;
   }
   
   if(            (a[i+1][j] == 0x44) && (j != 3) && (a[i+1][j+1] == 0x44) && (z == 1) && \
      (i != 3) && (a[i+2][j] == 0x44) &&             (a[i+2][j+1] == 0x44) && (a[i][j+1] == 0x00))
   {
      a[i][j]   = 0x44;   a[i][j+1]   = 0x44;
      a[i+2][j] = 0x00;   a[i+2][j+1] = 0x00;
      i = i + 2;
      return 1;
   }
   
   return 0;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

int encotre_a_posicao_de_0x00()
{
   int x, y, segundo = 0;
   
   for(x = 0; x < 5 ; x++)
   {
      for(y = 0; y < 4 ; y++)
      {
         if(a[x][y] == 0x00)
         {
            if(z == 1)
            {
               i = x;
               j = y;
               if(segundo)
                  z = 2;
               else
                  z = 1;
               return 0;
            }
            else
            {
               z = 1;
               segundo = 1;
               continue;
            }
         }
      }
   }
   
   return 1;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void quais_movimentos_podem_ocorrer()
{
   unsigned char mov_byte_temp = 0x00, mov_byte_temp2 = 0x00;
   int x;
   unsigned char *pont_estado;
   
   z = 1;
   
   for(x = 0; x < 2 ; x++)
   {
      encotre_a_posicao_de_0x00();
      
      mov_byte_temp = 0x00;
      
      if( mova_da_esquerda_para_direita() )
      {
         mov_byte_temp = mov_byte_temp | 0b10000000;  // armazena que o movimento pode ser feito
         mova_da_direita_para_esquerda();             // desfaz o movimento
      }
      
      if( mova_da_direita_para_esquerda() )
      {
         mov_byte_temp = mov_byte_temp | 0b01000000;
         mova_da_esquerda_para_direita();
      }
      
      if( mova_de_cima_para_baixo() )
      {
         mov_byte_temp = mov_byte_temp | 0b00100000;
         mova_de_baixo_para_cima();
      }
      
      if( mova_de_baixo_para_cima() )
      {
         mov_byte_temp = mov_byte_temp | 0b00010000;
         mova_de_cima_para_baixo();
      }
      
      if(x == 1) mov_byte_temp = mov_byte_temp >> 4;  // z = 2. Isso para o segundo espaço vazio
      
      mov_byte_temp2 = mov_byte_temp2 | mov_byte_temp;
      
      if(x == 0) z++;
   }
   
   pont_estado = (unsigned char *)estado[n_estado];
   
   pont_estado[20] = mov_byte_temp2;
   return ;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

int sugira_estado() // usa o mov_byte para sugerir um estado que vai gerar um galho no estado atual n_estado
{
   unsigned char     *pont_estado;
   unsigned long int *pont_galho;
   
   pont_estado   = (unsigned char *)estado[n_estado];
   pont_galho    = (unsigned long int *)&pont_estado[24];
   
   if((pont_estado[20] & (0b10000000 >> n_galho)) && ( pont_galho[n_galho] == 0xFFFFFFFF))
   {
      switch(n_galho)
      {
         case 0:
            z = 1;
            encotre_a_posicao_de_0x00();
            mova_da_esquerda_para_direita();
            return 1;
         case 1:
            z = 1;
            encotre_a_posicao_de_0x00();
            mova_da_direita_para_esquerda();
            return 1;
         case 2:
            z = 1;
            encotre_a_posicao_de_0x00();
            mova_de_cima_para_baixo();
            return 1;
         case 3:
            z = 1;
            encotre_a_posicao_de_0x00();
            mova_de_baixo_para_cima();
            return 1;
         case 4:
            z = 2;
            encotre_a_posicao_de_0x00();
            mova_da_esquerda_para_direita();
            return 1;
         case 5:
            z = 2;
            encotre_a_posicao_de_0x00();
            mova_da_direita_para_esquerda();
            return 1;
         case 6:
            z = 2;
            encotre_a_posicao_de_0x00();
            mova_de_cima_para_baixo();
            return 1;
         case 7:
            z = 2;
            encotre_a_posicao_de_0x00();
            mova_de_baixo_para_cima();
            return 1;
      } // Fim switch
   }
   
   return 0;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

int estado_sugerido_eh_novo()
{
   int x, y, k, diferente;
   unsigned char *pont_estado;
   
   n_igual = 0;
   
   if(n_total == 0) return 1;
   
   for(k=0; k < n_total; k++)
   {
      diferente = 0;
      pont_estado = (unsigned char *)estado[k];
      
      for(x=0; x<5 ; x++)
      {
         for(y=0; y<4 ; y++)
         {
            if(pont_estado[(4*x)+y] != a[x][y])
            {
               diferente = 1;
            }
         }
      }
      if(! diferente)
      {
         n_igual = k;
         return 0;
      }
   }
   
   return 1;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

void carrega_estado(int num) // usada para desfazer mudanças em a[5][4] e para voltar para estado do tronco quando não há mais galhos a explorar
{
   int x, y;
   unsigned char *pont_estado;
   
   pont_estado = (unsigned char *)estado[num];
   
   for(x=0; x<5 ; x++)
   {
      for(y=0; y<4 ; y++)
      {
         a[x][y] = pont_estado[(4*x)+y];
      }
   }
   //imprime_estado_sugerido();
   return;
}

