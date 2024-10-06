
// usei o comando gcc -Wall -I../sysdeps/generic -I../sysdeps/unix/sysv/linux -E -P -o libc-start2.c libc-start.c
// dentro do diretório /media/ARQpen2/codigos fonte/glibc-2.11/csu

//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

extern int __libc_multiple_libcs;
extern int _dl_starting_up;
extern char **__environ;
extern void *__libc_stack_end;
extern void __pthread_initialize_minimal(void);
typedef unsigned int uintptr_t;
extern void *_dl_random;
typedef unsigned int size_t;
extern void *memcpy(void *__restrict __dest, const void *__restrict __src, size_t __n);
_dl_setup_stack_chk_guard(void *dl_random)
{
   uintptr_t ret;
   if(dl_random == ((void *)0))
   {
      ret = 0;
      unsigned char *p = (unsigned char *) &ret;
      p[sizeof(ret) - 1] = 255;
      p[sizeof(ret) - 2] = '\n';
      p[0] = 0;
   }
   else
      memcpy(&ret, dl_random, sizeof(ret));
   return ret;
}
uintptr_t __stack_chk_guard;
extern void __libc_init_first(int argc, char **argv, char **envp);
extern int __libc_enable_secure;
extern void exit(int __status);



//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

int __libc_start_main(int (*main)(int, char **, char ** ), int argc, char * * ubp_av, __typeof (main) init, void (*fini)(void), void (*rtld_fini)(void), void * stack_end)
{
   int result;
   __libc_multiple_libcs = &_dl_starting_up && !_dl_starting_up;
   char * * ubp_ev = &ubp_av[argc + 1];
   __environ = ubp_ev;
   __libc_stack_end = stack_end;
   __pthread_initialize_minimal();
   uintptr_t stack_chk_guard = _dl_setup_stack_chk_guard(_dl_random);
   __stack_chk_guard = stack_chk_guard;
   if(__builtin_expect(rtld_fini != ((void *)0), 1))
      __cxa_atexit((void (*) (void *)) rtld_fini, ((void *)0), ((void *)0));
   __libc_init_first(argc, ubp_av, __environ);
   if(fini)
      __cxa_atexit((void (*) (void *)) fini, ((void *)0), ((void *)0));
   if (__builtin_expect(__libc_enable_secure, 0))
      __libc_check_standard_fds();
   if(init)
      (*init)(argc, ubp_av, __environ);
   result = main(argc, ubp_av, __environ);
   exit(result);
}
