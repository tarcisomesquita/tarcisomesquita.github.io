#include <Trade\Trade.mqh>
CTrade trade;

void OnStart() {
  string ativo = "CSAN3";
  double preco = 3.68;
  double volume = 100.0;
  
  Print("Comprando ", volume, " ações de ", meuAtivo, " a R$ ", preco);
  
  if (trade.BuyLimit(volume, precoCompra, meuAtivo)) {
    Print("Ordem enviada com sucesso! Ticket: ", trade.ResultOrder());
  }
  else {
    Print("Falha ao enviar a ordem. Erro: ", trade.ResultRetcodeDescription());
  }
}
