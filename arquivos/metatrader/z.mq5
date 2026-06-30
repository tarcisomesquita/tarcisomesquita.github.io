#include <Trade\Trade.mqh> // Inclui a biblioteca nativa de negociação do MT5
CTrade trade;              // Cria o objeto "trade" para gerenciar as ordens

//--- Variáveis Globais (Mantidas dos exemplos anteriores)
double ema_ticks_atual = 0.0;    
double peso_k = 0.0;             
bool   ema_inicializada = false; 

//--- Configurações do Robô
#define VOLUME_URGENTE 5000     
#define DESLOCAMENTO   0.01     
#define ALVO_LUCRO     0.02     // Alvo fixo de 2 centavos de lucro
#define TEMPO_MAXIMO_ESPERA 5000 // Tempo máximo na fila em milissegundos (5 segundos)

//--- Variáveis de Controle de Tempo de Fila
ulong  horario_envio_ordem = 0;  // Guarda o momento em que a ordem entrou na fila

//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
{
   peso_k = 2.0 / (50.0 + 1.0);
   ema_inicializada = false;
   horario_envio_ordem = 0;
   
   // Define o ID mágico do robô para ele não mexer em ordens de outros robôs ou ordens manuais
   trade.SetExpertMagicNumber(123456); 

   return(INIT_SUCCEEDED);
}

//+------------------------------------------------------------------+
//| Expert tick function                                             |
//+------------------------------------------------------------------+
void OnTick()
{
   // --- CENÁRIO 1: VERIFICA SE A ORDEM FICOU PARA TRÁS NA FILA (TIMEOUT) ---
   if(OrdersTotal() > 0)
   {
      ulong tempo_atual = GetMicrosecondCount() / 1000; // Tempo atual em milissegundos
      
      if(tempo_atual - horario_envio_ordem > TEMPO_MAXIMO_ESPERA)
      {
         Comment("Ordem ficou para trás na fila! Cancelando por tempo limite...");
         
         // Como temos apenas 1 ordem por vez, varremos a lista para cancelá-la
         for(int i = OrdersTotal() - 1; i >= 0; i--)
         {
            ulong ticket_ordem = OrderGetTicket(i);
            if(OrderGetInteger(ORDER_MAGIC) == 123456) // Garante que é a ordem deste robô
            {
               trade.OrderDelete(ticket_ordem); // Deleta a ordem pendente da fila da B3
            }
         }
         horario_envio_ordem = 0; // Zera o cronômetro
      }
      return; // Bloqueia o robô enquanto a ordem estiver na fila dentro do tempo aceitável
   }

   // Se o robô já conseguiu ser executado e está posicionado, aguarda o Take Profit de 2 centavos ser batido
   if(PositionsTotal() > 0)
   {
      Comment("Robô posicionado. Aguardando saída de 2 centavos...");
      horario_envio_ordem = 0; // Garante o reset do cronômetro da fila
      return; 
   }

   // --- CAPTURA E FILTRO DOS TICKS (Mantidos do exemplo anterior) ---
   MqlTick array_negocios[];
   int copiado = CopyTicks(_Symbol, array_negocios, COPY_TICKS_ALL, 0, 2);
   if(copiado < 2) return;

   MqlTick tick_atual = array_negocios[1];
   bool foi_negocio_real = (tick_atual.flags & TICK_FLAG_LAST) != 0;
   if(!foi_negocio_real) return;

   double preco_ultimo_negocio = tick_atual.last;
   long   volume_ultimo_negocio = tick_atual.real_volume;

   // Cálculo da EMA
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

   // --- ENVIOS DAS ORDENS COM TAKE PROFIT EMBUTIDO (SAÍDA DE 2 CENTAVOS) ---
   double preco_limite = 0.0;

   // SINAL DE COMPRA
   if(preco_ultimo_negocio > ema_ticks_atual)
   {
      preco_limite = tick_atual.bid; 
      if(volume_ultimo_negocio >= VOLUME_URGENTE) preco_limite += DESLOCAMENTO; 

      // Alvo de lucro: Preço de entrada + 2 centavos (ALVO_LUCRO)
      double take_profit = preco_limite + ALVO_LUCRO;

      // Executa a compra Limit. Parâmetros: Volume (100 ações), Ativo, Preço, StopLoss (0.0), TakeProfit
      if(trade.BuyLimit(100, _Symbol, preco_limite, 0.0, take_profit))
      {
         // Se a ordem foi enviada com sucesso para a fila, iniciamos o cronômetro
         horario_envio_ordem = GetMicrosecondCount() / 1000;
         Comment("Ordem de COMPRA colocada na fila a R$ ", DoubleToString(preco_limite, 2));
      }
   }
   
   // SINAL DE VENDA
   else if(preco_ultimo_negocio < ema_ticks_atual)
   {
      preco_limite = tick_atual.ask;
      if(volume_ultimo_negocio >= VOLUME_URGENTE) preco_limite -= DESLOCAMENTO;

      // Alvo de lucro para venda: Preço de entrada - 2 centavos
      double take_profit = preco_limite - ALVO_LUCRO;

      // Executa a venda Limit
      if(trade.SellLimit(100, _Symbol, preco_limite, 0.0, take_profit))
      {
         horario_envio_ordem = GetMicrosecondCount() / 1000;
         Comment("Ordem de VENDA colocada na fila a R$ ", DoubleToString(preco_limite, 2));
      }
   }
}
