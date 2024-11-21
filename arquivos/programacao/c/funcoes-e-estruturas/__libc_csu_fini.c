

/* retirada do arquivo elf-init.c da pasta do código fonte de glibc-2.11/csu */

typedef unsigned int size_t;

/* These magic symbols are provided by the linker.  */
extern void (*__fini_array_end [])(void);
extern void (*__fini_array_start [])(void);


/* These function symbols are provided for the .init/.fini section entry
   points automagically by the linker.  */
extern void _fini(void);


/* This function should not be used anymore.  We run the executable's
   destructor now just like any other.  We cannot remove the function,
   though.  */
void __libc_csu_fini(void)
{
#ifndef LIBC_NONSHARED // se refere à biblioteca /usr/lib/libc_nonshared.a(elf-init.oS) que a tiramos usando a opção -nodefaultlibs.
  size_t i = __fini_array_end - __fini_array_start;
  while (i-- > 0)
    (*__fini_array_start [i]) ();

  _fini ();
#endif
}

/*
int main()
{
   __libc_csu_fini();
   return 0;
}
*/
