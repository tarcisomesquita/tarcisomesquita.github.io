
// clear ; gcc -Wall servidor.c -o servidor.elf && ./servidor.elf ; echo $?

// #include <sys/socket.h>
struct sockaddr {
   unsigned short int sa_family;
   char sa_data[14];
};

// Structure describing an Internet socket address.
struct sockaddr_in {
   unsigned short int familia; 
   unsigned short int porta;     // Port number.
   unsigned long int  ip;       // Internet address.
   
   // Pad to size of struct sockaddr
   unsigned char sin_zero[sizeof(struct sockaddr) - \
   (sizeof(unsigned short int)) - \
   sizeof(unsigned short int) -   \
   sizeof(unsigned long int)];
};

// #include <sys/socket.h> // = = = = = = = = = = = = = = = = = = = = = =

// #include <stdio.h>
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout, *stderr; 
extern int fprintf(FILE *stream, const char *formatted_output, ...);
extern void perror(const char *s);
extern int sprintf(char *s, const char *format, ...);
extern int fgetc(FILE *arquivo);
extern long unsigned int fread(void *buffer, long unsigned int size, long unsigned int n, FILE *arquivo);
extern FILE *fopen(char *nome_do_arquivo, char *modo_de_abertura);
extern void rewind(FILE *arquivo);
extern int fclose(FILE *ponteiro_para_o_arquivo);


// #include <sys/socket.h>
extern int socket(int domain, int type, int protocol);
extern int setsockopt(int sock, int level, int optname, const void *optval, unsigned int optlen);
extern int bind(int sock, struct sockaddr_in *addr, int len_len);
extern int listen(int sock, int n);
extern int accept(int sock, struct sockaddr_in *addr, int *addr_len);
extern int send(int conexao, const void *buf, unsigned long int n, int flags);

#define PF_INET  2       // DOMAIN IPv4
#define AF_INET  PF_INET // DOMAIN IPv4

enum socket_type {
   SOCK_STREAM = 1  // TYPE TCP: Sequenced, reliable, connection-based byte streams.  
};

// #include <netinet/in.h>
enum {
   IPPROTO_TCP = 6  // PROTOCOL TCP
};


// #include <asm-generic/socket.h>
#define SOL_SOCKET 1
#define SO_REUSEADDR 2


// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int hostshort);


// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *cp);


// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int read(int fd, void *buf, unsigned long int nbytes);
extern int close(int fd);


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern unsigned int strlen(char *str);


//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int atoi(const char *);
extern void *malloc(long unsigned int size);
extern void free(void *ptr);

// input: sbyte, contendo as duas letras do byte
// output: byte, contendo o byte
// return 1 para erro, 0 para ok
int _read_hex_byte(unsigned char *sbyte, unsigned char *byte) {
   unsigned char i;
   
   for (i=0; i<2; i++) {
      if      (sbyte[i] >= 0x30 && sbyte[i] <= 0x39 ) continue; // 0-9
      else if (sbyte[i] >= 0x41 && sbyte[i] <= 0x46 ) continue; // A-F
      else if (sbyte[i] >= 0x61 && sbyte[i] <= 0x66 ) continue; // a-f
      else {
         fprintf(stdout, "\nERRO: Encontrei uma letra que não pertence ao alfabeto hexadecimal.\n\n");
         return 1;
      }
   }
   
   byte[0] = 0x00;
   
   for (i=0; i<2; i++) {
      switch(sbyte[i]) {
         case '0': byte[0] = byte[0] + (0<<((1-i)*4)); break;
         case '1': byte[0] = byte[0] + (1<<((1-i)*4)); break;
         case '2': byte[0] = byte[0] + (2<<((1-i)*4)); break;
         case '3': byte[0] = byte[0] + (3<<((1-i)*4)); break;
         case '4': byte[0] = byte[0] + (4<<((1-i)*4)); break;
         case '5': byte[0] = byte[0] + (5<<((1-i)*4)); break;
         case '6': byte[0] = byte[0] + (6<<((1-i)*4)); break;
         case '7': byte[0] = byte[0] + (7<<((1-i)*4)); break;
         case '8': byte[0] = byte[0] + (8<<((1-i)*4)); break;
         case '9': byte[0] = byte[0] + (9<<((1-i)*4)); break;
         case 'A': byte[0] = byte[0] + (10<<((1-i)*4)); break;
         case 'B': byte[0] = byte[0] + (11<<((1-i)*4)); break;
         case 'C': byte[0] = byte[0] + (12<<((1-i)*4)); break;
         case 'D': byte[0] = byte[0] + (13<<((1-i)*4)); break;
         case 'E': byte[0] = byte[0] + (14<<((1-i)*4)); break;
         case 'F': byte[0] = byte[0] + (15<<((1-i)*4)); break;
         case 'a': byte[0] = byte[0] + (10<<((1-i)*4)); break;
         case 'b': byte[0] = byte[0] + (11<<((1-i)*4)); break;
         case 'c': byte[0] = byte[0] + (12<<((1-i)*4)); break;
         case 'd': byte[0] = byte[0] + (13<<((1-i)*4)); break;
         case 'e': byte[0] = byte[0] + (14<<((1-i)*4)); break;
         case 'f': byte[0] = byte[0] + (15<<((1-i)*4)); break;
      }
   }
   
   return 0;
}


