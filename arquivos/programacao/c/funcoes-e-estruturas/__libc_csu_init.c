

/* retirada do arquivo elf-init.c da pasta do código fonte de glibc-2.11/csu */

typedef unsigned int size_t;

/* These magic symbols are provided by the linker.  */
extern void (*__preinit_array_start[])(int, char **, char **);
extern void (*__preinit_array_end[])(int, char **, char **);
extern void (*__init_array_start[])(int, char **, char **);
extern void (*__init_array_end[])(int, char **, char **);


/* These function symbols are provided for the .init/.fini section entry
   points automagically by the linker.  */
extern void _init (void);


/* These functions are passed to __libc_start_main by the startup code.
   These get statically linked into each program.  For dynamically linked
   programs, this module will come from libc_nonshared.a and differs from
   the libc.a module in that it doesn't call the preinit array.  */

void __libc_csu_init(int argc, char **argv, char **envp)
{

  /* For dynamically linked executables the preinit array is executed by
     the dynamic linker (before initializing any shared object.  */

#ifndef LIBC_NONSHARED  // se refere à biblioteca /usr/lib/libc_nonshared.a(elf-init.oS) que a tiramos usando a opção -nodefaultlibs.
# ifdef USE_MULTIARCH // não encontrei o define do USE_MULTIARCH
#  ifdef ELF_MACHINE_IRELA
  {
    const size_t size = __rela_iplt_end - __rela_iplt_start;
    for (size_t i = 0; i < size; i++)
      elf_irela (&__rela_iplt_start [i]);
  }
#  endif

#  ifdef ELF_MACHINE_IREL
   {
      const size_t size = __rel_iplt_end - __rel_iplt_start;
      for (size_t i = 0; i < size; i++)
         elf_irel (&__rel_iplt_start [i]);
   }
#  endif
# endif

  /* For static executables, preinit happens right before init.  */
   {
       const size_t size = __preinit_array_end - __preinit_array_start;
       size_t i;
       for (i = 0; i < size; i++)
          (*__preinit_array_start[i])(argc, argv, envp);
   }
#endif
   
   _init();
   
   const size_t size = __init_array_end - __init_array_start;
   size_t i = 0;
   for ( ; i < size; i++)
      (*__init_array_start[i])(argc, argv, envp);
}

/*
int main(int argc, char **argv)
{
   char **envp = "nada";
   __libc_csu_init(argc, argv, envp);
   return 0;
}
*/
