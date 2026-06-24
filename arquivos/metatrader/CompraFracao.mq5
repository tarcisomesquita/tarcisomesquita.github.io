#include <Trade\Trade.mqh>
CTrade trade;

void OnStart() {
  string ativo = "CSAN3F";
  double preco = 3.68;
  double volume = 1.0;
  
  Print("Comprando ", volume, " ações de ", ativo, " a R$ ", preco);
  
  if (trade.BuyLimit(volume, preco, ativo)) Print("Ordem enviada com sucesso! Ticket: ", trade.ResultOrder());
  else                                      Print("Falha ao enviar a ordem. Erro: ", trade.ResultRetcodeDescription());
}
