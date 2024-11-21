#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char cmd[512];
char dir[4096];
char *argv[3];
int pid;

int main(void) {
   while (1) {
      printf("0 ");
      fgets(cmd, 511, stdin);
      cmd[strlen(cmd) - 1] = 0;  // troca o enter = \n por um novo \0 = 0
      if (strcmp(cmd, "exit") == 0) return 0; // se o resultado da comparação for 0 = V finaliza o shell
      
      argv[0] = strtok(cmd, " ");
      argv[1] = strtok(0x00, " ");
      argv[2] = 0x00;
      
      if (strcmp(argv[0], "pwd") == 0) {
         getcwd(dir, 4096);
         printf("%s\n", dir);
      }
      else if (strcmp(argv[0], "cd") == 0) {
         if (chdir(argv[1]) != 0) printf("Caminho inválido!\n");
      }
      else {
         pid = fork();
         if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
               printf("Comando inválido\n");
               return 1;
            }
         }
         else wait();
      }
   }
   return 0;
}

