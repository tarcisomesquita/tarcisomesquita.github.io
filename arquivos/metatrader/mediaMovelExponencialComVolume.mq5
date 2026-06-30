// handles e arrays
int handle_ema;
int handle_vol_medio; // Média do volume real
double array_ema[];
double array_fechamento[];
double array_volume_real[]; // Guarda o volume real do candle

int OnInit() {
   // EMA de 5 períodos para ser rápida
   handle_ema = iMA(_Symbol, PERIOD_M1, 5, 0, MODE_EMA, PRICE_CLOSE);
   
   // Alinha os arrays como séries temporais
   ArraySetAsSeries(array_ema, true);
   ArraySetAsSeries(array_fechamento, true);
   return(INIT_SUCCEEDED);
}

void OnTick() {
   // Copia dados do preço e da média
   if(CopyBuffer(handle_ema, 0, 0, 2, array_ema) < 0) return;
   if(CopyClose(_Symbol, PERIOD_M1, 0, 2, array_fechamento) < 0) return;
   
   // Captura o VOLUME REAL do último candle fechado (índice 1)
   long volume_ultimo_periodo = MqlRates rates[];
   if(CopyRates(_Symbol, PERIOD_M1, 1, 1, rates) < 0) return;
   long vol_real = rates[0].real_volume;

   // DECISÃO COM FILTRO DE VOLUME
   // Digamos que você só quer operar se o volume no último período foi maior que 50.000 ações
   bool volume_valido = (vol_real > 50000); 
   
   if(array_fechamento[1] > array_ema[1] && volume_valido) {
      Comment("Preço acima da EMA com VOLUME ALTO (", vol_real, " ações). Sinal de COMPRA válido!");
      // Executa ordem LIMIT
   }
}
