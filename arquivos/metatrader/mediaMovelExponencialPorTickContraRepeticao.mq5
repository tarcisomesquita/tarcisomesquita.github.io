//--- Variáveis Globais para o Cálculo da EMA (mantidas do código anterior)
double ego_ticks_atual = 0.0;    
double peso_k = 0.0;             
bool   ema_inicializada = false; 

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
   // --- TRAVA DE SEGURANÇA EXIGIDA ---
   // 1. Verifica se existem ordens PENDENTES na fila (enviadas, mas não executadas)
   if(OrdersTotal() > 0) 
   {
      Comment("Aguardando execução da ordem já enviada na fila do livro...");
      return; // Bloqueia o robô. Não calcula nada e não envia novas ordens.
   }

   // 2. Verifica se o robô já está POSICIONADO (comprado ou vendido após a ordem ser executada)
   if(PositionsTotal() > 0)
   {
      Comment("Robô já está posicionado em uma operação. Aguardando encerramento...");
      return; // Bloqueia o robô. Evita piramidar ou abrir ordens simultâneas.
   }

   // --- CÁLCULO DO FLUXO (Executado apenas se as travas acima forem falsas)
   MqlTick array_negocios[];
   int copiado = CopyTicks(_Symbol, array_negocios, COPY_TICKS_ALL, 0, 2);
   if(copiado < 2) return;

   MqlTick tick_atual = array_negocios[1];
   bool foi_negocio_real = (tick_atual.flags & TICK_FLAG_LAST) != 0;
   if(!foi_negocio_real) return;

   double preco_ultimo_negocio = tick_atual.last;

   // Inicialização da Média (Idêntica ao código anterior)
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

   // Cálculo Exponencial
   ema_ticks_atual = (preco_ultimo_negocio * peso_k) + (ema_ticks_atual * (1.0 - peso_k));

   // --- ENVIO CRÍTICO DE ORDENS ---
   if(preco_ultimo_negocio > ema_ticks_atual)
   {
      Comment("Sinal de COMPRA. Enviando ordem LIMIT única para a fila...");
      
      // Aqui entrará a sua estrutura MqlTradeRequest para COMPRA LIMIT
      // Assim que essa linha rodar, OrdersTotal() passará a ser 1 no próximo tick,
      // travando o robô automaticamente até a ordem ser preenchida ou cancelada.
   }
   else if(preco_ultimo_negocio < ema_ticks_atual)
   {
      Comment("Sinal de VENDA. Enviando ordem LIMIT única para a fila...");
      
      // Aqui entrará a sua estrutura MqlTradeRequest para VENDA LIMIT
   }
}
