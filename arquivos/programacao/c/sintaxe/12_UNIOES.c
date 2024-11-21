
/*
UNIÕES

Armazena duas ou mais variáveis na mesma posição de memória, podendo ser de tipo e tamanhos diferentes.
O tamanho total de uma union é igual ao tamanho do maior de seus itens.
O tipo recuperado deve ser o mais recentemente armazenado.

Sintaxe:
union etiqueta_da_union {
  tipo var_1;
  tipo var_2;
  tipo var_n;
} variavel_da_union;

*/

extern int printf(char *, ...);

union longchar {
  long numl;
  unsigned char numc[4];
};

int main() {
  union longchar lc;
  register int i;
  
  lc.numl = 0x01020304;
  for (i=0; i<4; i++) printf("0x%02X\n", lc.numc[i]);
  
  return 0;
}
