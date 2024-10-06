
/*
Escreve uma string para a saída padrão stdout e adiciona um '\n'.
*/


//#include <stdio.h>
extern int puts( const char *);



/*

int
_IO_puts (str)
     const char *str;
{
  int result = EOF;
  _IO_size_t len = strlen (str);
  _IO_acquire_lock (_IO_stdout);

  if ((_IO_vtable_offset (_IO_stdout) != 0
       || _IO_fwide (_IO_stdout, -1) == -1)
      && _IO_sputn (_IO_stdout, str, len) == len
      && _IO_putc_unlocked ('\n', _IO_stdout) != EOF)
    result = MIN (INT_MAX, len + 1);

  _IO_release_lock (_IO_stdout);
  return result;
}


*/
/* EXEMPLO */

int main()
{
  char string[] = "Hello world!";
  puts(string);
  return 0;
}

