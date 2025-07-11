/*

char *fgets(char *string, int length, FILE *stream)

Lê uma linha de texto de *stream e armazena o que foi lido em *string.
Retorna um ponteiro para a string lida ou NULL em caso de erro ou final de arquivo.
O parâmetro lenght limita o numero máximo de bytes que se quer ler por linha (tamanho-1). Se a linha no arquivo for maior que tamanho, lê apenas a parte inicial. O restante será lido na próxima chamada à fgets().

The fgets function terminates reading after a new-line character is found, after it reaches end-of-file, or after (length - 1) characters have been read

If a new-line was reached it is included in the string as the last character before the null character.

The length argument includes space needed for the null character which will be appended to the end of the string.
*/


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdin;	
extern char *fgets(char *__restrict __s, int __n, FILE *__restrict __stream);
extern int printf(__const char *__restrict __format, ...);
extern int getchar(void);

#define MAX_LEN 20
#define BUFFSIZE 8
#define NULL '\0'


/*
char *
_IO_fgets (buf, n, fp)
     char *buf;
     int n;
     _IO_FILE *fp;
{
  _IO_size_t count;
  char *result;
  int old_error;
  CHECK_FILE (fp, NULL);
  if (n <= 0)
    return NULL;
  if (__builtin_expect (n == 1, 0))
    {
      /* Another irregular case: since we have to store a NUL byte and
	 there is only room for exactly one byte, we don't have to
	 read anything.  */
      buf[0] = '\0';
      return buf;
    }
  _IO_acquire_lock (fp);
  /* This is very tricky since a file descriptor may be in the
     non-blocking mode. The error flag doesn't mean much in this
     case. We return an error only when there is a new error. */
  old_error = fp->_IO_file_flags & _IO_ERR_SEEN;
  fp->_IO_file_flags &= ~_IO_ERR_SEEN;
  count = INTUSE(_IO_getline) (fp, buf, n - 1, '\n', 1);
  /* If we read in some bytes and errno is EAGAIN, that error will
     be reported for next read. */
  if (count == 0 || ((fp->_IO_file_flags & _IO_ERR_SEEN)
		     && errno != EAGAIN))
    result = NULL;
  else
    {
      buf[count] = '\0';
      result = buf;
    }
  fp->_IO_file_flags |= old_error;
  _IO_release_lock (fp);
  return result;
}

*/

int main()
{
   char str_buf[MAX_LEN + 1];
   char buff[BUFFSIZE];    

   if (fgets(buff, BUFFSIZE, stdin) == NULL)
   {
      printf("read error.\n");
      return(1);
   }
   
   printf("fgets: %s.\n", buff);
   
   while(getchar() != '\n'); //limpa o buffer de stdin
   
   while(fgets(str_buf, MAX_LEN + 1, stdin) != NULL)
      printf("%s\n", str_buf);
   
   return(0);
}

