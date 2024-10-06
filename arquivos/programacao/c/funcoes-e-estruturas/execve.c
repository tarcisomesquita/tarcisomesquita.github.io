// $ clear ; gcc -Wall -static execve.c -o execve.elf && strace -s 100 -i -f -v ./execve.elf T1

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
// Replace the current process, executing PATH with arguments ARGV and environment ENVP.
// ARGV and ENVP are terminated by NULL pointers.
extern int execve (const char *path, const char **argv, const char **envp);

char arg1[] = "arg1";
char arg2[] = "arg2";
//char arg3 = 0x00;

struct t {
   char *a;
   char *b;
   char *c;
} teste;

char **argv2 = (char **)&teste;

int main(int argc, char **argv) {
   
   teste.a = arg1;
   teste.b = arg2;
   teste.c = (char *)0x00;
   
   execve ("./write.elf", (const char **)argv2, (const char **)0x000000);
   
   return 0;
}

