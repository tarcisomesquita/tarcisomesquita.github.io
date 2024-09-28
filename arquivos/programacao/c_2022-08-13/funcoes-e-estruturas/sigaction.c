
// Get and/or set the action for signal SIG.
// Funciona só num sistema POSIX


//#include<signal.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = =

typedef void (*__sighandler_t) (int);

typedef union sigval
{
   int sival_int;
   void *sival_ptr;
} sigval_t;

typedef struct siginfo
{
   int si_signo;
   int si_errno;
   int si_code;
   
   union
   {
      int _pad[((128 / sizeof (int)) - 3)];
      
      struct
      {
         int si_pid;
         unsigned int si_uid;
      } _kill;
      
      struct
      {
         int si_tid;
         int si_overrun;
         sigval_t si_sigval;
      } _timer;
      
      struct
      {
         int si_pid;
         unsigned int si_uid;
         sigval_t si_sigval;
      } _rt;
      
      struct
      {
         int si_pid;
         unsigned int si_uid;
         int si_status;
         long int si_utime;
         long int si_stime;
      } _sigchld;
      
      struct
      {
         void *si_addr;
      } _sigfault;
      
      struct
      {
         long int si_band;
         int si_fd;
      } _sigpoll;
   } _sifields;
} siginfo_t;

typedef struct
{
   unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} sigset_t;

struct sigaction
{
   union
   {
      __sighandler_t sa_handler;
      void (*sa_sigaction) (int, siginfo_t *, void *);
   }
   
   __sigaction_handler;
   sigset_t sa_mask;
   int sa_flags;
   void (*sa_restorer) (void);
};

extern int sigaction (int __sig, const struct sigaction *__restrict __act, struct sigaction *__restrict __oact);



// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


#define	SIGINT		2	// Interrupt (ANSI).


void termination_handler (int signum)
{
   fprintf(stdout,"Estou aqui\n");
}

int main (void)
{
   struct sigaction new_action;
   int i;
   
   new_action.__sigaction_handler.sa_handler = termination_handler;
   new_action.sa_flags = 0;
   
   sigaction (SIGINT, &new_action, 0x00);
   
   fprintf(stdout,"\nDigite Ctrl-c\n\n");
   
   for(i=0;i<1000000000;i++);
   
   return(0);
}

