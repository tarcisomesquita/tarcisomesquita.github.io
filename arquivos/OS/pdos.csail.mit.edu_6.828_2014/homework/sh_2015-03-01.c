// clear ; gcc -Wall sh.c -o sh.elf && ./sh.elf

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>

extern int wait(int *);

// Simplifed xv6 shell.

#define MAXARGS 10

// All commands have at least a type. Have looked at the type, the code
// typically casts the *cmd to some specific cmd type.
struct cmd {
   int type;          //  ' ' (exec), | (pipe), '<' or '>' for redirection
};

struct execcmd {
   int type;              // ' '
   char *argv[MAXARGS];   // arguments to the command to be exec-ed
};

struct redircmd {
   int type;          // < or > 
   struct cmd *cmd;   // the command to be run (e.g., an execcmd)
   char *file;        // the input/output file
   int mode;          // the mode to open the file with
   int fd;            // the file descriptor number to use for the file
};

struct pipecmd {
   int type;          // |
   struct cmd *left;  // left side of pipe
   struct cmd *right; // right side of pipe
};

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// Execute cmd.  Never returns.
void runcmd(struct cmd *cmd) {
   //int p[2], r;
   struct execcmd *ecmd;
   //struct pipecmd *pcmd;
   struct redircmd *rcmd;
   
   printf("> runcmd\n");
   if(cmd == 0) exit(0);
   
   switch(cmd->type) {
      case ' ':
         ecmd = (struct execcmd*)cmd;
         if(ecmd->argv[0] == 0) exit(0);
         fprintf(stderr, "exec not implemented\n");
         // Your code here ...
         break;
      case '>':
      case '<':
         rcmd = (struct redircmd*)cmd;
         fprintf(stderr, "redir not implemented\n");
         // Your code here ...
         runcmd(rcmd->cmd);
         break;
      case '|':
         //pcmd = (struct pipecmd*)cmd;
         fprintf(stderr, "pipe not implemented\n");
         // Your code here ...
         break;
      default:
         fprintf(stderr, "unknown runcmd\n");
         exit(-1);
   }
   exit(0);
}


struct cmd *execcmd(void) {
   struct execcmd *cmd;
   
   printf("> execcmd\n");
   cmd = malloc(sizeof(*cmd));
   memset(cmd, 0, sizeof(*cmd));
   cmd->type = ' ';
   return (struct cmd*)cmd;
}


struct cmd *redircmd(struct cmd *subcmd, char *file, int type) {
   struct redircmd *cmd;
   
   printf("> redircmd\n");
   cmd = malloc(sizeof(*cmd));
   memset(cmd, 0, sizeof(*cmd));
   cmd->type = type;
   cmd->cmd = subcmd;
   cmd->file = file;
   cmd->mode = (type == '<') ?  O_RDONLY : O_WRONLY|O_CREAT|O_TRUNC;
   cmd->fd = (type == '<') ? 0 : 1;
   return (struct cmd*)cmd;
}

struct cmd *pipecmd(struct cmd *left, struct cmd *right) {
   struct pipecmd *cmd;
   
   printf("> pipecmd\n");
   cmd = malloc(sizeof(*cmd));
   memset(cmd, 0, sizeof(*cmd));
   cmd->type = '|';
   cmd->left = left;
   cmd->right = right;
   return (struct cmd*)cmd;
}

// Parsing

//struct cmd *parseline(char**, char*);
//struct cmd *parsepipe(char**, char*);
//struct cmd *parseexec(char**, char*);

char whitespace[] = " \t\r\n\v";
char symbols[] = "<|>";

int gettoken(char **ps, char *es, char **q, char **eq) {
   char *s;
   int ret;
   
   printf("> gettoken(&\"%s\", 0x%08X, 0x%08X, 0x%08X)\n", *ps, (unsigned int)es, (unsigned int)*eq, (unsigned int)*eq);
   s = *ps;
   while(s < es && strchr(whitespace, *s)) s++;
   if(q) *q = s;
   ret = *s;
   switch(*s) {
      case 0: break;
      case '|':
      case '<':
         s++;
         break;
      case '>':
         s++;
         break;
      default:
         ret = 'a';
         while(s < es && !strchr(whitespace, *s) && !strchr(symbols, *s)) s++;
         break;
   }
   if(eq) *eq = s;
   
   while(s < es && strchr(whitespace, *s)) s++;
   *ps = s;
   return ret;
}


int peek(char **ps, char *es, char *toks) {
   char *s;
   
   printf("> peek(&\"%s\", 0x%08X, \"%s\")\n", *ps, (unsigned int)es, toks);
   s = *ps;
   while(s < es && strchr(whitespace, *s)) s++;
   *ps = s;
   return *s && strchr(toks, *s);
}


