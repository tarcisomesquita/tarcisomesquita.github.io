
//#include<bits/stdio-lock.h>
#  define _IO_acquire_lock(_fp) \
  do {									      \
    _IO_FILE *_IO_acquire_lock_file					      \
	__attribute__((cleanup (_IO_acquire_lock_fct)))			      \
	= (_fp);							      \
    _IO_flockfile (_IO_acquire_lock_file);

_IO_FILE *fp;
_IO_acquire_lock(fp)

_IO_release_lock(fp)


A função _IO_acquire_lock não está definida em nenhum lugar, mas ela é usada em um grande número de funções de IO.
Não sei sua utilidade.



