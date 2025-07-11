rewind()
Reinicia o arquivo, equivale ao Reset do Pascal, ou seja apenas movimenta o ponteiro do arquivo para seu início.


void rewind(FILE *arquivo)
  	Posiciona o ponteiro no inicio do arquivo.É identico a fseek(arquivo,0L,SEEK_SET).
