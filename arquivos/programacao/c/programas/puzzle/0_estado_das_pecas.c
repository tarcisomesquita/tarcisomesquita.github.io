
// peças:
// 0x00      é um espaço vazio
// 0x11      é uma peça que ocupa um casa
// 0x12 0x12 é uma peça que ocupa duas casas horizontais
// 0x21      é uma peça que ocupa duas casas verticais
// 0x21      
// 0x33      é uma peça fixa
// 0x44 0x44 é uma peça que ocupa quatro casas
// 0x44 0x44 


// = = = = = = = = = = = estado das peças do quebra-cabeça = = = = = = = = = = 

/*
//teste
unsigned char a[5][4] = {{0x00, 0x11, 0x11, 0x11} ,\
                         {0x11, 0x44, 0x44, 0x00} ,\
                         {0x11, 0x44, 0x44, 0x11} ,\
                         {0x11, 0x33, 0x33, 0x11} ,\
                         {0x33, 0x33, 0x33, 0x33}};
*/

/*
//Charoite (Eu consigo resolver em 27 passos)
unsigned char a[5][4] = {{0x11, 0x00, 0x00, 0x11} ,\
                         {0x11, 0x11, 0x11, 0x11} ,\
                         {0x11, 0x11, 0x11, 0x11} ,\
                         {0x11, 0x44, 0x44, 0x11} ,\
                         {0x11, 0x44, 0x44, 0x11}};
*/

/*
//Épidote
unsigned char a[5][4] = {{0x11, 0x00, 0x00, 0x11} ,\
                         {0x11, 0x11, 0x11, 0x11} ,\
                         {0x11, 0x11, 0x11, 0x11} ,\
                         {0x21, 0x44, 0x44, 0x21} ,\
                         {0x21, 0x44, 0x44, 0x21}};
*/

/*
//Pyrite
unsigned char a[5][4] = {{0x11, 0x00, 0x00, 0x11} ,\
                         {0x11, 0x11, 0x11, 0x11} ,\
                         {0x11, 0x12, 0x12, 0x11} ,\
                         {0x21, 0x44, 0x44, 0x21} ,\
                         {0x21, 0x44, 0x44, 0x21}};
*/


//Sulphur
unsigned char a[5][4] = {{0x00, 0x12, 0x12, 0x00} ,\
                         {0x11, 0x12, 0x12, 0x11} ,\
                         {0x11, 0x12, 0x12, 0x11} ,\
                         {0x21, 0x44, 0x44, 0x21} ,\
                         {0x21, 0x44, 0x44, 0x21}};



// = = = = = = = = estrutura para armazenar uma árvore de dados sobre estados  

struct posicao_peca
{
   unsigned char p11, p12, p13, p14;
   unsigned char p21, p22, p23, p24;
   unsigned char p31, p32, p33, p34;
   unsigned char p41, p42, p43, p44;
   unsigned char p51, p52, p53, p54;
};

struct estado_galho
{
   unsigned long int g1, g2, g3, g4, g5, g6, g7, g8;
};

struct arvore
{
   struct posicao_peca pecas;                   // posição das peças no estado atual
   unsigned char mov_byte, nulo1, nulo2, nulo3; // os 8 bits de mov_byte representam os movimentos possíveis. Os nulos são apenas para alinhar a memória
   struct estado_galho galho;                   // números dos estados que formam galho a partir do atual 
   unsigned long int tronco;                    // número do estado anterior ao estado atual (o de menor número de passos)
}; // um estado armazenado na árvore ocupa 60 bytes da memória

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

struct arvore **estado = 0x00000000;   // a memória para cada estado será alocada de forma dinâmica
int *linha_atual = 0x00000000;
int *linha_galhos = 0x00000000;

int i = 0, j = 0;  // coordenadas de 0x00 (o espaço vazio)
int z = 0;         // z = 1 se i e j são as coordenadas do primeiro espaço vazio. z = 2 para as coodenadas do segundo
int n_estado = 0;  // número do estado atual
int n_total  = 0;  // número total de estado armazenados na árvore de dados
int n_galho  = 0;  // número do galho atual. Uma peça (a 0x11) pode fazer até 8 movimentos, portanto o estado atual pode gerar oito galhos de estados
int n_igual  = 0;  // número do estado na árvore que é igual ao estado que foi sugerido pela função sugere_estado()
int atualizei = 0; // variável de controle usada para atualizar o tronco de galhos quando se encontra dois estados iguais
unsigned long int memoria_usada = 0;

