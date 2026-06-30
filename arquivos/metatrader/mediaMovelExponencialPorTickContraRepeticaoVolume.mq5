//--- Variáveis Globais (Mantidas dos exemplos anteriores)
double ema_ticks_atual = 0.0;    
double peso_k = 0.0;             
bool   ema_inicializada = false; 

//--- Configuração do Filtro de Volume e Ajuste
#define VOLUME_URGENTE 5000     // Volume (em ações) considerado forte na B3
#define DESLOCAMENTO   0.01     // Ajuste de 1 centavo no preço se houver urgência

//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
{
   peso_k = 2.0 / (50.0 + 1.0);
   ema_inicializada = false;
   return(INIT_SUCCEEDED);
}

//+------------------------------------------------------------------+
//| Expert tick function                                             |
//+------------------------------------------------------------------+
void OnTick()
{
   // --- TRAVAS DE SEGURANÇA CONTRA ORDENS DUPLICADAS ---
   if(OrdersTotal() > 0 || PositionsTotal() > 0) return; 

   // --- CAPTURA E FILTRO DOS TICKS ---
   MqlTick array_negocios[];
   int copiado = CopyTicks(_Symbol, array_negocios, COPY_TICKS_ALL, 0, 2);
   if(copiado < 2) return;

   MqlTick tick_atual = array_negocios[1];
   bool foi_negocio_real = (tick_atual.flags & TICK_FLAG_LAST) != 0;
   if(!foi_negocio_real) return;

   double preco_ultimo_negocio = tick_atual.last;
   long   volume_ultimo_negocio = tick_atual.real_volume; // Volume real negociado

   // --- CÁLCULO DA EMA DE TICKS ---
   if(!ema_inicializada)
   {
      MqlTick historico_ticks[];
      int total_historico = CopyTicks(_Symbol, historico_ticks, COPY_TICKS_ALL, 0, 50);
      if(total_historico >= 50)
      {
         double soma_precos = 0;
         for(int i=0; i<50; i++) soma_precos += historico_ticks[i].last;
         ema_ticks_atual = soma_precos / 50.0;
         ema_inicializada = true;
      }
      return; 
   }

   ema_ticks_atual = (preco_ultimo_negocio * peso_k) + (ema_ticks_atual * (1.0 - peso_k));

   // --- LÓGICA DE PRECIFICAÇÃO DINÂMICA POR VOLUME ---
   double preco_compra_limit = 0.0;
   double preco_venda_limit  = 0.0;

   // Se o preço cruzar acima da média (Sinal de Compra)
   if(preco_ultimo_negocio > ema_ticks_atual)
   {
      // Passo A: Identificar o preço ideal passivo (Topo do livro de COMPRA para entrar na fila)
      preco_compra_limit = tick_atual.bid; 
      
      // Passo B: Se o volume do negócio foi muito alto, ajustamos o preço com urgência
      if(volume_ultimo_negocio >= VOLUME_URGENTE)
      {
         // Pagamos 1 centavo a mais para "furar a fila" ou garantir contra a agressão dos vendedores
         preco_compra_limit = preco_compra_limit + DESLOCAMENTO; 
         
         Comment("COMPRA URGENTE! Volume alto detected: ", volume_ultimo_negocio, " ações.\n",
                 "Ordem LIMIT ajustada para cima: R$ ", DoubleToString(preco_compra_limit, 2));
      }
      else
      {
         Comment("Compra padrão na fila. Volume normal: ", volume_ultimo_negocio, " ações.\n",
                 "Ordem LIMIT no preço passivo: R$ ", DoubleToString(preco_compra_limit, 2));
      }

      // TODO: Chamar a função de envio real de MqlTradeRequest usando 'preco_compra_limit'
   }
   
   // Se o preço cruzar abaixo da média (Sinal de Venda)
   else if(preco_ultimo_negocio < ema_ticks_atual)
   {
      // Passo A: Identificar o preço ideal passivo (Topo do livro de VENDA)
      preco_venda_limit = tick_atual.ask;
      
      // Passo B: Se o volume do negócio foi muito alto, ajustamos o preço com urgência
      if(volume_ultimo_negocio >= VOLUME_URGENTE)
      {
         // Vendemos 1 centavo mais barato para garantir a execução rápida antes que o preço desabe
         preco_venda_limit = preco_venda_limit - DESLOCAMENTO;
         
         Comment("VENDA URGENTE! Volume alto detectado: ", volume_ultimo_negocio, " ações.\n",
                 "Ordem LIMIT ajustada para baixo: R$ ", DoubleToString(preco_venda_limit, 2));
      }
      else
      {
         Comment("Venda padrão na fila. Volume normal: ", volume_ultimo_negocio, " ações.\n",
                 "Ordem LIMIT no preço passivo: R$ ", DoubleToString(preco_venda_limit, 2));
      }

      // TODO: Chamar a função de envio real de MqlTradeRequest usando 'preco_venda_limit'
   }
}
