//--- Variáveis globais
int handle_media;             // Guarda o identificador do indicador
double array_media[];         // Array para armazenar os valores da média móvel
double array_fechamento[];    // Array para armazenar os valores de fechamento dos candles

//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
{
   // 1. Cria o handle da Média Móvel (Ativo atual, Tempo gráfico atual, Período 20, Deslocamento 0, Modo Simples, Aplicado ao Fechamento)
   handle_media = iMA(_Symbol, _Period, 20, 0, MODE_SMA, PRICE_CLOSE);
   
   if(handle_media == INVALID_HANDLE)
   {
      Print("Erro ao criar o handle do indicador.");
      return(INIT_FAILED);
   }

   // Define os arrays como séries temporais (o índice [0] vira o candle atual em formação)
   ArraySetAsSeries(array_media, true);
   ArraySetAsSeries(array_fechamento, true);

   return(INIT_SUCCEEDED);
}

//+------------------------------------------------------------------+
//| Expert tick function                                             |
//+------------------------------------------------------------------+
void OnTick()
{
   // 2. Copia os dados mais recentes do indicador e do preço para os arrays (últimos 3 candles)
   if(CopyBuffer(handle_media, 0, 0, 3, array_media) < 0) return;
   if(CopyClose(_Symbol, _Period, 0, 3, array_fechamento) < 0) return;

   // 3. Leitura dos dados para tomada de decisão
   // Índice [0] = candle atual (em variação). Índice [1] = candle fechado anterior.
   double preco_atual = array_fechamento[0];
   double media_atual = array_media[0];
   
   // Exemplo lógico simples:
   if(preco_atual > media_atual)
   {
      // Substitua pelo seu código de envio de ordem de COMPRA que você já testou
      Comment("Preço acima da média. Sinal de COMPRA. Média: ", media_atual);
   }
   else if(preco_atual < media_atual)
   {
      // Substitua pelo seu código de envio de ordem de VENDA que você já testou
      Comment("Preço abaixo da média. Sinal de VENDA. Média: ", media_atual);
   }
}

//+------------------------------------------------------------------+
//| Expert deinitialization function                                 |
//+------------------------------------------------------------------+
void OnDeinit(const int reason)
{
   // Libera a memória do indicador ao desativar o robô
   IndicatorRelease(handle_media);
}
