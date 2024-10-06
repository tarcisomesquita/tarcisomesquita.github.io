// clear ; gcc -Wall getenv.c -o getenv.elf && ./getenv.elf

int printf(char *, ...);

//#include<stdlib.h> = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern char *getenv(const char *);
// retorna zero se não houver a variável ambiente.

// Put STRING, which is of the form "NAME=VALUE", in the environment.
// If there is no `=', remove NAME from the environment.
extern int putenv(char *string);


int main(int argc, char **argv) {
   char *pPath;
   char path2[] = "PATH=/teste:/bin";
   
   printf("\n");
   pPath = getenv("PATH");
   printf("pPath = %08X\n", (unsigned int)pPath);
   printf("The current $PATH is: %s\n",pPath);
   
   putenv(path2);
   
   printf("\n");
   pPath = getenv("PATH");
   printf("pPath = %08X\n", (unsigned int)pPath);
   printf("The current $PATH is: %s\n",pPath);
   
   printf("\n");
   return 0;
}

