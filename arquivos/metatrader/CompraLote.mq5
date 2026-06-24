#include <Trade\Trade.mqh>
CTrade trade;

void OnStart() {
  string meuAtivo = "CSAN3";       // Lote padrão (B3 exige múltiplos de 100)
  double precoCompra = 3.68;       // Preço desejado
  double volume = 100.0;           // 100 ações = 1 lote padrão da B3
  
  Print("Tentando comprar 1 lote (100 ações) de ", meuAtivo, " a R$ ", precoCompra);
  
  if (trade.BuyLimit(volume, precoCompra, meuAtivo)) {
    Print("Ordem de lote padrão enviada com sucesso! Ticket: ", trade.ResultOrder());
  }
  else {
    Print("Falha ao enviar a ordem. Erro: ", trade.ResultRetcodeDescription());
  }
}