char *carrega_arquivo(char *arquivo, unsigned long int *arquivo_size) {
   FILE *fd;
   char *cache, msg[100];
   unsigned long int size_file, n;
   
   fd = fopen(arquivo,"rb");
   if(fd <= 0x00000000) return 0x00000000;
   
   for(size_file=0 ; fgetc(fd) != -1; size_file++);
   rewind(fd);
   
   sprintf(msg, "%s%c%c%s%c%c%s%lu%c%c%c%c", \
                "HTTP/1.1 200 OK", 0x0D, 0x0A, \
                "Content-Type: text/html; charset=UTF-8", 0x0D, 0x0A, \
                "Content-Length: ", size_file, 0x0D, 0x0A, \
                0x0D, 0x0A
   );
   
   cache = malloc((long unsigned int)size_file + strlen(msg));
   
   sprintf(cache, "%s", msg);
   
   n = fread(&cache[strlen(msg)], 1, size_file, fd);
   if(n != size_file) {
      fprintf(stderr, "\nERRO: fread leu menos apenas %lu bytes. Isso é menor que o tamanho do arquivo.\n\n", n);
      fclose(fd);
      free(cache);
      return 0x00000000;
   }
   fclose(fd);
   
   *arquivo_size = size_file;
   return cache;
}


int main() {
   char file_line[50], *pagina;
   int sock, conexao, endereco_size = sizeof(struct sockaddr_in), yes = 1, i, j;
   struct sockaddr_in endereco_local, endereco_remoto;
   unsigned char buffer[1024], entrada[1024], saida[1024];
   unsigned short int n;
   unsigned long int pagina_size;
   
   if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
      return 1;
   }
   setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
   
   endereco_local.familia = AF_INET;
   endereco_local.porta   = htons(8085);
   endereco_local.ip      = inet_addr("127.0.0.1");
   
   if (bind(sock, &endereco_local, sizeof(struct sockaddr_in)) < 0) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
      return 1;
   }
   
   if (listen(sock, 5) < 0) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
      return 1;
   }
   
   for (;;) {
      if ((conexao = accept(sock, &endereco_remoto, &endereco_size)) < 0) {
         sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
         perror(file_line);
         return 1;
      }
      
      for (n = 0; n < 1024; n++) buffer[n] = 0x00; // limpa o buffer para não evitar erro de impressão
      
      // Carrega cabeçalho HTTP
      for (n = 0; n < 1024; ) {
         read(conexao, &buffer[n], 1);
         if (buffer[n] == -1) {
            n = 0;
            break;
         }
         else fprintf(stdout, "%c", buffer[n]);
         
         // verifica se é o fim do cabeçalho HTTP
         if ((buffer[n] == 0x0A) && (n > 3)) {
            if (buffer[n-1] == 0x0D && buffer[n-2] == 0x0A && buffer[n-3] == 0x0D) break;
         }
         n = n + 1;
      }
      
      if ((n == 0) || (n < 15)) {
         close(conexao);
         continue;
      }
      
      if ((buffer[0]  != 'G') && \
          (buffer[1]  != 'E') && \
          (buffer[2]  != 'T') && \
          (buffer[3]  != ' ') && \
          (buffer[4]  != '/') ) {
         close(conexao);
         continue;
      }
      
      if ((buffer[5]  == ' ') && \
          (buffer[6]  == 'H') && \
          (buffer[7]  == 'T') && \
          (buffer[8]  == 'T') && \
          (buffer[9]  == 'P') && \
          (buffer[10] == '/') && \
          (buffer[11] == '1') && \
          (buffer[12] == '.') && \
          (buffer[13] == '1') ) {
         pagina = carrega_arquivo("index.html", &pagina_size);
         if (pagina != 0) {
            send(conexao, pagina, strlen(pagina), 0);   // envia a página inicial para o cliente.
            free(pagina);
            pagina = 0;
         }
         close(conexao);
         continue;
      }
      else if ((buffer[5] == 'f') && \
               (buffer[6] == '=')) {
         j = 7;
         for (i=0; buffer[j] != 0x20 && i < (n-7); i++) {
            if (buffer[j] == '%' && i < (n-7-3)) {
               if (_read_hex_byte(&buffer[j+1], &entrada[i])) return 1;
               j = j + 2;
            }
            else if (buffer[j] == '+') entrada[i] = ' ';
            else entrada[i] = buffer[j];
            //fprintf(stdout, "%c", entrada[i]);
            j = j + 1;
         }
         entrada[i] = 0x00;
         fprintf(stdout, "\nentrada = %s\n\n", entrada);
         
         // altera a "entrada"
         sprintf((char *)buffer, "%s%s%s%s%s", "<option>", (char *)entrada, "</option><p>", (char *)entrada, "</p>");
         sprintf((char *)entrada, "%s", (char *)buffer);
         
         // Reenvia o que recebeu
         sprintf((char *)saida, "%s", (char *)entrada);
         
         // send the string in "entrada" to the client.
         sprintf((char *)buffer, "HTTP/1.1 200 OK%c%cContent-Type: text/html%c%cContent-Length: ", 0x0D, 0x0A, 0x0D, 0x0A);
         sprintf((char *)buffer, "%s%d%c%c%c%c%s", (char *)buffer, strlen((char *)saida),0x0D, 0x0A, 0x0D, 0x0A, (char *)saida);
         send(conexao, buffer, strlen((char *)buffer), 0);
         close(conexao);
         fprintf(stdout, "saida = %s\n\n", saida);
      }
      else {
         close(conexao); continue; // isso está aqui por que ainda não escrevi parse-arquivo()
         
         //arquivo = parse-arquivo();
         //pagina = carrega_arquivo(arquivo, &pagina_size);
         if (pagina != 0) {
            send(conexao, pagina, strlen(pagina), 0);   // envia a página inicial para o cliente.
            free(pagina);
            pagina = 0;
         }
         close(conexao);
         continue;
      }
   }
   close(sock);
   
   return 0;
}

