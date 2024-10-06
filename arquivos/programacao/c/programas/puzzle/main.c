
// clear ; gcc -Wall main.c -o puzzle.elf && ./puzzle.elf

#include<stdlib.h>
#include<stdio.h>

int debug = 0;

#include "0_estado_das_pecas.c"
#include "1_funcoes_para_impressao.c"
#include "2_funcoes_para_estado_novo.c"
#include "3_funcoes_para_encontrar_estado.c"

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

int main()
{
   int y, x = 0, solucao = 0, l_galho = 0, l_galho_old = 0;
   unsigned char *pont_estado;
   unsigned long int *pont_galho;
   
   escreva_estado_novo_na_arvore();
   linha_atual = realloc(linha_atual, sizeof(int));
   linha_atual[0] = n_total - 1;
   
   for(;;)
   {
      n_estado = linha_atual[x];
      pont_estado = (unsigned char *)estado[n_estado];
      pont_galho = (unsigned long int *)&pont_estado[24];
      //if(n_estado == 0x32) {printf("CHEGUEI NO PONTO\n"); imprima_todos_os_estados(); return 1;}
      
      carrega_estado(n_estado);
      quais_movimentos_podem_ocorrer();
      if(debug) {printf("\n\nestado[%08X]", n_estado); imprima_o_estado(n_estado); }
      
      if(debug) {printf("\n");}
      for(n_galho=0; n_galho < 8; n_galho++)
      {
         if(! sugira_estado()) continue;
         //printf("Estado sugerido:"); imprima_o_estado_sugerido();
         if(debug)
         {
            if( (pont_estado[20] & (0b10000000 >> n_galho)) )
            {
               switch(n_galho)
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
         }
         
         if(estado_sugerido_eh_novo())
         {
            if(debug) {printf("ACEITO\n");}
            if(escreva_estado_novo_na_arvore()) solucao = 1;
            
            linha_galhos = realloc(linha_galhos, (l_galho + 1)*sizeof(int));
            linha_galhos[l_galho] = n_total - 1;
            pont_galho[n_galho] = n_total - 1;
            
            l_galho++;
         }
         else
         {
            if(debug) {printf("RECUSADO\n");}
            
            pont_galho[n_galho] = n_igual;
         }
         
         if(solucao)
         {
            n_estado = n_total - 1;
            printf("Encontrei uma solução com %d passos.", quantos_movimentos_usei_para_chegar_no_estado(n_estado));
            imprima_os_estados_do_tronco_do_estado_atual();
            free(linha_atual);
            free(linha_galhos);
            for(y=0; y<n_total; y++) free(estado[y]);
            free(estado);
            return 0; // chame rotina para imprima a resposta, liberar a memória
         }
         
         carrega_estado(linha_atual[x]);
      }
      if(debug) {printf("\n");}
      
      // AQUI DEVE SE COLOCAR NO ESTADO NA LINHA E COLUNA CERTA
      
      if(x == l_galho_old)
      {
         free(linha_atual);
         linha_atual = linha_galhos;
         linha_galhos = 0x00000000;
         l_galho_old = l_galho-1;
         //for(y=0 ; y <= l_galho_old; y++) printf("[%08X]", linha_atual[y]); printf("\n");
         l_galho = 0;
         x = 0;
         
         quanto_de_memoria();
      }
      else
      {
         x++;
      }
   }
   
   return 0;
}

