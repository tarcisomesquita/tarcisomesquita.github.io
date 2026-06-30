//--- Handles dos Indicadores
int handle_rapida;
int handle_lenta;

//--- Arrays para armazenar os valores das médias
double ema_rapida[];
double ema_lenta[];

//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
{
   // Cria as duas Médias Móveis Exponenciais (MODE_EMA)
   handle_rapida = iMA(_Symbol, PERIOD_M1, 9,  0, MODE_EMA, PRICE_CLOSE);
   handle_lenta  = iMA(_Symbol, PERIOD_M1, 21, 0, MODE_EMA, PRICE_CLOSE);
   
   if(handle_rapida == INVALID_HANDLE || handle_lenta == INVALID_HANDLE)
   {
      Print("Erro ao inicializar os indicadores.");
      return(INIT_FAILED);
   }

   // Alinha os arrays com a ordem cronológica do gráfico (Índice 0 = candle atual)
   ArraySetAsSeries(ema_rapida, true);
   ArraySetAsSeries(ema_lenta, true);

   return(INIT_SUCCEEDED);
}

//+------------------------------------------------------------------+
//| Expert tick function                                             |
//+------------------------------------------------------------------+
void OnTick()
{
   // Copia os dados das duas médias (precisamos do candle 1 fechado e do candle 2)
   if(CopyBuffer(handle_rapida, 0, 0, 3, ema_rapida) < 0) return;
   if(CopyBuffer(handle_lenta,  0, 0, 3, ema_lenta) < 0) return;

   // LÓGICA DE CRUZAMENTO (Evita o candle 0 para não operar com o preço oscilando)
   // Candle 1 = Último minuto que acabou de fechar
   // Candle 2 = O minuto anterior ao candle 1
   
   bool cruzou_para_cima = (ema_rapida[1] > ema_lenta[1]) && (ema_rapida[2] <= ema_lenta[2]);
   bool cruzou_para_baixo = (ema_rapida[1] < ema_lenta[1]) && (ema_rapida[2] >= ema_lenta[2]);

   // Tomada de Decisão
   if(cruzou_para_cima)
   {
      Comment("Sinal de COMPRA DETECTADO no fechamento do minuto anterior!");
      // Insira sua função de envio de ORDEM DE COMPRA aqui
   }
   else if(cruzou_para_baixo)
   {
      Comment("Sinal de VENDA DETECTADO no fechamento do minuto anterior!");
      // Insira sua função de envio de ORDEM DE VENDA aqui
   }
}

//+------------------------------------------------------------------+
//| Expert deinitialization function                                 |
//+------------------------------------------------------------------+
void OnDeinit(const int reason)
{
   IndicatorRelease(handle_rapida);
   IndicatorRelease(handle_lenta);
}
