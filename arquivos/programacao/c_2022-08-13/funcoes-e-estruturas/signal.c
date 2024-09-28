
// prefira a função sigaction

//#include<signal.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef void (*__sighandler_t)(int);
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern int __sigpause(int __sig_or_mask, int __is_sig);

//#include<bits/signum.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define	SIGHUP		1	// Hangup (POSIX).
#define	SIGINT		2	// Interrupt (ANSI).
#define	SIGQUIT		3	// Quit (POSIX).
#define	SIGILL		4	// Illegal instruction (ANSI).
#define	SIGTRAP		5	// Trace trap (POSIX).
#define	SIGABRT		6	// Abort (ANSI).
#define	SIGIOT		6	// IOT trap (4.2 BSD).
#define	SIGBUS		7	// BUS error (4.2 BSD).
#define	SIGFPE		8	// Floating-point exception (ANSI).
#define	SIGKILL		9	// Kill, unblockable (POSIX).
#define	SIGUSR1		10	// User-defined signal 1 (POSIX).
#define	SIGSEGV		11	// Segmentation violation (ANSI).
#define	SIGUSR2		12	// User-defined signal 2 (POSIX).
#define	SIGPIPE		13	// Broken pipe (POSIX).
#define	SIGALRM		14	// Alarm clock (POSIX).
#define	SIGTERM		15	// Termination (ANSI).
#define	SIGSTKFLT	16	// Stack fault.
#define	SIGCLD		SIGCHLD	// Same as SIGCHLD (System V).
#define	SIGCHLD		17	// Child status has changed (POSIX).
#define	SIGCONT		18	// Continue (POSIX).
#define	SIGSTOP		19	// Stop, unblockable (POSIX).
#define	SIGTSTP		20	// Keyboard stop (POSIX).
#define	SIGTTIN		21	// Background read from tty (POSIX).
#define	SIGTTOU		22	// Background write to tty (POSIX).
#define	SIGURG		23	// Urgent condition on socket (4.2 BSD).
#define	SIGXCPU		24	// CPU limit exceeded (4.2 BSD).
#define	SIGXFSZ		25	// File size limit exceeded (4.2 BSD).
#define	SIGVTALRM	26	// Virtual alarm clock (4.2 BSD).
#define	SIGPROF		27	// Profiling alarm clock (4.2 BSD).
#define	SIGWINCH	28	// Window size change (4.3 BSD, Sun).
#define	SIGPOLL		SIGIO	// Pollable event occurred (System V).
#define	SIGIO		29	// I/O now possible (4.2 BSD).
#define	SIGPWR		30	// Power failure restart (System V).
#define SIGSYS		31	// Bad system call.
#define SIGUNUSED	31

#define	_NSIG		65	// Biggest signal number + 1 (including real-time signals).

#define SIGRTMIN        (__libc_current_sigrtmin ())
#define SIGRTMAX        (__libc_current_sigrtmax ())

// These are the hard limits of the kernel.  These values should not be used directly at user level.
#define __SIGRTMIN	32
#define __SIGRTMAX	(_NSIG - 1)


//#include<stdarg.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)


//#include<stdio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//extern int printf(char *, ...);
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;
extern int vfprintf (FILE *s, const char *format, va_list arg);


int printf(const char *format, ...)
{
   va_list arg;
   int done;
   va_start(arg,format);
   done = vfprintf(stdout, format, arg);
   va_end(arg);
   return done;
}

void imprime(int i)
{
   printf("Recebi um sinal\n");
//   return 0;
}

int main()
{
   signal(SIGTERM, imprime);
   for(;;)
   {
      printf("Estou aqui\n");
      __sigpause(SIGALRM, 1);
   }
   return 0;
}