// make a copy of the characters in the input buffer, starting from s through es.
// null-terminate the copy to make it a string.
char *mkcopy(char *s, char *es) {
   int n = es - s;
   char *c = malloc(n+1);
   
   assert(c);  //  c ? (void)(0) : __assert_fail ("c", __FILE__, __LINE__, __ASSERT_FUNCTION))
   strncpy(c, s, n);
   c[n] = 0;
   return c;
}


struct cmd *parseredirs(struct cmd *cmd, char **ps, char *es) {
   int tok;
   char *q, *eq;
   
   printf("> parseredirs(struct cmd *, &\"%s\", 0x%08X)\n", *ps, (unsigned int)es);
   //printf("*ps = \'%s\'\n", *ps);
   while(peek(ps, es, "<>")) {
      tok = gettoken(ps, es, 0, 0);
      if(gettoken(ps, es, &q, &eq) != 'a') {
         fprintf(stderr, "missing file for redirection\n");
         exit(-1);
      }
      switch(tok) {
         case '<':
            cmd = redircmd(cmd, mkcopy(q, eq), '<');
            break;
         case '>':
            cmd = redircmd(cmd, mkcopy(q, eq), '>');
            break;
      }
   }
   return cmd;
}


struct cmd *parseexec(char **ps, char *es) {
   char *q, *eq;
   int tok, argc;
   struct execcmd *cmd;
   struct cmd *ret;
   
   printf("> parseexec(&\"%s\", 0x%08X)\n", *ps, (unsigned int)es);
   //printf("*ps = \'%s\'\n", *ps);
   ret = execcmd();
   cmd = (struct execcmd*)ret;
   
   argc = 0;
   ret = parseredirs(ret, ps, es);
   while(!peek(ps, es, "|")){
      printf("*ps = \'%s\'\n", *ps);
      if((tok=gettoken(ps, es, &q, &eq)) == 0) break;
      if(tok != 'a') {
         fprintf(stderr, "syntax error\n");
         exit(-1);
      }
      cmd->argv[argc] = mkcopy(q, eq);
      argc++;
      if(argc >= MAXARGS) {
         fprintf(stderr, "too many args\n");
         exit(-1);
      }
      ret = parseredirs(ret, ps, es);
   }
   cmd->argv[argc] = 0;
   return ret;
}


struct cmd *parsepipe(char **ps, char *es) {
   struct cmd *cmd;
   
   printf("> parsepipe(&\"%s\", 0x%08X)\n", *ps, (unsigned int)es);
   //printf("*ps = \'%s\'\n", *ps);
   cmd = parseexec(ps, es);
   if (peek(ps, es, "|")){
      gettoken(ps, es, 0, 0);
      cmd = pipecmd(cmd, parsepipe(ps, es));
   }
   return cmd;
}


struct cmd *parseline(char **ps, char *es) {
   struct cmd *cmd;
   
   printf("> parseline(&\"%s\", 0x%08X)\n", *ps, (unsigned int)es);
   //printf("*ps = \'%s\'\n", *ps);
   cmd = parsepipe(ps, es);
   return cmd;
}


struct cmd *parsecmd(char *s) {
   char *es;
   struct cmd *cmd;
   
   printf("> parsecmd(\"%s\")\n", s);
   //printf("s = \'%s\'\n", s);
   printf("\"%s\" = 0x%08X\n", s, (unsigned int)s);
   es = s + strlen(s);
   cmd = parseline(&s, es);
   peek(&s, es, "");
   if(s != es) {
      fprintf(stderr, "leftovers: %s\n", s);
      exit(-1);
   }
   return cmd;
}


int fork1(void) {
   int pid;
   
   //printf("> fork1\n");
   pid = fork();
   if(pid == -1) perror("fork");
   return pid;
}


int getcmd(char *buf, int nbuf) {
   printf("> getcmd\n");
   if(isatty(fileno(stdin))) fprintf(stdout, "6.828$ ");
   memset(buf, 0, nbuf);
   fgets(buf, nbuf, stdin);
   if(buf[0] == 0) return -1; // EOF
   buf[strlen(buf) - 1] = 0;
   return 0;
}


int main(int argc, char **argv) {
   static char buf[100];
   int r;
   
   printf("> main\n");
   // Read and run input commands.
   while(getcmd(buf, sizeof(buf)) >= 0){
      if(buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' '){
         buf[strlen(buf)-1] = 0;  // chop \n
         if(chdir(buf+3) < 0) fprintf(stderr, "cannot cd %s\n", buf+3);
         continue;
      }
      if(fork1() == 0) runcmd(parsecmd(buf));
      wait(&r);
   }
   exit(0);
}

