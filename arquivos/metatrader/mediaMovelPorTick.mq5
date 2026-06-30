//--- Variáveis Globais para o Cálculo da EMA
double ema_ticks_atual = 0.0;    // Guarda o valor atual da Média Móvel
double peso_k = 0.0;             // Multiplicador de peso (K) da fórmula
bool   ema_inicializada = false; // Flag para garantir que acumulamos os primeiros 50 ticks

//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
{
   // Calcula o peso K para 50 períodos (fórmula: 2 / (N + 1))
   // Para 50 ticks, K = 2 / 51 = ~0.0392 (Cada novo tick tem ~3.9% de peso na média)
   peso_k = 2.0 / (50.0 + 1.0);
   
   ema_ticks_atual = 0.0;
   ema_inicializada = false;

   return(INIT_SUCCEEDED);
}

//+------------------------------------------------------------------+
//| Expert tick function                                             |
//+------------------------------------------------------------------+
void OnTick()
{
   MqlTick array_negocios[];
   
   // Captura os últimos 2 ticks para saber se houve um novo negócio real
   int copiado = CopyTicks(_Symbol, array_negocios, COPY_TICKS_ALL, 0, 2);
   if(copiado < 2) return;

   // Indexadores do CopyTicks: índice 1 é o tick atual (agora), índice 0 é o tick anterior
   MqlTick tick_atual = array_negocios[1];
   
   // FILTRO CRÍTICO: Só calcula se o tick atual foi um NEGÓCIO REAL executado na B3
   bool foi_negocio_real = (tick_atual.flags & TICK_FLAG_LAST) != 0;
   if(!foi_negocio_real) return;

   double preco_ultimo_negocio = tick_atual.last;

   //--- PASSO 1: Inicialização da Média (Primeira rodada do robô)
   if(!ema_inicializada)
   {
      // Para iniciar a EMA, precisamos de uma base. Vamos puxar os últimos 50 ticks de uma vez
      MqlTick historico_ticks[];
      int total_historico = CopyTicks(_Symbol, historico_ticks, COPY_TICKS_ALL, 0, 50);
      
      if(total_historico >= 50)
      {
         double soma_precos = 0;
         for(int i=0; i<50; i++)
         {
            soma_precos += historico_ticks[i].last;
         }
         // A primeira EMA começa como uma média simples dos últimos 50 negócios
         ema_ticks_atual = soma_precos / 50.0;
         ema_inicializada = true;
         Print("EMA de 50 Ticks inicializada com sucesso em: ", ema_ticks_atual);
      }
      return; // Sai da função para esperar o próximo tick e iniciar a fórmula exponencial
   }

   //--- PASSO 2: Cálculo Exponencial a cada novo negócio (Fórmula Matemática)
   // EMA_atual = (Preço_Último_Negócio * K) + (EMA_anterior * (1 - K))
   ema_ticks_atual = (preco_ultimo_negocio * peso_k) + (ema_ticks_atual * (1.0 - peso_k));

   //--- PASSO 3: Tomada de Decisão para o Scalper
   // O valor da EMA de ticks agora está atualizado e pronto para comparação
   
   if(preco_ultimo_negocio > ema_ticks_atual)
   {
      Comment("TENDÊNCIA DE ALTA (FLUXO)\n",
              "Preço do Negócio: ", DoubleToString(preco_ultimo_negocio, 2), "\n",
              "EMA 50 Ticks: ", DoubleToString(ema_ticks_atual, 4), "\n",
              "Volume do Negócio: ", tick_atual.real_volume, " ações.");
              
      // Insira aqui sua lógica de compra com ordem LIMIT
   }
   else if(preco_ultimo_negocio < ema_ticks_atual)
   {
      Comment("TENDÊNCIA DE BAIXA (FLUXO)\n",
              "Preço do Negócio: ", DoubleToString(preco_ultimo_negocio, 2), "\n",
              "EMA 50 Ticks: ", DoubleToString(ema_ticks_atual, 4), "\n",
              "Volume do Negócio: ", tick_atual.real_volume, " ações.");
              
      // Insira aqui sua lógica de venda com ordem LIMIT
   }
}
