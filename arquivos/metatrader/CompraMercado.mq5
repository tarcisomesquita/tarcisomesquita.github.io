#include <Trade\Trade.mqh>
CTrade trade;

void OnStart() {
  string ativo = "CSAN3";
  double volume = 100.0;
   
  Print("Enviando ordem de compra a mercado de ", volume, " ações de ", ativo);
  
  if (trade.Buy(volume, ativo)) Print("Ordem executada com sucesso! Ticket: ", trade.ResultOrder());
  else                          Print("Falha ao enviar a ordem. Erro: ", trade.ResultRetcodeDescription());
}
