/*
minha conclusão: é melhor não usar essa função

gcc getopt.pre.c  -std=gnu99 -fgnu89-inline -O2 -U_FORTIFY_SOURCE -Wall -Winline -Wwrite-strings -fmerge-all-constants -fno-stack-protector -march=prescott -mtune=native -Wstrict-prototypes -mpreferred-stack-boundary=2  -fexceptions -c -o /home/ubuntu/Desktop/getopt.o


gcc getopt.pre.c  -std=gnu99 -fgnu89-inline -O2 -U_FORTIFY_SOURCE -Wall -Winline -Wwrite-strings -fmerge-all-constants -fno-stack-protector -march=prescott -mtune=native -Wstrict-prototypes -mpreferred-stack-boundary=2  -fexceptions -o /home/ubuntu/Desktop/getopt.elf

/tmp/cctd9Aph.o: In function `_getopt_internal_r':
getopt.pre.c:(.text+0x69a): undefined reference to `__fxprintf'
*/


struct option {
   const char *name;
   int has_arg;
   int *flag;
   int val;
};

struct _getopt_data {
   int optind;
   int opterr;
   int optopt;
   char *optarg;
   int __initialized;
   char *__nextchar;
   enum {
      REQUIRE_ORDER, PERMUTE, RETURN_IN_ORDER
   } __ordering;
   int __posixly_correct;
   int __first_nonopt;
   int __last_nonopt;
};

char *optarg;
int optind = 1;
int opterr = 1;
int optopt = '?';
static struct _getopt_data getopt_data;

extern int printf(const char *format, ...);

void imprima_dados() {
   printf("\n");
   printf("optarg = \"%s\"\n", optarg);
   printf("optind = %d\n", optind);
   printf("opterr = %d\n", opterr);
   printf("optopt = %d\n", optopt);
   printf("\n");
   printf("getopt_data.optind = %d\n", getopt_data.optind);
   printf("getopt_data.opterr = %d\n", getopt_data.opterr);
   printf("getopt_data.optopt = %d\n", getopt_data.optopt);
   printf("getopt_data.optarg = \"%s\"\n", getopt_data.optarg);
   printf("getopt_data.__initialized = %d\n", getopt_data.__initialized);
   printf("getopt_data.__nextchar = \"%s\"\n", getopt_data.__nextchar);
   //printf("getopt_data. = %d\n", getopt_data.);
   printf("getopt_data.__posixly_correct = %d\n", getopt_data.__posixly_correct);
   printf("getopt_data.__first_nonopt = %d\n", getopt_data.__first_nonopt);
   printf("getopt_data.__last_nonopt = %d\n", getopt_data.__last_nonopt);
   printf("\n");
   
   return;
}

/*
extern void __chk_fail (void) __attribute__ ((__noreturn__));



typedef unsigned int size_t;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;
__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
__extension__ typedef __u_quad_t __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef __u_quad_t __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef __quad_t __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef __u_quad_t __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;
__extension__ typedef int __daddr_t;
__extension__ typedef long int __swblk_t;
__extension__ typedef int __key_t;
__extension__ typedef int __clockid_t;
__extension__ typedef void * __timer_t;
__extension__ typedef long int __blksize_t;
__extension__ typedef long int __blkcnt_t;
__extension__ typedef __quad_t __blkcnt64_t;
__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef __u_quad_t __fsblkcnt64_t;
__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef __u_quad_t __fsfilcnt64_t;
__extension__ typedef int __ssize_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
__extension__ typedef int __intptr_t;
__extension__ typedef unsigned int __socklen_t;
struct _IO_FILE;

typedef struct _IO_FILE FILE;








typedef struct _IO_FILE __FILE;
typedef int wchar_t;
typedef unsigned int wint_t;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,
  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,
  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};
enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};
struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;
typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
       __const unsigned char **, __const unsigned char *,
       unsigned char **, unsigned int *, int, int);
typedef wint_t (*__gconv_btowc_fct) (struct __gconv_step *, unsigned char);
typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);
typedef int (*__gconv_trans_fct) (struct __gconv_step *,
      struct __gconv_step_data *, void *,
      __const unsigned char *,
      __const unsigned char **,
      __const unsigned char *, unsigned char **,
      unsigned int *);
typedef int (*__gconv_trans_context_fct) (void *, __const unsigned char *,
       __const unsigned char *,
       unsigned char *, unsigned char *);
typedef int (*__gconv_trans_query_fct) (__const char *, __const char ***,
     unsigned int *);
typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);
struct __gconv_trans_data
{
  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};
struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  __const char *__modname;
  int __counter;
  char *__from_name;
  char *__to_name;
  __gconv_fct __fct;
  __gconv_btowc_fct __btowc_fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;
  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;
  int __stateful;
  void *__data;
};
struct __gconv_step_data
{
  unsigned char *__outbuf;
  unsigned char *__outbufend;
  int __flags;
  int __invocation_counter;

  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;



  struct __gconv_trans_data *__trans;
};



typedef struct __gconv_info
{
  unsigned int __nsteps;
  struct __gconv_step *__steps;
  __extension__ struct __gconv_step_data __data [];
} *__gconv_t;
typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t; struct _IO_FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;




};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};




struct _IO_codecvt
{
  void (*__codecvt_destr) (struct _IO_codecvt *);
  enum __codecvt_result (*__codecvt_do_out) (struct _IO_codecvt *,
          __mbstate_t *,
          const wchar_t *,
          const wchar_t *,
          const wchar_t **, char *,
          char *, char **);
  enum __codecvt_result (*__codecvt_do_unshift) (struct _IO_codecvt *,
       __mbstate_t *, char *,
       char *, char **);
  enum __codecvt_result (*__codecvt_do_in) (struct _IO_codecvt *,
         __mbstate_t *,
         const char *, const char *,
         const char **, wchar_t *,
         wchar_t *, wchar_t **);
  int (*__codecvt_do_encoding) (struct _IO_codecvt *);
  int (*__codecvt_do_always_noconv) (struct _IO_codecvt *);
  int (*__codecvt_do_length) (struct _IO_codecvt *, __mbstate_t *,
         const char *, const char *, size_t);
  int (*__codecvt_do_max_length) (struct _IO_codecvt *);

  _G_iconv_t __cd_in;
  _G_iconv_t __cd_out;
};


struct _IO_wide_data
{
  wchar_t *_IO_read_ptr;
  wchar_t *_IO_read_end;
  wchar_t *_IO_read_base;
  wchar_t *_IO_write_base;
  wchar_t *_IO_write_ptr;
  wchar_t *_IO_write_end;
  wchar_t *_IO_buf_base;
  wchar_t *_IO_buf_end;

  wchar_t *_IO_save_base;
  wchar_t *_IO_backup_base;

  wchar_t *_IO_save_end;

  __mbstate_t _IO_state;
  __mbstate_t _IO_last_state;
  struct _IO_codecvt _codecvt;

  wchar_t _shortbuf[1];

  const struct _IO_jump_t *_wide_vtable;
};


struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  unsigned int _freeres_size;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (unsigned int)];
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
extern _IO_FILE *_IO_stdin ;
extern _IO_FILE *_IO_stdout ;
extern _IO_FILE *_IO_stderr ;
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, unsigned int __nbytes);
typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
     unsigned int __n);
typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn (void *__cookie);
typedef __io_read_fn cookie_read_function_t;
typedef __io_write_fn cookie_write_function_t;
typedef __io_seek_fn cookie_seek_function_t;
typedef __io_close_fn cookie_close_function_t;
typedef struct
{
  __io_read_fn *read;
  __io_write_fn *write;
  __io_seek_fn *seek;
  __io_close_fn *close;
} _IO_cookie_io_functions_t;
typedef _IO_cookie_io_functions_t cookie_io_functions_t;
struct _IO_cookie_file;
extern void _IO_cookie_init (struct _IO_cookie_file *__cfile, int __read_write,
        void *__cookie, _IO_cookie_io_functions_t __fns);
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
extern wint_t __wunderflow (_IO_FILE *);
extern wint_t __wuflow (_IO_FILE *);
extern wint_t __woverflow (_IO_FILE *, wint_t);
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_peekc_locked (_IO_FILE *__fp);
extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf(_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern unsigned int _IO_sgetn (_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));
extern wint_t _IO_getwc (_IO_FILE *__fp);
extern wint_t _IO_putwc (wchar_t __wc, _IO_FILE *__fp);
extern int _IO_fwide (_IO_FILE *__fp, int __mode) __attribute__ ((__nothrow__));
extern int _IO_vfwscanf (_IO_FILE * __restrict, const wchar_t * __restrict,
    __gnuc_va_list, int *__restrict);
extern int _IO_vfwprintf(_IO_FILE *__restrict, const wchar_t *__restrict,
     __gnuc_va_list);
extern __ssize_t _IO_wpadn (_IO_FILE *, wint_t, __ssize_t);
extern void _IO_free_wbackup_area (_IO_FILE *) __attribute__ ((__nothrow__));






typedef __gnuc_va_list va_list;

typedef _G_fpos_t fpos_t;

typedef _G_fpos64_t fpos64_t;
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int remove (__const char *__filename) __attribute__ ((__nothrow__));
extern int rename (__const char *__old, __const char *__new) __attribute__ ((__nothrow__));

extern int renameat (int __oldfd, __const char *__old, int __newfd,
       __const char *__new) __attribute__ ((__nothrow__));

extern FILE *tmpfile (void) ;
extern FILE *tmpfile64 (void) ;
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__)) ;

extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__)) ;
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;

extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);

extern int fflush_unlocked (FILE *__stream);
extern int fcloseall (void);

extern FILE *fopen (__const char *__restrict __filename,
      __const char *__restrict __modes) ;
extern FILE *freopen (__const char *__restrict __filename,
        __const char *__restrict __modes,
        FILE *__restrict __stream) ;

extern FILE *fopen64 (__const char *__restrict __filename,
        __const char *__restrict __modes) ;
extern FILE *freopen64 (__const char *__restrict __filename,
   __const char *__restrict __modes,
   FILE *__restrict __stream) ;
extern FILE *fdopen (int __fd, __const char *__modes) __attribute__ ((__nothrow__)) ;
extern FILE *fopencookie (void *__restrict __magic_cookie,
     __const char *__restrict __modes,
     _IO_cookie_io_functions_t __io_funcs) __attribute__ ((__nothrow__)) ;
extern FILE *fmemopen (void *__s, unsigned int __len, __const char *__modes)
  __attribute__ ((__nothrow__)) ;
extern FILE *open_memstream (char **__bufloc, unsigned int *__sizeloc) __attribute__ ((__nothrow__)) ;

extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, unsigned int __n) __attribute__ ((__nothrow__));

extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         unsigned int __size) __attribute__ ((__nothrow__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__));

extern int fprintf(FILE *__restrict __stream,
      __const char *__restrict __format, ...);
extern int printf(__const char *__restrict __format, ...);
extern int sprintf(char *__restrict __s,
      __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf(FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf(__const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf(char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));


extern int snprintf(char *__restrict __s, unsigned int __maxlen,
       __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf(char *__restrict __s, unsigned int __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

extern int vasprintf(char **__restrict __ptr, __const char *__restrict __f,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf(char **__restrict __ptr,
         __const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf(char **__restrict __ptr,
       __const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int vdprintf(int __fd, __const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf(int __fd, __const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));

extern int fscanf (FILE *__restrict __stream,
     __const char *__restrict __format, ...) ;
extern int scanf (__const char *__restrict __format, ...) ;
extern int sscanf (__const char *__restrict __s,
     __const char *__restrict __format, ...) __attribute__ ((__nothrow__));


extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s,
      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));


extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);

extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);

extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);

extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);

extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
extern char *gets (char *__s) ;

extern char *fgets_unlocked (char *__restrict __s, int __n,
        FILE *__restrict __stream) ;
extern __ssize_t __getdelim (char **__restrict __lineptr,
          unsigned int *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        unsigned int *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
       unsigned int *__restrict __n,
       FILE *__restrict __stream) ;

extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);
extern int puts (__const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern unsigned int fread (void *__restrict __ptr, unsigned int __size,
       unsigned int __n, FILE *__restrict __stream) ;
extern unsigned int fwrite (__const void *__restrict __ptr, unsigned int __size,
        unsigned int __n, FILE *__restrict __s) ;

extern int fputs_unlocked (__const char *__restrict __s,
      FILE *__restrict __stream);
extern unsigned int fread_unlocked (void *__restrict __ptr, unsigned int __size,
         unsigned int __n, FILE *__restrict __stream) ;
extern unsigned int fwrite_unlocked (__const void *__restrict __ptr, unsigned int __size,
          unsigned int __n, FILE *__restrict __stream) ;

extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);

extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;

extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, __const fpos_t *__pos);

extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream) ;
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64 (FILE *__stream, __const fpos64_t *__pos);

extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern void perror (__const char *__s);

extern int sys_nerr;
extern __const char *__const sys_errlist[];
extern int _sys_nerr;
extern __const char *__const _sys_errlist[];
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern FILE *popen (__const char *__command, __const char *__modes) ;
extern int pclose (FILE *__stream);
extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
extern char *cuserid (char *__s);
struct obstack;
extern int obstack_printf(struct obstack *__restrict __obstack,
      __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf(struct obstack *__restrict __obstack,
       __const char *__restrict __format,
       __gnuc_va_list __args)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0)));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__));
extern __inline int
vprintf(__const char *__restrict __fmt, __gnuc_va_list __arg)
{
  return vfprintf(stdout, __fmt, __arg);
}
extern __inline int
getchar (void)
{
  return _IO_getc (stdin);
}
extern __inline int
fgetc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}
extern __inline int
getc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}
extern __inline int
getchar_unlocked (void)
{
  return (__builtin_expect (((stdin)->_IO_read_ptr >= (stdin)->_IO_read_end), 0) ? __uflow (stdin) : *(unsigned char *) (stdin)->_IO_read_ptr++);
}
extern __inline int
putchar (int __c)
{
  return _IO_putc (__c, stdout);
}
extern __inline int
fputc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}
extern __inline int
putc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}
extern __inline int
putchar_unlocked (int __c)
{
  return (__builtin_expect (((stdout)->_IO_write_ptr >= (stdout)->_IO_write_end), 0) ? __overflow (stdout, (unsigned char) (__c)) : (unsigned char) (*(stdout)->_IO_write_ptr++ = (__c)));
}
extern __inline __ssize_t
getline (char **__lineptr, unsigned int *__n, FILE *__stream)
{
  return __getdelim (__lineptr, __n, '\n', __stream);
}
extern __inline int
__attribute__ ((__nothrow__)) feof_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x10) != 0);
}
extern __inline int
__attribute__ ((__nothrow__)) ferror_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x20) != 0);
}

extern int __fcloseall (void);
extern int __snprintf(char *__restrict __s, unsigned int __maxlen,
         __const char *__restrict __format, ...)
     __attribute__ ((__format__ (__printf__, 3, 4)));
extern int __vsnprintf(char *__restrict __s, unsigned int __maxlen,
   __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 3, 0)));
extern int __vfscanf (FILE *__restrict __s,
        __const char *__restrict __format,
        __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0)));

extern int __vscanf (__const char *__restrict __format,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0)));
extern __ssize_t __getline (char **__lineptr, unsigned int *__n,
         FILE *__stream);
extern int __vsscanf (__const char *__restrict __s,
        __const char *__restrict __format,
        __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int __sprintf_chk (char *, int, size_t, const char *, ...) __attribute__ ((__nothrow__));
extern int __snprintf_chk (char *, size_t, int, size_t, const char *, ...)
     __attribute__ ((__nothrow__));
extern int __vsprintf_chk (char *, int, size_t, const char *,
      __gnuc_va_list) __attribute__ ((__nothrow__));
extern int __vsnprintf_chk (char *, size_t, int, size_t, const char *,
       __gnuc_va_list) __attribute__ ((__nothrow__));
extern int __printf_chk (int, const char *, ...);
extern int __fprintf_chk (FILE *, int, const char *, ...);
extern int __vprintf_chk (int, const char *, __gnuc_va_list);
extern int __vfprintf_chk (FILE *, int, const char *, __gnuc_va_list);
extern char *__fgets_unlocked_chk (char *buf, unsigned int size, int n, FILE *fp);
extern char *__fgets_chk (char *buf, unsigned int size, int n, FILE *fp);
extern int __asprintf_chk (char **, int, const char *, ...) __attribute__ ((__nothrow__));
extern int __vasprintf_chk (char **, int, const char *, __gnuc_va_list) __attribute__ ((__nothrow__));
extern int __dprintf_chk (int, int, const char *, ...);
extern int __vdprintf_chk (int, int, const char *, __gnuc_va_list);
extern int __obstack_printf_chk (struct obstack *, int, const char *, ...)
     __attribute__ ((__nothrow__));
extern int __obstack_vprintf_chk (struct obstack *, int, const char *,
      __gnuc_va_list) __attribute__ ((__nothrow__));
extern int __isoc99_fscanf (FILE *__restrict __stream,
       __const char *__restrict __format, ...) ;
extern int __isoc99_scanf (__const char *__restrict __format, ...) ;
extern int __isoc99_sscanf (__const char *__restrict __s,
       __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int __isoc99_vfscanf (FILE *__restrict __s,
        __const char *__restrict __format,
        __gnuc_va_list __arg) ;
extern int __isoc99_vscanf (__const char *__restrict __format,
       __gnuc_va_list __arg) ;
extern int __isoc99_vsscanf (__const char *__restrict __s,
        __const char *__restrict __format,
        __gnuc_va_list __arg) __attribute__ ((__nothrow__));


extern FILE *__new_tmpfile (void);
extern FILE *__old_tmpfile (void);
extern int __path_search (char *__tmpl, unsigned int __tmpl_len,
     __const char *__dir, __const char *__pfx,
     int __try_tempdir);
extern int __gen_tempname (char *__tmpl, int __flags, int __kind);
extern void __libc_fatal (__const char *__message)
     __attribute__ ((__noreturn__));
extern void __libc_message (int do_abort, __const char *__fnt, ...);
extern void __fortify_fail (const char *msg) __attribute__ ((noreturn));

extern void __flockfile (FILE *__stream);
extern void __funlockfile (FILE *__stream);
extern int __ftrylockfile (FILE *__stream);
extern int __getc_unlocked (FILE *__fp);
extern wint_t __getwc_unlocked (FILE *__fp);
extern int __fxprintf(FILE *__fp, const char *__fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern __const char *__const _sys_errlist_internal[] ;
extern int _sys_nerr_internal ;
extern int __asprintf_internal (char **__restrict __ptr,
    __const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern _IO_FILE *_IO_new_fopen (const char*, const char*);
extern _IO_FILE *_IO_new_fdopen (int, const char*);
extern int _IO_new_fclose (_IO_FILE*);
extern int _IO_fputs (const char*, _IO_FILE*);

extern int _IO_new_fsetpos (_IO_FILE *, const _G_fpos_t *);
extern int _IO_new_fgetpos (_IO_FILE *, _G_fpos_t *);


























typedef int ptrdiff_t;

union wait
  {
    int w_status;
    struct
      {
 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;
      } __wait_terminated;
    struct
      {
 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;
      } __wait_stopped;
  };
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));

typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;


__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;

extern unsigned int __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__)) ;

extern double atof (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern int atoi (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern long int atol (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;


__extension__ extern long long int atoll (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;


extern double strtod (__const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__)) ;


extern float strtof (__const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__)) ;
extern long double strtold (__const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__)) ;


extern long int strtol (__const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) ;
extern unsigned long int strtoul (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) ;

__extension__
extern long long int strtoq (__const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) ;
__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) ;

__extension__
extern long long int strtoll (__const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) ;
__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) ;

typedef struct __locale_struct
{
  struct locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
} *__locale_t;
extern long int strtol_l (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base,
     __locale_t __loc) __attribute__ ((__nothrow__)) ;
extern unsigned long int strtoul_l (__const char *__restrict __nptr,
        char **__restrict __endptr,
        int __base, __locale_t __loc)
     __attribute__ ((__nothrow__)) ;
__extension__
extern long long int strtoll_l (__const char *__restrict __nptr,
    char **__restrict __endptr, int __base,
    __locale_t __loc)
     __attribute__ ((__nothrow__)) ;
__extension__
extern unsigned long long int strtoull_l (__const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, __locale_t __loc)
     __attribute__ ((__nothrow__)) ;
extern double strtod_l (__const char *__restrict __nptr,
   char **__restrict __endptr, __locale_t __loc)
     __attribute__ ((__nothrow__)) ;
extern float strtof_l (__const char *__restrict __nptr,
         char **__restrict __endptr, __locale_t __loc)
     __attribute__ ((__nothrow__)) ;
extern long double strtold_l (__const char *__restrict __nptr,
         char **__restrict __endptr,
         __locale_t __loc)
     __attribute__ ((__nothrow__)) ;

extern __inline double
__attribute__ ((__nothrow__)) atof (__const char *__nptr)
{
  return strtod (__nptr, (char **) ((void *)0));
}
extern __inline int
__attribute__ ((__nothrow__)) atoi (__const char *__nptr)
{
  return (int) strtol (__nptr, (char **) ((void *)0), 10);
}
extern __inline long int
__attribute__ ((__nothrow__)) atol (__const char *__nptr)
{
  return strtol (__nptr, (char **) ((void *)0), 10);
}


__extension__ extern __inline long long int
__attribute__ ((__nothrow__)) atoll (__const char *__nptr)
{
  return strtoll (__nptr, (char **) ((void *)0), 10);
}

extern char *l64a (long int __n) __attribute__ ((__nothrow__)) ;
extern long int a64l (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;

typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __ino64_t ino64_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __off64_t off64_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;

typedef __clock_t clock_t;



typedef __time_t time_t;


typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef __useconds_t useconds_t;
typedef __suseconds_t suseconds_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));
typedef int register_t __attribute__ ((__mode__ (__word__)));
typedef int __sig_atomic_t;
typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
typedef __sigset_t sigset_t;
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask fds_bits[1024 / (8 * sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);

extern int __pselect (int __nfds, fd_set *__readfds,
        fd_set *__writefds, fd_set *__exceptfds,
        const struct timespec *__timeout,
        const __sigset_t *__sigmask);
extern int __select (int __nfds, fd_set *__restrict __readfds,
       fd_set *__restrict __writefds,
       fd_set *__restrict __exceptfds,
       struct timeval *__restrict __timeout);

__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__));
__extension__ extern __inline unsigned int
__attribute__ ((__nothrow__)) gnu_dev_major (unsigned long long int __dev)
{
  return ((__dev >> 8) & 0xfff) | ((unsigned int) (__dev >> 32) & ~0xfff);
}
__extension__ extern __inline unsigned int
__attribute__ ((__nothrow__)) gnu_dev_minor (unsigned long long int __dev)
{
  return (__dev & 0xff) | ((unsigned int) (__dev >> 12) & ~0xff);
}
__extension__ extern __inline unsigned long long int
__attribute__ ((__nothrow__)) gnu_dev_makedev (unsigned int __major, unsigned int __minor)
{
  return ((__minor & 0xff) | ((__major & 0xfff) << 8)
   | (((unsigned long long int) (__minor & ~0xff)) << 12)
   | (((unsigned long long int) (__major & ~0xfff)) << 32));
}
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[36];
  long int __align;
} pthread_attr_t;
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;
    int __kind;
    unsigned int __nusers;
    __extension__ union
    {
      int __spins;
      __pthread_slist_t __list;
    };
  } __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;
typedef union
{
  char __size[4];
  long int __align;
} pthread_mutexattr_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  char __size[4];
  long int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;
    int __writer;
  } __data;
  char __size[32];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[20];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;

extern long int random (void) __attribute__ ((__nothrow__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   unsigned int __statelen) __attribute__ ((__nothrow__)) ;
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__)) ;
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__)) ;
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__)) ;
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   unsigned int __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) ;
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) ;

extern int rand (void) __attribute__ ((__nothrow__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__));

extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__));
extern double drand48 (void) __attribute__ ((__nothrow__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__)) ;
extern long int lrand48 (void) __attribute__ ((__nothrow__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) ;
extern long int mrand48 (void) __attribute__ ((__nothrow__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) ;
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__)) ;
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__)) ;
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) ;
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) ;
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) ;
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) ;
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) ;
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) ;
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) ;
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__)) ;
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) ;

extern void *malloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern void *calloc (size_t __nmemb, unsigned int __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;


extern void *realloc (void *__ptr, unsigned int __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__warn_unused_result__));
extern void free (void *__ptr) __attribute__ ((__nothrow__));

extern void cfree (void *__ptr) __attribute__ ((__nothrow__));

extern void *alloca (size_t __size) __attribute__ ((__nothrow__));

extern void *__alloca (size_t __size);
extern int __libc_use_alloca (size_t size) __attribute__ ((const));
extern int __libc_alloca_cutoff (size_t size) __attribute__ ((const));
extern int
__inline __attribute__ ((__always_inline__))
__libc_use_alloca (size_t size)
{
  return (__builtin_expect (size <= 16384 / 4, 1)
   || __libc_alloca_cutoff (size));
}
extern void *valloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern int posix_memalign (void **__memptr, unsigned int __alignment, unsigned int __size)
     __attribute__ ((__nothrow__)) ;

extern void abort (void) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__)) ;

extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__)) ;

extern void exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));


extern void _Exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));


extern char *__secure_getenv (__const char *__name)
     __attribute__ ((__nothrow__)) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__)) ;
extern int setenv (__const char *__name, __const char *__value, int __replace)
     __attribute__ ((__nothrow__)) ;
extern int unsetenv (__const char *__name) __attribute__ ((__nothrow__));
extern int clearenv (void) __attribute__ ((__nothrow__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__)) ;
extern int mkstemp (char *__template) ;
extern int mkstemp64 (char *__template) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__)) ;
extern int mkostemp (char *__template, int __flags) ;
extern int mkostemp64 (char *__template, int __flags) ;

extern int system (__const char *__command) ;

extern char *canonicalize_file_name (__const char *__name)
     __attribute__ ((__nothrow__)) ;
extern char *realpath (__const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__)) ;
typedef int (*__compar_fn_t) (__const void *, __const void *);
typedef __compar_fn_t comparison_fn_t;
typedef int (*__compar_d_fn_t) (__const void *, __const void *, void *);

extern void *bsearch (__const void *__key, __const void *__base,
        unsigned int __nmemb, unsigned int __size, __compar_fn_t __compar)
     ;
extern void qsort (void *__base, unsigned int __nmemb, unsigned int __size,
     __compar_fn_t __compar) ;
extern void qsort_r (void *__base, unsigned int __nmemb, unsigned int __size,
       __compar_d_fn_t __compar, void *__arg)
  ;
extern int abs (int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     unsigned int __len) __attribute__ ((__nothrow__)) ;
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     unsigned int __len) __attribute__ ((__nothrow__)) ;
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, unsigned int __len)
     __attribute__ ((__nothrow__)) ;
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, unsigned int __len)
     __attribute__ ((__nothrow__)) ;

extern int mblen (__const char *__s, unsigned int __n) __attribute__ ((__nothrow__)) ;
extern int mbtowc (wchar_t *__restrict __pwc,
     __const char *__restrict __s, unsigned int __n) __attribute__ ((__nothrow__)) ;
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__)) ;
extern unsigned int mbstowcs (wchar_t *__restrict __pwcs,
   __const char *__restrict __s, unsigned int __n) __attribute__ ((__nothrow__));
extern unsigned int wcstombs (char *__restrict __s,
   __const wchar_t *__restrict __pwcs, unsigned int __n)
     __attribute__ ((__nothrow__));

extern int rpmatch (__const char *__response) __attribute__ ((__nothrow__)) ;
extern int getsubopt (char **__restrict __optionp,
        char *__const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__)) ;
extern void setkey (__const char *__key) __attribute__ ((__nothrow__)) ;
extern int posix_openpt (int __oflag) ;
extern int grantpt (int __fd) __attribute__ ((__nothrow__));
extern int unlockpt (int __fd) __attribute__ ((__nothrow__));
extern char *ptsname (int __fd) __attribute__ ((__nothrow__)) ;
extern int ptsname_r (int __fd, char *__buf, unsigned int __buflen)
     __attribute__ ((__nothrow__)) ;
extern int getpt (void);
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__)) ;


extern __typeof (strtol_l) __strtol_l;
extern __typeof (strtoul_l) __strtoul_l;
extern __typeof (strtoll_l) __strtoll_l;
extern __typeof (strtoull_l) __strtoull_l;
extern __typeof (strtod_l) __strtod_l;
extern __typeof (strtof_l) __strtof_l;
extern __typeof (strtold_l) __strtold_l;
















extern long int __random (void);
extern void __srandom (unsigned int __seed);
extern char *__initstate (unsigned int __seed, char *__statebuf,
     unsigned int __statelen);
extern char *__setstate (char *__statebuf);
extern int __random_r (struct random_data *__buf, int32_t *__result);
extern int __srandom_r (unsigned int __seed, struct random_data *__buf);
extern int __initstate_r (unsigned int __seed, char *__statebuf,
     unsigned int __statelen, struct random_data *__buf);
extern int __setstate_r (char *__statebuf, struct random_data *__buf);
extern int __rand_r (unsigned int *__seed);
extern int __erand48_r (unsigned short int __xsubi[3],
   struct drand48_data *__buffer, double *__result);
extern int __nrand48_r (unsigned short int __xsubi[3],
   struct drand48_data *__buffer,
   long int *__result);
extern int __jrand48_r (unsigned short int __xsubi[3],
   struct drand48_data *__buffer,
   long int *__result);
extern int __srand48_r (long int __seedval,
   struct drand48_data *__buffer);
extern int __seed48_r (unsigned short int __seed16v[3],
         struct drand48_data *__buffer);
extern int __lcong48_r (unsigned short int __param[7],
   struct drand48_data *__buffer);
extern int __drand48_iterate (unsigned short int __xsubi[3],
         struct drand48_data *__buffer);
extern struct drand48_data __libc_drand48_data ;
extern int __setenv (__const char *__name, __const char *__value,
       int __replace);
extern int __unsetenv (__const char *__name);
extern int __clearenv (void);
extern char *__canonicalize_file_name (__const char *__name);
extern char *__realpath (__const char *__name, char *__resolved);
extern int __ptsname_r (int __fd, char *__buf, unsigned int __buflen);
extern int __getpt (void);
extern int __posix_openpt (int __oflag);
extern int __add_to_environ (const char *name, const char *value,
        const char *combines, int replace);
extern void _quicksort (void *const pbase, unsigned int total_elems,
   unsigned int size, __compar_d_fn_t cmp, void *arg);
extern int __on_exit (void (*__func) (int __status, void *__arg), void *__arg);
extern int __cxa_atexit (void (*func) (void *), void *arg, void *d);
extern int __cxa_atexit_internal (void (*func) (void *), void *arg, void *d)
     ;
extern void __cxa_finalize (void *d);
extern int __posix_memalign (void **memptr, unsigned int alignment, unsigned int size);
extern void *__libc_memalign (size_t alignment, unsigned int size)
     __attribute__ ((__malloc__));
extern int __libc_system (const char *line);
extern double __strtod_internal (__const char *__restrict __nptr,
     char **__restrict __endptr, int __group)
     __attribute__ ((__nothrow__)) ;
extern float __strtof_internal (__const char *__restrict __nptr,
    char **__restrict __endptr, int __group)
     __attribute__ ((__nothrow__)) ;
extern long double __strtold_internal (__const char *__restrict __nptr,
           char **__restrict __endptr,
           int __group)
     __attribute__ ((__nothrow__)) ;
extern long int __strtol_internal (__const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, int __group)
     __attribute__ ((__nothrow__)) ;
extern unsigned long int __strtoul_internal (__const char *__restrict __nptr,
          char **__restrict __endptr,
          int __base, int __group)
     __attribute__ ((__nothrow__)) ;
__extension__
extern long long int __strtoll_internal (__const char *__restrict __nptr,
      char **__restrict __endptr,
      int __base, int __group)
     __attribute__ ((__nothrow__)) ;
__extension__
extern unsigned long long int __strtoull_internal (__const char *
         __restrict __nptr,
         char **__restrict __endptr,
         int __base, int __group)
     __attribute__ ((__nothrow__)) ;







extern double ____strtod_l_internal (__const char *__restrict __nptr,
         char **__restrict __endptr, int __group,
         __locale_t __loc);
extern float ____strtof_l_internal (__const char *__restrict __nptr,
        char **__restrict __endptr, int __group,
        __locale_t __loc);
extern long double ____strtold_l_internal (__const char *__restrict __nptr,
        char **__restrict __endptr,
        int __group, __locale_t __loc);
extern long int ____strtol_l_internal (__const char *__restrict __nptr,
           char **__restrict __endptr,
           int __base, int __group,
           __locale_t __loc);
extern unsigned long int ____strtoul_l_internal (__const char *
       __restrict __nptr,
       char **__restrict __endptr,
       int __base, int __group,
       __locale_t __loc);
__extension__
extern long long int ____strtoll_l_internal (__const char *__restrict __nptr,
          char **__restrict __endptr,
          int __base, int __group,
          __locale_t __loc);
__extension__
extern unsigned long long int ____strtoull_l_internal (__const char *
             __restrict __nptr,
             char **
             __restrict __endptr,
             int __base, int __group,
             __locale_t __loc);














extern char *__ecvt (double __value, int __ndigit, int *__restrict __decpt,
       int *__restrict __sign);
extern char *__fcvt (double __value, int __ndigit, int *__restrict __decpt,
       int *__restrict __sign);
extern char *__gcvt (double __value, int __ndigit, char *__buf);
extern int __ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
       int *__restrict __sign, char *__restrict __buf,
       unsigned int __len);
extern int __fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
       int *__restrict __sign, char *__restrict __buf,
       unsigned int __len);
extern char *__qecvt (long double __value, int __ndigit,
        int *__restrict __decpt, int *__restrict __sign);
extern char *__qfcvt (long double __value, int __ndigit,
        int *__restrict __decpt, int *__restrict __sign);
extern char *__qgcvt (long double __value, int __ndigit, char *__buf);
extern int __qecvt_r (long double __value, int __ndigit,
        int *__restrict __decpt, int *__restrict __sign,
        char *__restrict __buf, unsigned int __len);
extern int __qfcvt_r (long double __value, int __ndigit,
        int *__restrict __decpt, int *__restrict __sign,
        char *__restrict __buf, unsigned int __len);
extern void *__default_morecore (ptrdiff_t) __attribute__ ((__nothrow__));



typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
extern int access (__const char *__name, int __type) __attribute__ ((__nothrow__)) ;
extern int euidaccess (__const char *__name, int __type)
     __attribute__ ((__nothrow__)) ;
extern int eaccess (__const char *__name, int __type)
     __attribute__ ((__nothrow__)) ;
extern int faccessat (int __fd, __const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__)) ;
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__));
extern __off64_t lseek64 (int __fd, __off64_t __offset, int __whence)
     __attribute__ ((__nothrow__));
extern int close (int __fd);
extern ssize_t read (int __fd, void *__buf, unsigned int __nbytes) ;
extern ssize_t write (int __fd, __const void *__buf, unsigned int __n) ;
extern ssize_t pread (int __fd, void *__buf, unsigned int __nbytes,
        __off_t __offset) ;
extern ssize_t pwrite (int __fd, __const void *__buf, unsigned int __n,
         __off_t __offset) ;
extern ssize_t pread64 (int __fd, void *__buf, unsigned int __nbytes,
   __off64_t __offset) ;
extern ssize_t pwrite64 (int __fd, __const void *__buf, unsigned int __n,
    __off64_t __offset) ;
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__)) ;
extern int pipe2 (int __pipedes[2], int __flags) __attribute__ ((__nothrow__)) ;
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__));
extern unsigned int sleep (unsigned int __seconds);
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__));
extern int usleep (__useconds_t __useconds);
extern int pause (void);
extern int chown (__const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__)) ;
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__)) ;
extern int lchown (__const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__)) ;
extern int fchownat (int __fd, __const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__)) ;
extern int chdir (__const char *__path) __attribute__ ((__nothrow__)) ;
extern int fchdir (int __fd) __attribute__ ((__nothrow__)) ;
extern char *getcwd (char *__buf, unsigned int __size) __attribute__ ((__nothrow__)) ;
extern char *get_current_dir_name (void) __attribute__ ((__nothrow__));
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__)) ;
extern int dup (int __fd) __attribute__ ((__nothrow__)) ;
extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__));
extern int dup3 (int __fd, int __fd2, int __flags) __attribute__ ((__nothrow__));
extern char **__environ;
extern char **environ;
extern int execve (__const char *__path, char *__const __argv[],
     char *__const __envp[]) __attribute__ ((__nothrow__)) ;
extern int fexecve (int __fd, char *__const __argv[], char *__const __envp[])
     __attribute__ ((__nothrow__));
extern int execv (__const char *__path, char *__const __argv[])
     __attribute__ ((__nothrow__)) ;
extern int execle (__const char *__path, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) ;
extern int execl (__const char *__path, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) ;
extern int execvp (__const char *__file, char *__const __argv[])
     __attribute__ ((__nothrow__)) ;
extern int execlp (__const char *__file, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) ;
extern int nice (int __inc) __attribute__ ((__nothrow__)) ;
extern void _exit (int __status) __attribute__ ((__noreturn__));
enum
  {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
  };
enum
  {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS
  };
enum
  {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS
  };
extern long int pathconf (__const char *__path, int __name)
     __attribute__ ((__nothrow__)) ;
extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__));
extern long int sysconf (int __name) __attribute__ ((__nothrow__));
extern unsigned int confstr (int __name, char *__buf, unsigned int __len) __attribute__ ((__nothrow__));
extern __pid_t getpid (void) __attribute__ ((__nothrow__));
extern __pid_t getppid (void) __attribute__ ((__nothrow__));
extern __pid_t getpgrp (void) __attribute__ ((__nothrow__));
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__));
extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__));
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__));
extern int setpgrp (void) __attribute__ ((__nothrow__));
extern __pid_t setsid (void) __attribute__ ((__nothrow__));
extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__));
extern __uid_t getuid (void) __attribute__ ((__nothrow__));
extern __uid_t geteuid (void) __attribute__ ((__nothrow__));
extern __gid_t getgid (void) __attribute__ ((__nothrow__));
extern __gid_t getegid (void) __attribute__ ((__nothrow__));
extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__)) ;
extern int group_member (__gid_t __gid) __attribute__ ((__nothrow__));
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__));
extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__));
extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__));
extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__));
extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__));
extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__));
extern int getresuid (__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid)
     __attribute__ ((__nothrow__));
extern int getresgid (__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid)
     __attribute__ ((__nothrow__));
extern int setresuid (__uid_t __ruid, __uid_t __euid, __uid_t __suid)
     __attribute__ ((__nothrow__));
extern int setresgid (__gid_t __rgid, __gid_t __egid, __gid_t __sgid)
     __attribute__ ((__nothrow__));
extern __pid_t fork (void) __attribute__ ((__nothrow__));
extern __pid_t vfork (void) __attribute__ ((__nothrow__));
extern char *ttyname (int __fd) __attribute__ ((__nothrow__));
extern int ttyname_r (int __fd, char *__buf, unsigned int __buflen)
     __attribute__ ((__nothrow__)) ;
extern int isatty (int __fd) __attribute__ ((__nothrow__));
extern int ttyslot (void) __attribute__ ((__nothrow__));
extern int link (__const char *__from, __const char *__to)
     __attribute__ ((__nothrow__)) ;
extern int linkat (int __fromfd, __const char *__from, int __tofd,
     __const char *__to, int __flags)
     __attribute__ ((__nothrow__)) ;
extern int symlink (__const char *__from, __const char *__to)
     __attribute__ ((__nothrow__)) ;
extern ssize_t readlink (__const char *__restrict __path,
    char *__restrict __buf, unsigned int __len)
     __attribute__ ((__nothrow__)) ;
extern int symlinkat (__const char *__from, int __tofd,
        __const char *__to) __attribute__ ((__nothrow__)) ;
extern ssize_t readlinkat (int __fd, __const char *__restrict __path,
      char *__restrict __buf, unsigned int __len)
     __attribute__ ((__nothrow__)) ;
extern int unlink (__const char *__name) __attribute__ ((__nothrow__)) ;
extern int unlinkat (int __fd, __const char *__name, int __flag)
     __attribute__ ((__nothrow__)) ;
extern int rmdir (__const char *__path) __attribute__ ((__nothrow__)) ;
extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__));
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__));
extern char *getlogin (void);
extern int getlogin_r (char *__name, unsigned int __name_len) ;
extern int setlogin (__const char *__name) __attribute__ ((__nothrow__)) ;
extern int gethostname (char *__name, unsigned int __len) __attribute__ ((__nothrow__)) ;
extern int sethostname (__const char *__name, unsigned int __len)
     __attribute__ ((__nothrow__)) ;
extern int sethostid (long int __id) __attribute__ ((__nothrow__)) ;
extern int getdomainname (char *__name, unsigned int __len)
     __attribute__ ((__nothrow__)) ;
extern int setdomainname (__const char *__name, unsigned int __len)
     __attribute__ ((__nothrow__)) ;
extern int vhangup (void) __attribute__ ((__nothrow__));
extern int revoke (__const char *__file) __attribute__ ((__nothrow__)) ;
extern int profil (unsigned short int *__sample_buffer, unsigned int __size,
     unsigned int __offset, unsigned int __scale)
     __attribute__ ((__nothrow__)) ;
extern int acct (__const char *__name) __attribute__ ((__nothrow__));
extern char *getusershell (void) __attribute__ ((__nothrow__));
extern void endusershell (void) __attribute__ ((__nothrow__));
extern void setusershell (void) __attribute__ ((__nothrow__));
extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__)) ;
extern int chroot (__const char *__path) __attribute__ ((__nothrow__)) ;
extern char *getpass (__const char *__prompt) ;
extern int fsync (int __fd);
extern long int gethostid (void);
extern void sync (void) __attribute__ ((__nothrow__));
extern int getpagesize (void) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int getdtablesize (void) __attribute__ ((__nothrow__));
extern int truncate (__const char *__file, __off_t __length)
     __attribute__ ((__nothrow__)) ;
extern int truncate64 (__const char *__file, __off64_t __length)
     __attribute__ ((__nothrow__)) ;
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__)) ;
extern int ftruncate64 (int __fd, __off64_t __length) __attribute__ ((__nothrow__)) ;
extern int brk (void *__addr) __attribute__ ((__nothrow__)) ;
extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__));
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__));
extern int lockf (int __fd, int __cmd, __off_t __len) ;
extern int lockf64 (int __fd, int __cmd, __off64_t __len) ;
extern int fdatasync (int __fildes);
extern char *crypt (__const char *__key, __const char *__salt)
     __attribute__ ((__nothrow__)) ;
extern void encrypt (char *__block, int __edflag) __attribute__ ((__nothrow__)) ;
extern void swab (__const void *__restrict __from, void *__restrict __to,
    ssize_t __n) __attribute__ ((__nothrow__)) ;
extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
















extern int __access (__const char *__name, int __type);
extern int __euidaccess (__const char *__name, int __type);
extern __off64_t __lseek64 (int __fd, __off64_t __offset, int __whence);
extern __off_t __lseek (int __fd, __off_t __offset, int __whence);

extern __off_t __libc_lseek (int __fd, __off_t __offset, int __whence);
extern __off64_t __libc_lseek64 (int __fd, __off64_t __offset, int __whence);
extern ssize_t __pread (int __fd, void *__buf, unsigned int __nbytes,
   __off_t __offset);
extern ssize_t __libc_pread (int __fd, void *__buf, unsigned int __nbytes,
        __off_t __offset);
extern ssize_t __pread64 (int __fd, void *__buf, unsigned int __nbytes,
     __off64_t __offset);
extern ssize_t __libc_pread64 (int __fd, void *__buf, unsigned int __nbytes,
          __off64_t __offset);
extern ssize_t __pwrite (int __fd, __const void *__buf, unsigned int __n,
    __off_t __offset);
extern ssize_t __libc_pwrite (int __fd, __const void *__buf, unsigned int __n,
         __off_t __offset);
extern ssize_t __pwrite64 (int __fd, __const void *__buf, unsigned int __n,
      __off64_t __offset);

extern ssize_t __libc_pwrite64 (int __fd, __const void *__buf, unsigned int __n,
    __off64_t __offset);
extern ssize_t __libc_read (int __fd, void *__buf, unsigned int __n);

extern ssize_t __libc_write (int __fd, __const void *__buf, unsigned int __n);

extern int __pipe (int __pipedes[2]);

extern int __pipe2 (int __pipedes[2], int __flags);
extern unsigned int __sleep (unsigned int __seconds);
extern int __chown (__const char *__file,
      __uid_t __owner, __gid_t __group);

extern int __fchown (int __fd,
       __uid_t __owner, __gid_t __group);
extern int __lchown (__const char *__file, __uid_t __owner,
       __gid_t __group);
extern int __chdir (__const char *__path);
extern int __fchdir (int __fd);
extern char *__getcwd (char *__buf, unsigned int __size);
extern int __rmdir (const char *__path);
char *__canonicalize_directory_name_internal (__const char *__thisdir,
           char *__buf,
           unsigned int __size) ;
extern int __dup (int __fd);
extern int __dup2 (int __fd, int __fd2);

extern int __execve (__const char *__path, char *__const __argv[],
       char *__const __envp[]);
extern long int __pathconf (__const char *__path, int __name);
extern long int __fpathconf (int __fd, int __name);
extern long int __sysconf (int __name);

extern __pid_t __getpid (void);

extern __pid_t __getppid (void);
extern __pid_t __setsid (void);
extern __uid_t __getuid (void);
extern __uid_t __geteuid (void);
extern __gid_t __getgid (void);
extern __gid_t __getegid (void);
extern int __getgroups (int __size, __gid_t __list[]);

extern int __group_member (__gid_t __gid);
extern int __setuid (__uid_t __uid);
extern int __setreuid (__uid_t __ruid, __uid_t __euid);
extern int __setgid (__gid_t __gid);
extern int __setpgid (__pid_t __pid, __pid_t __pgid);

extern int __setregid (__gid_t __rgid, __gid_t __egid);
extern int __getresuid (__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid);
extern int __getresgid (__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid);
extern int __setresuid (__uid_t __ruid, __uid_t __euid, __uid_t __suid);
extern int __setresgid (__gid_t __rgid, __gid_t __egid, __gid_t __sgid);




extern __pid_t __vfork (void);

extern int __ttyname_r (int __fd, char *__buf, unsigned int __buflen);
extern int __isatty (int __fd);
extern int __link (__const char *__from, __const char *__to);
extern int __symlink (__const char *__from, __const char *__to);
extern int __readlink (__const char *__path, char *__buf, unsigned int __len);
extern int __unlink (__const char *__name);
extern int __gethostname (char *__name, unsigned int __len);
extern int __profil (unsigned short int *__sample_buffer, unsigned int __size,
       unsigned int __offset, unsigned int __scale);
extern int __getdtablesize (void);
extern int __brk (void *__addr);
extern int __close (int __fd);

extern int __libc_close (int __fd);
extern ssize_t __read (int __fd, void *__buf, unsigned int __nbytes);

extern ssize_t __write (int __fd, __const void *__buf, unsigned int __n);

extern __pid_t __fork (void);

extern int __getpagesize (void) __attribute__ ((__const__));

extern int __ftruncate (int __fd, __off_t __length);
extern int __ftruncate64 (int __fd, __off64_t __length);
extern int __truncate (const char *path, __off_t __length);
extern void *__sbrk (intptr_t __delta);

extern int __libc_enable_secure __attribute__ ((section (".data.rel.ro")));
extern int __libc_enable_secure_decided;
extern void __libc_check_standard_fds (void);
extern void __exit_thread (int val) __attribute__ ((noreturn));
extern __pid_t __libc_fork (void);
extern int __libc_pause (void);
extern int __pause_nocancel (void) ;
extern int __have_sock_cloexec;
extern void *__memccpy (void *__dest, __const void *__src,
   int __c, unsigned int __n);
extern unsigned int __strnlen (__const char *__string, unsigned int __maxlen)
     __attribute__ ((__pure__));
extern char *__strsep (char **__stringp, __const char *__delim);
extern int __strverscmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__pure__));
extern int __strncasecmp (__const char *__s1, __const char *__s2,
     unsigned int __n)
     __attribute__ ((__pure__));
extern int __strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__pure__));
extern char *__strcasestr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__pure__));
extern char *__strdup (__const char *__string)
     __attribute__ ((__malloc__));
extern char *__strndup (__const char *__string, unsigned int __n)
     __attribute__ ((__malloc__));
extern void *__rawmemchr (__const void *__s, int __c)
     __attribute__ ((__pure__));
extern char *__strchrnul (__const char *__s, int __c)
     __attribute__ ((__pure__));
extern void *__memrchr (__const void *__s, int __c, unsigned int __n)
     __attribute__ ((__pure__));
extern void *__memchr (__const void *__s, int __c, unsigned int __n)
     __attribute__ ((__pure__));
extern int __ffs (int __i) __attribute__ ((const));
extern char *__strerror_r (int __errnum, char *__buf, unsigned int __buflen);


extern void *memcpy (void *__restrict __dest,
       __const void *__restrict __src, unsigned int __n)
     __attribute__ ((__nothrow__)) ;
extern void *memmove (void *__dest, __const void *__src, unsigned int __n)
     __attribute__ ((__nothrow__)) ;

extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
        int __c, unsigned int __n)
     __attribute__ ((__nothrow__)) ;

extern void *memset (void *__s, int __c, unsigned int __n) __attribute__ ((__nothrow__)) ;
extern int memcmp (__const void *__s1, __const void *__s2, unsigned int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern void *memchr (__const void *__s, int __c, unsigned int __n)
      __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;

extern void *rawmemchr (__const void *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern void *memrchr (__const void *__s, int __c, unsigned int __n)
      __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;

extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) ;
extern char *strncpy (char *__restrict __dest,
        __const char *__restrict __src, unsigned int __n)
     __attribute__ ((__nothrow__)) ;
extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) ;
extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
        unsigned int __n) __attribute__ ((__nothrow__)) ;
extern int strcmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern int strncmp (__const char *__s1, __const char *__s2, unsigned int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern int strcoll (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern unsigned int strxfrm (char *__restrict __dest,
         __const char *__restrict __src, unsigned int __n)
     __attribute__ ((__nothrow__)) ;

extern int strcoll_l (__const char *__s1, __const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern unsigned int strxfrm_l (char *__dest, __const char *__src, unsigned int __n,
    __locale_t __l) __attribute__ ((__nothrow__)) ;
extern char *strdup (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern char *strndup (__const char *__string, unsigned int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;

extern char *strchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern char *strrchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;

extern char *strchrnul (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;

extern unsigned int strcspn (__const char *__s, __const char *__reject)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern unsigned int strspn (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern char *strpbrk (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern char *strstr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) ;

extern char *__strtok_r (char *__restrict __s,
    __const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) ;
extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) ;
extern char *strcasestr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern void *memmem (__const void *__haystack, unsigned int __haystacklen,
       __const void *__needle, unsigned int __needlelen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern void *__mempcpy (void *__restrict __dest,
   __const void *__restrict __src, unsigned int __n)
     __attribute__ ((__nothrow__)) ;
extern void *mempcpy (void *__restrict __dest,
        __const void *__restrict __src, unsigned int __n)
     __attribute__ ((__nothrow__)) ;

extern unsigned int strlen (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;

extern unsigned int strnlen (__const char *__string, unsigned int __maxlen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;

extern char *strerror (int __errnum) __attribute__ ((__nothrow__));

extern char *strerror_r (int __errnum, char *__buf, unsigned int __buflen)
     __attribute__ ((__nothrow__)) ;
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__));
extern void __bzero (void *__s, unsigned int __n) __attribute__ ((__nothrow__)) ;
extern void bcopy (__const void *__src, void *__dest, unsigned int __n)
     __attribute__ ((__nothrow__)) ;
extern void bzero (void *__s, unsigned int __n) __attribute__ ((__nothrow__)) ;
extern int bcmp (__const void *__s1, __const void *__s2, unsigned int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern char *index (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern char *rindex (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern int ffs (int __i) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int ffsl (long int __l) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern int strncasecmp (__const char *__s1, __const char *__s2, unsigned int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern int strcasecmp_l (__const char *__s1, __const char *__s2,
    __locale_t __loc)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern int strncasecmp_l (__const char *__s1, __const char *__s2,
     unsigned int __n, __locale_t __loc)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern char *strsep (char **__restrict __stringp,
       __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) ;
extern int strverscmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) ;
extern char *strsignal (int __sig) __attribute__ ((__nothrow__));
extern char *__stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) ;
extern char *stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) ;
extern char *__stpncpy (char *__restrict __dest,
   __const char *__restrict __src, unsigned int __n)
     __attribute__ ((__nothrow__)) ;
extern char *stpncpy (char *__restrict __dest,
        __const char *__restrict __src, unsigned int __n)
     __attribute__ ((__nothrow__)) ;
extern char *strfry (char *__string) __attribute__ ((__nothrow__)) ;
extern void *memfrob (void *__s, unsigned int __n) __attribute__ ((__nothrow__)) ;
extern char *basename (__const char *__filename) __attribute__ ((__nothrow__)) ;
extern void *__rawmemchr (const void *__s, int __c);
extern __inline unsigned int __strcspn_c1 (__const char *__s, int __reject);
extern __inline size_t
__strcspn_c1 (__const char *__s, int __reject)
{
  register unsigned int __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject)
    ++__result;
  return __result;
}
extern __inline unsigned int __strcspn_c2 (__const char *__s, int __reject1,
         int __reject2);
extern __inline size_t
__strcspn_c2 (__const char *__s, int __reject1, int __reject2)
{
  register unsigned int __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject1
  && __s[__result] != __reject2)
    ++__result;
  return __result;
}
extern __inline unsigned int __strcspn_c3 (__const char *__s, int __reject1,
         int __reject2, int __reject3);
extern __inline size_t
__strcspn_c3 (__const char *__s, int __reject1, int __reject2,
       int __reject3)
{
  register unsigned int __result = 0;
  while (__s[__result] != '\0' && __s[__result] != __reject1
  && __s[__result] != __reject2 && __s[__result] != __reject3)
    ++__result;
  return __result;
}
extern __inline unsigned int __strspn_c1 (__const char *__s, int __accept);
extern __inline size_t
__strspn_c1 (__const char *__s, int __accept)
{
  register unsigned int __result = 0;
  while (__s[__result] == __accept)
    ++__result;
  return __result;
}
extern __inline unsigned int __strspn_c2 (__const char *__s, int __accept1,
        int __accept2);
extern __inline size_t
__strspn_c2 (__const char *__s, int __accept1, int __accept2)
{
  register unsigned int __result = 0;
  while (__s[__result] == __accept1 || __s[__result] == __accept2)
    ++__result;
  return __result;
}
extern __inline unsigned int __strspn_c3 (__const char *__s, int __accept1,
        int __accept2, int __accept3);
extern __inline size_t
__strspn_c3 (__const char *__s, int __accept1, int __accept2, int __accept3)
{
  register unsigned int __result = 0;
  while (__s[__result] == __accept1 || __s[__result] == __accept2
  || __s[__result] == __accept3)
    ++__result;
  return __result;
}
extern __inline char *__strpbrk_c2 (__const char *__s, int __accept1,
         int __accept2);
extern __inline char *
__strpbrk_c2 (__const char *__s, int __accept1, int __accept2)
{
  while (*__s != '\0' && *__s != __accept1 && *__s != __accept2)
    ++__s;
  return *__s == '\0' ? ((void *)0) : (char *) (unsigned int) __s;
}
extern __inline char *__strpbrk_c3 (__const char *__s, int __accept1,
         int __accept2, int __accept3);
extern __inline char *
__strpbrk_c3 (__const char *__s, int __accept1, int __accept2,
       int __accept3)
{
  while (*__s != '\0' && *__s != __accept1 && *__s != __accept2
  && *__s != __accept3)
    ++__s;
  return *__s == '\0' ? ((void *)0) : (char *) (unsigned int) __s;
}
extern __inline char *__strtok_r_1c (char *__s, char __sep, char **__nextp);
extern __inline char *
__strtok_r_1c (char *__s, char __sep, char **__nextp)
{
  char *__result;
  if (__s == ((void *)0))
    __s = *__nextp;
  while (*__s == __sep)
    ++__s;
  __result = ((void *)0);
  if (*__s != '\0')
    {
      __result = __s++;
      while (*__s != '\0')
 if (*__s++ == __sep)
   {
     __s[-1] = '\0';
     break;
   }
    }
  *__nextp = __s;
  return __result;
}
extern char *__strsep_g (char **__stringp, __const char *__delim);
extern __inline char *__strsep_1c (char **__s, char __reject);
extern __inline char *
__strsep_1c (char **__s, char __reject)
{
  register char *__retval = *__s;
  if (__retval != ((void *)0) && (*__s = (__extension__ (__builtin_constant_p (__reject) && !__builtin_constant_p (__retval) && (__reject) == '\0' ? (char *) __rawmemchr (__retval, __reject) : __builtin_strchr (__retval, __reject)))) != ((void *)0))
    *(*__s)++ = '\0';
  return __retval;
}
extern __inline char *__strsep_2c (char **__s, char __reject1, char __reject2);
extern __inline char *
__strsep_2c (char **__s, char __reject1, char __reject2)
{
  register char *__retval = *__s;
  if (__retval != ((void *)0))
    {
      register char *__cp = __retval;
      while (1)
 {
   if (*__cp == '\0')
     {
       __cp = ((void *)0);
   break;
     }
   if (*__cp == __reject1 || *__cp == __reject2)
     {
       *__cp++ = '\0';
       break;
     }
   ++__cp;
 }
      *__s = __cp;
    }
  return __retval;
}
extern __inline char *__strsep_3c (char **__s, char __reject1, char __reject2,
       char __reject3);
extern __inline char *
__strsep_3c (char **__s, char __reject1, char __reject2, char __reject3)
{
  register char *__retval = *__s;
  if (__retval != ((void *)0))
    {
      register char *__cp = __retval;
      while (1)
 {
   if (*__cp == '\0')
     {
       __cp = ((void *)0);
   break;
     }
   if (*__cp == __reject1 || *__cp == __reject2 || *__cp == __reject3)
     {
       *__cp++ = '\0';
       break;
     }
   ++__cp;
 }
      *__s = __cp;
    }
  return __retval;
}
extern char *__strdup (__const char *__string) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__));
extern char *__strndup (__const char *__string, unsigned int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__));

extern __typeof (strcoll_l) __strcoll_l;
extern __typeof (strxfrm_l) __strxfrm_l;
extern __typeof (strcasecmp_l) __strcasecmp_l;
extern __typeof (strncasecmp_l) __strncasecmp_l;
















extern char *__strsep_g (char **__stringp, __const char *__delim);






















extern void *__memcpy_chk (void *__restrict __dest,
      const void *__restrict __src, unsigned int __len,
      unsigned int __destlen) __attribute__ ((__nothrow__));
extern void *__memmove_chk (void *__dest, const void *__src, unsigned int __len,
       unsigned int __destlen) __attribute__ ((__nothrow__));
extern void *__mempcpy_chk (void *__restrict __dest,
       const void *__restrict __src, unsigned int __len,
       unsigned int __destlen) __attribute__ ((__nothrow__));
extern void *__memset_chk (void *__dest, int __ch, unsigned int __len,
      unsigned int __destlen) __attribute__ ((__nothrow__));
extern char *__strcpy_chk (char *__restrict __dest,
      const char *__restrict __src,
      unsigned int __destlen) __attribute__ ((__nothrow__));
extern char *__stpcpy_chk (char *__restrict __dest,
      const char *__restrict __src,
      unsigned int __destlen) __attribute__ ((__nothrow__));
extern char *__strncpy_chk (char *__restrict __dest,
       const char *__restrict __src,
       unsigned int __len, unsigned int __destlen) __attribute__ ((__nothrow__));
extern char *__strcat_chk (char *__restrict __dest,
      const char *__restrict __src,
      unsigned int __destlen) __attribute__ ((__nothrow__));
extern char *__strncat_chk (char *__restrict __dest,
       const char *__restrict __src,
       unsigned int __len, unsigned int __destlen) __attribute__ ((__nothrow__));

extern char *gettext (__const char *__msgid)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (1)));
extern char *dgettext (__const char *__domainname, __const char *__msgid)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2)));
extern char *__dgettext (__const char *__domainname, __const char *__msgid)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2)));
extern char *dcgettext (__const char *__domainname,
   __const char *__msgid, int __category)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2)));
extern char *__dcgettext (__const char *__domainname,
     __const char *__msgid, int __category)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2)));
extern char *ngettext (__const char *__msgid1, __const char *__msgid2,
         unsigned long int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (1))) __attribute__ ((__format_arg__ (2)));
extern char *dngettext (__const char *__domainname, __const char *__msgid1,
   __const char *__msgid2, unsigned long int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2))) __attribute__ ((__format_arg__ (3)));
extern char *dcngettext (__const char *__domainname, __const char *__msgid1,
    __const char *__msgid2, unsigned long int __n,
    int __category)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2))) __attribute__ ((__format_arg__ (3)));
extern char *textdomain (__const char *__domainname) __attribute__ ((__nothrow__));
extern char *bindtextdomain (__const char *__domainname,
        __const char *__dirname) __attribute__ ((__nothrow__));
extern char *bind_textdomain_codeset (__const char *__domainname,
          __const char *__codeset) __attribute__ ((__nothrow__));
enum
{
  __LC_CTYPE = 0,
  __LC_NUMERIC = 1,
  __LC_TIME = 2,
  __LC_COLLATE = 3,
  __LC_MONETARY = 4,
  __LC_MESSAGES = 5,
  __LC_ALL = 6,
  __LC_PAPER = 7,
  __LC_NAME = 8,
  __LC_ADDRESS = 9,
  __LC_TELEPHONE = 10,
  __LC_MEASUREMENT = 11,
  __LC_IDENTIFICATION = 12
};


struct lconv
{
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_p_cs_precedes;
  char int_p_sep_by_space;
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;
};
extern char *setlocale (int __category, __const char *__locale) __attribute__ ((__nothrow__));
extern struct lconv *localeconv (void) __attribute__ ((__nothrow__));

typedef __locale_t locale_t;
extern __locale_t newlocale (int __category_mask, __const char *__locale,
        __locale_t __base) __attribute__ ((__nothrow__));
extern __locale_t duplocale (__locale_t __dataset) __attribute__ ((__nothrow__));
extern void freelocale (__locale_t __dataset) __attribute__ ((__nothrow__));
extern __locale_t uselocale (__locale_t __dataset) __attribute__ ((__nothrow__));

extern __typeof (uselocale) __uselocale;


extern struct loaded_l10nfile *_nl_locale_file_list[] ;
extern const struct __locale_struct _nl_C_locobj ;
extern struct lconv *__localeconv (void);
extern const char *__current_locale_name (int category) ;

extern char *__gettext (__const char *__msgid)
     __attribute__ ((__format_arg__ (1)));
extern char *__dgettext (__const char *__domainname,
    __const char *__msgid)
     __attribute__ ((__format_arg__ (2)));
extern char *__dcgettext (__const char *__domainname,
     __const char *__msgid, int __category)
     __attribute__ ((__format_arg__ (2)));

extern char *__dcgettext_internal (__const char *__domainname,
       __const char *__msgid, int __category)
     __attribute__ ((__format_arg__ (2)))
     ;
extern char *__ngettext (__const char *__msgid1, __const char *__msgid2,
    unsigned long int __n)
     __attribute__ ((__format_arg__ (1))) __attribute__ ((__format_arg__ (2)));
extern char *__dngettext (__const char *__domainname,
     __const char *__msgid1, __const char *__msgid2,
     unsigned long int __n)
     __attribute__ ((__format_arg__ (2))) __attribute__ ((__format_arg__ (3)));
extern char *__dcngettext (__const char *__domainname,
      __const char *__msgid1, __const char *__msgid2,
      unsigned long int __n, int __category)
     __attribute__ ((__format_arg__ (2))) __attribute__ ((__format_arg__ (3)));
extern char *__dcngettext_internal (__const char *__domainname,
        __const char *__msgid1,
        __const char *__msgid2,
        unsigned long int __n, int __category)
     __attribute__ ((__format_arg__ (2))) __attribute__ ((__format_arg__ (3)))
     ;
extern char *__textdomain (__const char *__domainname);
extern char *__bindtextdomain (__const char *__domainname,
          __const char *__dirname);
extern char *__bind_textdomain_codeset (__const char *__domainname,
     __const char *__codeset);
extern const char _libc_intl_domainname[];


typedef __mbstate_t mbstate_t;




struct tm;



extern wchar_t *wcscpy (wchar_t *__restrict __dest,
   __const wchar_t *__restrict __src) __attribute__ ((__nothrow__));
extern wchar_t *wcsncpy (wchar_t *__restrict __dest,
    __const wchar_t *__restrict __src, unsigned int __n)
     __attribute__ ((__nothrow__));
extern wchar_t *wcscat (wchar_t *__restrict __dest,
   __const wchar_t *__restrict __src) __attribute__ ((__nothrow__));
extern wchar_t *wcsncat (wchar_t *__restrict __dest,
    __const wchar_t *__restrict __src, unsigned int __n)
     __attribute__ ((__nothrow__));
extern int wcscmp (__const wchar_t *__s1, __const wchar_t *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern int wcsncmp (__const wchar_t *__s1, __const wchar_t *__s2, unsigned int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));

extern int wcscasecmp (__const wchar_t *__s1, __const wchar_t *__s2) __attribute__ ((__nothrow__));
extern int wcsncasecmp (__const wchar_t *__s1, __const wchar_t *__s2,
   unsigned int __n) __attribute__ ((__nothrow__));
extern int wcscasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2,
    __locale_t __loc) __attribute__ ((__nothrow__));
extern int wcsncasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2,
     unsigned int __n, __locale_t __loc) __attribute__ ((__nothrow__));

extern int wcscoll (__const wchar_t *__s1, __const wchar_t *__s2) __attribute__ ((__nothrow__));
extern unsigned int wcsxfrm (wchar_t *__restrict __s1,
         __const wchar_t *__restrict __s2, unsigned int __n) __attribute__ ((__nothrow__));

extern int wcscoll_l (__const wchar_t *__s1, __const wchar_t *__s2,
        __locale_t __loc) __attribute__ ((__nothrow__));
extern unsigned int wcsxfrm_l (wchar_t *__s1, __const wchar_t *__s2,
    unsigned int __n, __locale_t __loc) __attribute__ ((__nothrow__));
extern wchar_t *wcsdup (__const wchar_t *__s) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__));

extern wchar_t *wcschr (__const wchar_t *__wcs, wchar_t __wc)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern wchar_t *wcsrchr (__const wchar_t *__wcs, wchar_t __wc)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));

extern wchar_t *wcschrnul (__const wchar_t *__s, wchar_t __wc)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));

extern unsigned int wcscspn (__const wchar_t *__wcs, __const wchar_t *__reject)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern unsigned int wcsspn (__const wchar_t *__wcs, __const wchar_t *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern wchar_t *wcspbrk (__const wchar_t *__wcs, __const wchar_t *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern wchar_t *wcsstr (__const wchar_t *__haystack, __const wchar_t *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern wchar_t *wcstok (wchar_t *__restrict __s,
   __const wchar_t *__restrict __delim,
   wchar_t **__restrict __ptr) __attribute__ ((__nothrow__));
extern unsigned int wcslen (__const wchar_t *__s) __attribute__ ((__nothrow__)) __attribute__ ((__pure__));

extern wchar_t *wcswcs (__const wchar_t *__haystack, __const wchar_t *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern unsigned int wcsnlen (__const wchar_t *__s, unsigned int __maxlen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));

extern wchar_t *wmemchr (__const wchar_t *__s, wchar_t __c, unsigned int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern int wmemcmp (__const wchar_t *__restrict __s1,
      __const wchar_t *__restrict __s2, unsigned int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern wchar_t *wmemcpy (wchar_t *__restrict __s1,
    __const wchar_t *__restrict __s2, unsigned int __n) __attribute__ ((__nothrow__));
extern wchar_t *wmemmove (wchar_t *__s1, __const wchar_t *__s2, unsigned int __n)
     __attribute__ ((__nothrow__));
extern wchar_t *wmemset (wchar_t *__s, wchar_t __c, unsigned int __n) __attribute__ ((__nothrow__));

extern wchar_t *wmempcpy (wchar_t *__restrict __s1,
     __const wchar_t *__restrict __s2, unsigned int __n)
     __attribute__ ((__nothrow__));

extern wint_t btowc (int __c) __attribute__ ((__nothrow__));
extern int wctob (wint_t __c) __attribute__ ((__nothrow__));
extern int mbsinit (__const mbstate_t *__ps) __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
extern unsigned int mbrtowc (wchar_t *__restrict __pwc,
         __const char *__restrict __s, unsigned int __n,
         mbstate_t *__p) __attribute__ ((__nothrow__));
extern unsigned int wcrtomb (char *__restrict __s, wchar_t __wc,
         mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));
extern unsigned int __mbrlen (__const char *__restrict __s, unsigned int __n,
   mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));
extern unsigned int mbrlen (__const char *__restrict __s, unsigned int __n,
        mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));

extern wint_t __btowc_alias (int __c) __asm ("btowc");
extern __inline wint_t
__attribute__ ((__nothrow__)) btowc (int __c)
{ return (__builtin_constant_p (__c) && __c >= '\0' && __c <= '\x7f'
   ? (wint_t) __c : __btowc_alias (__c)); }
extern int __wctob_alias (wint_t __c) __asm ("wctob");
extern __inline int
__attribute__ ((__nothrow__)) wctob (wint_t __wc)
{ return (__builtin_constant_p (__wc) && __wc >= L'\0' && __wc <= L'\x7f'
   ? (int) __wc : __wctob_alias (__wc)); }
extern __inline size_t
__attribute__ ((__nothrow__)) mbrlen (__const char *__restrict __s, unsigned int __n, mbstate_t *__restrict __ps)
{ return (__ps != ((void *)0)
   ? mbrtowc (((void *)0), __s, __n, __ps) : __mbrlen (__s, __n, ((void *)0))); }

extern unsigned int mbsrtowcs (wchar_t *__restrict __dst,
    __const char **__restrict __src, unsigned int __len,
    mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));
extern unsigned int wcsrtombs (char *__restrict __dst,
    __const wchar_t **__restrict __src, unsigned int __len,
    mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));

extern unsigned int mbsnrtowcs (wchar_t *__restrict __dst,
     __const char **__restrict __src, unsigned int __nmc,
     unsigned int __len, mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));
extern unsigned int wcsnrtombs (char *__restrict __dst,
     __const wchar_t **__restrict __src,
     unsigned int __nwc, unsigned int __len,
     mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));
extern int wcwidth (wchar_t __c) __attribute__ ((__nothrow__));
extern int wcswidth (__const wchar_t *__s, unsigned int __n) __attribute__ ((__nothrow__));

extern double wcstod (__const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr) __attribute__ ((__nothrow__));


extern float wcstof (__const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__));
extern long double wcstold (__const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__));


extern long int wcstol (__const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, int __base) __attribute__ ((__nothrow__));
extern unsigned long int wcstoul (__const wchar_t *__restrict __nptr,
      wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__));


__extension__
extern long long int wcstoll (__const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int wcstoull (__const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr,
     int __base) __attribute__ ((__nothrow__));

__extension__
extern long long int wcstoq (__const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int wcstouq (__const wchar_t *__restrict __nptr,
           wchar_t **__restrict __endptr,
           int __base) __attribute__ ((__nothrow__));
extern long int wcstol_l (__const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr, int __base,
     __locale_t __loc) __attribute__ ((__nothrow__));
extern unsigned long int wcstoul_l (__const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr,
        int __base, __locale_t __loc) __attribute__ ((__nothrow__));
__extension__
extern long long int wcstoll_l (__const wchar_t *__restrict __nptr,
    wchar_t **__restrict __endptr,
    int __base, __locale_t __loc) __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int wcstoull_l (__const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr,
       int __base, __locale_t __loc)
     __attribute__ ((__nothrow__));
extern double wcstod_l (__const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, __locale_t __loc)
     __attribute__ ((__nothrow__));
extern float wcstof_l (__const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, __locale_t __loc)
     __attribute__ ((__nothrow__));
extern long double wcstold_l (__const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         __locale_t __loc) __attribute__ ((__nothrow__));
extern wchar_t *wcpcpy (wchar_t *__dest, __const wchar_t *__src) __attribute__ ((__nothrow__));
extern wchar_t *wcpncpy (wchar_t *__dest, __const wchar_t *__src, unsigned int __n)
     __attribute__ ((__nothrow__));
extern __FILE *open_wmemstream (wchar_t **__bufloc, unsigned int *__sizeloc) __attribute__ ((__nothrow__));

extern int fwide (__FILE *__fp, int __mode) __attribute__ ((__nothrow__));
extern int fwprintf(__FILE *__restrict __stream,
       __const wchar_t *__restrict __format, ...)
                                                           ;
extern int wprintf(__const wchar_t *__restrict __format, ...)
                                                           ;
extern int swprintf(wchar_t *__restrict __s, unsigned int __n,
       __const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__)) ;
extern int vfwprintf(__FILE *__restrict __s,
        __const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
                                                           ;
extern int vwprintf(__const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                           ;
extern int vswprintf(wchar_t *__restrict __s, unsigned int __n,
        __const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) ;
extern int fwscanf (__FILE *__restrict __stream,
      __const wchar_t *__restrict __format, ...)
                                                          ;
extern int wscanf (__const wchar_t *__restrict __format, ...)
                                                          ;
extern int swscanf (__const wchar_t *__restrict __s,
      __const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__)) ;


extern int vfwscanf (__FILE *__restrict __s,
       __const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                          ;
extern int vwscanf (__const wchar_t *__restrict __format,
      __gnuc_va_list __arg)
                                                          ;
extern int vswscanf (__const wchar_t *__restrict __s,
       __const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) ;


extern wint_t fgetwc (__FILE *__stream);
extern wint_t getwc (__FILE *__stream);
extern wint_t getwchar (void);
extern wint_t fputwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwchar (wchar_t __wc);
extern wchar_t *fgetws (wchar_t *__restrict __ws, int __n,
   __FILE *__restrict __stream);
extern int fputws (__const wchar_t *__restrict __ws,
     __FILE *__restrict __stream);
extern wint_t ungetwc (wint_t __wc, __FILE *__stream);

extern wint_t getwc_unlocked (__FILE *__stream);
extern wint_t getwchar_unlocked (void);
extern wint_t fgetwc_unlocked (__FILE *__stream);
extern wint_t fputwc_unlocked (wchar_t __wc, __FILE *__stream);
extern wint_t putwc_unlocked (wchar_t __wc, __FILE *__stream);
extern wint_t putwchar_unlocked (wchar_t __wc);
extern wchar_t *fgetws_unlocked (wchar_t *__restrict __ws, int __n,
     __FILE *__restrict __stream);
extern int fputws_unlocked (__const wchar_t *__restrict __ws,
       __FILE *__restrict __stream);

extern unsigned int wcsftime (wchar_t *__restrict __s, unsigned int __maxsize,
   __const wchar_t *__restrict __format,
   __const struct tm *__restrict __tp) __attribute__ ((__nothrow__));

extern unsigned int wcsftime_l (wchar_t *__restrict __s, unsigned int __maxsize,
     __const wchar_t *__restrict __format,
     __const struct tm *__restrict __tp,
     __locale_t __loc) __attribute__ ((__nothrow__));

extern __typeof (wcscasecmp_l) __wcscasecmp_l;
extern __typeof (wcsncasecmp_l) __wcsncasecmp_l;
extern __typeof (wcscoll_l) __wcscoll_l;
extern __typeof (wcsxfrm_l) __wcsxfrm_l;
extern __typeof (wcstol_l) __wcstol_l;
extern __typeof (wcstoul_l) __wcstoul_l;
extern __typeof (wcstoll_l) __wcstoll_l;
extern __typeof (wcstoull_l) __wcstoull_l;
extern __typeof (wcstod_l) __wcstod_l;
extern __typeof (wcstof_l) __wcstof_l;
extern __typeof (wcstold_l) __wcstold_l;
extern __typeof (wcsftime_l) __wcsftime_l;








extern double __wcstod_internal (__const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr, int __group)
     __attribute__ ((__nothrow__));
extern float __wcstof_internal (__const wchar_t *__restrict __nptr,
    wchar_t **__restrict __endptr, int __group)
     __attribute__ ((__nothrow__));
extern long double __wcstold_internal (__const wchar_t *__restrict __nptr,
           wchar_t **__restrict __endptr,
           int __group) __attribute__ ((__nothrow__));
extern long int __wcstol_internal (__const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr,
       int __base, int __group) __attribute__ ((__nothrow__));
extern unsigned long int __wcstoul_internal (__const wchar_t *__restrict __npt,
          wchar_t **__restrict __endptr,
          int __base, int __group) __attribute__ ((__nothrow__));
__extension__
extern long long int __wcstoll_internal (__const wchar_t *__restrict __nptr,
      wchar_t **__restrict __endptr,
      int __base, int __group) __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int __wcstoull_internal (__const wchar_t *
         __restrict __nptr,
         wchar_t **
         __restrict __endptr,
         int __base,
         int __group) __attribute__ ((__nothrow__));
































extern int __wcscasecmp (__const wchar_t *__s1, __const wchar_t *__s2)
     __attribute__ ((__pure__));
extern int __wcsncasecmp (__const wchar_t *__s1, __const wchar_t *__s2,
     unsigned int __n)
     __attribute__ ((__pure__));
extern unsigned int __wcslen (__const wchar_t *__s) __attribute__ ((__pure__));
extern unsigned int __wcsnlen (__const wchar_t *__s, unsigned int __maxlen)
     __attribute__ ((__pure__));
extern wchar_t *__wcscat (wchar_t *dest, const wchar_t *src);
extern wint_t __btowc (int __c);
extern int __mbsinit (__const __mbstate_t *__ps);
extern unsigned int __mbrtowc (wchar_t *__restrict __pwc,
    __const char *__restrict __s, unsigned int __n,
    __mbstate_t *__restrict __p);


extern unsigned int __wcrtomb (char *__restrict __s, wchar_t __wc,
    __mbstate_t *__restrict __ps);
extern unsigned int __mbsrtowcs (wchar_t *__restrict __dst,
      __const char **__restrict __src,
      unsigned int __len, __mbstate_t *__restrict __ps);
extern unsigned int __wcsrtombs (char *__restrict __dst,
      __const wchar_t **__restrict __src,
      unsigned int __len, __mbstate_t *__restrict __ps);
extern unsigned int __mbsnrtowcs (wchar_t *__restrict __dst,
       __const char **__restrict __src, unsigned int __nmc,
       unsigned int __len, __mbstate_t *__restrict __ps);
extern unsigned int __wcsnrtombs (char *__restrict __dst,
       __const wchar_t **__restrict __src,
       unsigned int __nwc, unsigned int __len,
       __mbstate_t *__restrict __ps);
extern wchar_t *__wcsncpy (wchar_t *__restrict __dest,
    __const wchar_t *__restrict __src, unsigned int __n);
extern wchar_t *__wcpcpy (wchar_t *__dest, __const wchar_t *__src);
extern wchar_t *__wcpncpy (wchar_t *__dest, __const wchar_t *__src,
      unsigned int __n);
extern wchar_t *__wmemcpy (wchar_t *__s1, __const wchar_t *s2,
      unsigned int __n);
extern wchar_t *__wmempcpy (wchar_t *__restrict __s1,
       __const wchar_t *__restrict __s2,
       unsigned int __n);
extern wchar_t *__wmemmove (wchar_t *__s1, __const wchar_t *__s2,
       unsigned int __n);
extern wchar_t *__wcschrnul (__const wchar_t *__s, wchar_t __wc)
     __attribute__ ((__pure__));
extern int __vfwscanf (__FILE *__restrict __s,
         __const wchar_t *__restrict __format,
         __gnuc_va_list __arg)
                                                         ;
extern int __vswprintf(wchar_t *__restrict __s, unsigned int __n,
   __const wchar_t *__restrict __format,
   __gnuc_va_list __arg)
                                                           ;
extern int __fwprintf(__FILE *__restrict __s,
         __const wchar_t *__restrict __format, ...)
                                                           ;
extern int __vfwprintf(__FILE *__restrict __s,
   __const wchar_t *__restrict __format,
   __gnuc_va_list __arg)
                                                           ;
extern int __vfwprintf_chk (FILE *__restrict __s, int __flag,
       const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                           ;
extern int __vswprintf_chk (wchar_t *__restrict __s, unsigned int __n,
       int __flag, unsigned int __s_len,
       __const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                           ;


extern int __isoc99_fwscanf (__FILE *__restrict __stream,
        __const wchar_t *__restrict __format, ...);
extern int __isoc99_wscanf (__const wchar_t *__restrict __format, ...);
extern int __isoc99_swscanf (__const wchar_t *__restrict __s,
        __const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__));
extern int __isoc99_vfwscanf (__FILE *__restrict __s,
         __const wchar_t *__restrict __format,
         __gnuc_va_list __arg);
extern int __isoc99_vwscanf (__const wchar_t *__restrict __format,
        __gnuc_va_list __arg);
extern int __isoc99_vswscanf (__const wchar_t *__restrict __s,
         __const wchar_t *__restrict __format,
         __gnuc_va_list __arg) __attribute__ ((__nothrow__));


extern unsigned int __mbsrtowcs_l (wchar_t *dst, const char **src, unsigned int len,
        mbstate_t *ps, __locale_t l) ;
extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__));
extern int getopt_long (int ___argc, char *const *___argv,
   const char *__shortopts,
          const struct option *__longopts, int *__longind)
       __attribute__ ((__nothrow__));
extern int getopt_long_only (int ___argc, char *const *___argv,
        const char *__shortopts,
               const struct option *__longopts, int *__longind)
       __attribute__ ((__nothrow__));
extern int _getopt_internal (int ___argc, char *const *___argv,
        const char *__shortopts,
               const struct option *__longopts, int *__longind,
        int __long_only);
extern int _getopt_internal_r (int ___argc, char *const *___argv,
          const char *__shortopts,
          const struct option *__longopts, int *__longind,
          int __long_only, struct _getopt_data *__data);
extern int _getopt_long_r (int ___argc, char *const *___argv,
      const char *__shortopts,
      const struct option *__longopts, int *__longind,
      struct _getopt_data *__data);
extern int _getopt_long_only_r (int ___argc, char *const *___argv,
    const char *__shortopts,
    const struct option *__longopts,
    int *__longind,
    struct _getopt_data *__data);
extern int __libc_argc;
extern char **__libc_argv;
static void
exchange (char **argv, struct _getopt_data *d)
{
  int bottom = d->__first_nonopt;
  int middle = d->__last_nonopt;
  int top = d->optind;
  char *tem;
  while (top > middle && middle > bottom)
    {
      if (top - middle > middle - bottom)
 {
   int len = middle - bottom;
   register int i;
   for (i = 0; i < len; i++)
     {
       tem = argv[bottom + i];
       argv[bottom + i] = argv[top - (middle - bottom) + i];
       argv[top - (middle - bottom) + i] = tem;
       ;
     }
   top -= len;
 }
      else
 {
   int len = top - middle;
   register int i;
   for (i = 0; i < len; i++)
     {
       tem = argv[bottom + i];
       argv[bottom + i] = argv[middle + i];
       argv[middle + i] = tem;
       ;
     }
   bottom += len;
 }
    }
  d->__first_nonopt += (d->optind - d->__last_nonopt);
  d->__last_nonopt = d->optind;
}
*/

static const char *_getopt_initialize(int argc, char *const *argv, const char *optstring, struct _getopt_data *d) {
   
   d->__first_nonopt = d->optind;
   d->__last_nonopt = d->optind;
   d->__nextchar = 0x00;
   d->__posixly_correct = 0;
   
   if (optstring[0] == '-') {
      d->__ordering = RETURN_IN_ORDER;
      ++optstring;
   }
   else if (optstring[0] == '+') {
      d->__ordering = REQUIRE_ORDER;
      ++optstring;
   }
   else d->__ordering = PERMUTE;
   return optstring;
}

int _getopt_internal_r(int argc, char **argv, const char *optstring, const struct option *longopts, int *longind, int long_only, struct _getopt_data *d) {
   int print_errors = d->opterr;
   
   //printf("optstring = \"%s\"\n", optstring);
   if (optstring[0] == ':') print_errors = 0;
   
   if (argc < 1) return -1;
   
   d->optarg = 0x00;
   if (d->optind == 0 || !d->__initialized) {
      if (d->optind == 0) d->optind = 1;
      optstring = _getopt_initialize(argc, argv, optstring, d);
      d->__initialized = 1;
   }
   if (d->__nextchar == 0x00 || *d->__nextchar == 0x00) {
      if (d->__last_nonopt > d->optind) d->__last_nonopt = d->optind;
      if (d->__first_nonopt > d->optind) d->__first_nonopt = d->optind;
      if (d->__ordering == PERMUTE) {
         if (d->__first_nonopt != d->__last_nonopt && d->__last_nonopt != d->optind) exchange ((char **) argv, d);
         else if (d->__last_nonopt != d->optind) d->__first_nonopt = d->optind;
         while (d->optind < argc && (argv[d->optind][0] != '-' || argv[d->optind][1] == '\0')) d->optind++;
         d->__last_nonopt = d->optind;
      }
      if (d->optind != argc && 
          !__extension__ ({ 
             unsigned int __s1_len, __s2_len;
             (__builtin_constant_p (argv[d->optind]) && 
                 __builtin_constant_p ("--") && 
                 (__s1_len = strlen (argv[d->optind]), __s2_len = strlen ("--"), 
                    (!((unsigned int)(const void *)((argv[d->optind]) + 1) - (unsigned int)(const void *)(argv[d->optind]) == 1) || __s1_len >= 4) && 
                    (!((unsigned int)(const void *)(("--") + 1) - (unsigned int)(const void *)("--") == 1) || __s2_len >= 4)
                 ) ? __builtin_strcmp (argv[d->optind], "--") : (
                    __builtin_constant_p (argv[d->optind]) && 
                    ((unsigned int)(const void *)((argv[d->optind]) + 1) - (unsigned int)(const void *)(argv[d->optind]) == 1) && 
                    (__s1_len = strlen (argv[d->optind]), __s1_len < 4) ? (
                       __builtin_constant_p ("--") && 
                       ((unsigned int)(const void *)(("--") + 1) - (unsigned int)(const void *)("--") == 1) ? __builtin_strcmp (argv[d->optind], "--") : 
                          (__extension__ ({ 
                             __const unsigned char *__s2 = (__const unsigned char *) (__const char *) ("--");
                             register int __result = (((__const unsigned char *) (__const char *) (argv[d->optind]))[0] - __s2[0]);
                             if (__s1_len > 0 && __result == 0) {
                                __result = (((__const unsigned char *) (__const char *) (argv[d->optind]))[1] - __s2[1]);
                                if (__s1_len > 1 && __result == 0) {
                                   __result = (((__const unsigned char *) (__const char *) (argv[d->optind]))[2] - __s2[2]);
                                   if (__s1_len > 2 && __result == 0) __result = (
                                      ((__const unsigned char *) (__const char *) (argv[d->optind]))[3] - __s2[3]);
                                }
                             }
                             __result;
                          }))
                    ) : (
                       __builtin_constant_p ("--") && 
                       ((unsigned int)(const void *)(("--") + 1) - (unsigned int)(const void *)("--") == 1) && 
                       (__s2_len = strlen ("--"), __s2_len < 4) ? (__builtin_constant_p (argv[d->optind]) && 
                       ((unsigned int)(const void *)((argv[d->optind]) + 1) - (unsigned int)(const void *)(argv[d->optind]) == 1) ? 
                          __builtin_strcmp (argv[d->optind], "--") : 
                          (__extension__ ({ 
                             __const unsigned char *__s1 = (__const unsigned char *) (__const char *) (argv[d->optind]);
                             register int __result = __s1[0] - ((__const unsigned char *) (__const char *) ("--"))[0];
                             if (__s2_len > 0 && __result == 0) { 
                                __result = (__s1[1] - ((__const unsigned char *) (__const char *) ("--"))[1]);
                                if (__s2_len > 1 && __result == 0) {
                                   __result = (__s1[2] - ((__const unsigned char *) (__const char *) ("--"))[2]);
                                   if (__s2_len > 2 && __result == 0) __result = (__s1[3] - ((__const unsigned char *) (__const char *) ("--"))[3]);
                                }
                             } __result;
                          }))
                       ) : __builtin_strcmp (argv[d->optind], "--")))); })) {
         d->optind++;
         if (d->__first_nonopt != d->__last_nonopt && d->__last_nonopt != d->optind) exchange ((char **) argv, d);
         else if (d->__first_nonopt == d->__last_nonopt)
         d->__first_nonopt = d->optind;
         d->__last_nonopt = argc;
         d->optind = argc;
      }
   } // meu
   imprima_dados(); // meu
   return -1; // meu
} // meu
/*  // meu
      if (d->optind == argc)
 {
   if (d->__first_nonopt != d->__last_nonopt)
     d->optind = d->__first_nonopt;
   return -1;
 }
      if ((argv[d->optind][0] != '-' || argv[d->optind][1] == '\0'))
 {
   if (d->__ordering == REQUIRE_ORDER)
     return -1;
   d->optarg = argv[d->optind++];
   return 1;
 }
      d->__nextchar = (argv[d->optind] + 1
    + (longopts != ((void *)0) && argv[d->optind][1] == '-'));
    }
  if (longopts != ((void *)0)
      && (argv[d->optind][1] == '-'
   || (long_only && (argv[d->optind][2]
       || !(__extension__ (__builtin_constant_p (argv[d->optind][1]) && !__builtin_constant_p (optstring) && (argv[d->optind][1]) == '\0' ? (char *) __rawmemchr (optstring, argv[d->optind][1]) : __builtin_strchr (optstring, argv[d->optind][1])))))))
    {
      char *nameend;
      const struct option *p;
      const struct option *pfound = ((void *)0);
      int exact = 0;
      int ambig = 0;
      int indfound = -1;
      int option_index;
      for (nameend = d->__nextchar; *nameend && *nameend != '='; nameend++)
                    ;
      for (p = longopts, option_index = 0; p->name; p++, option_index++)
 if (!(__extension__ (__builtin_constant_p (nameend - d->__nextchar) && ((__builtin_constant_p (p->name) && strlen (p->name) < ((unsigned int) (nameend - d->__nextchar))) || (__builtin_constant_p (d->__nextchar) && strlen (d->__nextchar) < ((unsigned int) (nameend - d->__nextchar)))) ? __extension__ ({ unsigned int __s1_len, __s2_len; (__builtin_constant_p (p->name) && __builtin_constant_p (d->__nextchar) && (__s1_len = strlen (p->name), __s2_len = strlen (d->__nextchar), (!((unsigned int)(const void *)((p->name) + 1) - (unsigned int)(const void *)(p->name) == 1) || __s1_len >= 4) && (!((unsigned int)(const void *)((d->__nextchar) + 1) - (unsigned int)(const void *)(d->__nextchar) == 1) || __s2_len >= 4)) ? __builtin_strcmp (p->name, d->__nextchar) : (__builtin_constant_p (p->name) && ((unsigned int)(const void *)((p->name) + 1) - (unsigned int)(const void *)(p->name) == 1) && (__s1_len = strlen (p->name), __s1_len < 4) ? (__builtin_constant_p (d->__nextchar) && ((unsigned int)(const void *)((d->__nextchar) + 1) - (unsigned int)(const void *)(d->__nextchar) == 1) ? __builtin_strcmp (p->name, d->__nextchar) : (__extension__ ({ __const unsigned char *__s2 = (__const unsigned char *) (__const char *) (d->__nextchar); register int __result = (((__const unsigned char *) (__const char *) (p->name))[0] - __s2[0]); if (__s1_len > 0 && __result == 0) { __result = (((__const unsigned char *) (__const char *) (p->name))[1] - __s2[1]); if (__s1_len > 1 && __result == 0) { __result = (((__const unsigned char *) (__const char *) (p->name))[2] - __s2[2]); if (__s1_len > 2 && __result == 0) __result = (((__const unsigned char *) (__const char *) (p->name))[3] - __s2[3]); } } __result; }))) : (__builtin_constant_p (d->__nextchar) && ((unsigned int)(const void *)((d->__nextchar) + 1) - (unsigned int)(const void *)(d->__nextchar) == 1) && (__s2_len = strlen (d->__nextchar), __s2_len < 4) ? (__builtin_constant_p (p->name) && ((unsigned int)(const void *)((p->name) + 1) - (unsigned int)(const void *)(p->name) == 1) ? __builtin_strcmp (p->name, d->__nextchar) : (__extension__ ({ __const unsigned char *__s1 = (__const unsigned char *) (__const char *) (p->name); register int __result = __s1[0] - ((__const unsigned char *) (__const char *) (d->__nextchar))[0]; if (__s2_len > 0 && __result == 0) { __result = (__s1[1] - ((__const unsigned char *) (__const char *) (d->__nextchar))[1]); if (__s2_len > 1 && __result == 0) { __result = (__s1[2] - ((__const unsigned char *) (__const char *) (d->__nextchar))[2]); if (__s2_len > 2 && __result == 0) __result = (__s1[3] - ((__const unsigned char *) (__const char *) (d->__nextchar))[3]); } } __result; }))) : __builtin_strcmp (p->name, d->__nextchar)))); }) : strncmp (p->name, d->__nextchar, nameend - d->__nextchar))))
   {
     if ((unsigned int) (nameend - d->__nextchar)
  == (unsigned int) strlen (p->name))
       {
  pfound = p;
  indfound = option_index;
  exact = 1;
  break;
       }
     else if (pfound == ((void *)0))
       {
  pfound = p;
  indfound = option_index;
       }
     else if (long_only
       || pfound->has_arg != p->has_arg
       || pfound->flag != p->flag
       || pfound->val != p->val)
       ambig = 1;
   }
      if (ambig && !exact)
 {
   if (print_errors)
     {
       char *buf;
       if (__asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: option '%s' is ambiguous\n", __LC_MESSAGES), argv[0], argv[d->optind]) >= 0)
  {
    ;
    int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
    ((_IO_FILE *) stderr)->_flags2 |= 2;
    __fxprintf(((void *)0), "%s", buf);
    ((_IO_FILE *) stderr)->_flags2 = old_flags2;
    ;
    free (buf);
  }
     }
   d->__nextchar += strlen (d->__nextchar);
   d->optind++;
   d->optopt = 0;
   return '?';
 }
      if (pfound != ((void *)0))
 {
   option_index = indfound;
   d->optind++;
   if (*nameend)
     {
       if (pfound->has_arg)
  d->optarg = nameend + 1;
       else
  {
    if (print_errors)
      {
        char *buf;
        int n;
        if (argv[d->optind - 1][1] == '-')
   {
     n = __asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: option '--%s' doesn't allow an argument\n", __LC_MESSAGES), argv[0], pfound->name);
   }
        else
   {
     n = __asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: option '%c%s' doesn't allow an argument\n", __LC_MESSAGES), argv[0], argv[d->optind - 1][0], pfound->name);
   }
        if (n >= 0)
   {
     ;
     int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
     ((_IO_FILE *) stderr)->_flags2
       |= 2;
     __fxprintf(((void *)0), "%s", buf);
     ((_IO_FILE *) stderr)->_flags2 = old_flags2;
     ;
     free (buf);
   }
      }
    d->__nextchar += strlen (d->__nextchar);
    d->optopt = pfound->val;
    return '?';
  }
     }
   else if (pfound->has_arg == 1)
     {
       if (d->optind < argc)
  d->optarg = argv[d->optind++];
       else
  {
    if (print_errors)
      {
        char *buf;
        if (__asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: option '%s' requires an argument\n", __LC_MESSAGES), argv[0], argv[d->optind - 1]) >= 0)
   {
     ;
     int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
     ((_IO_FILE *) stderr)->_flags2
       |= 2;
     __fxprintf(((void *)0), "%s", buf);
     ((_IO_FILE *) stderr)->_flags2 = old_flags2;
     ;
     free (buf);
   }
      }
    d->__nextchar += strlen (d->__nextchar);
    d->optopt = pfound->val;
    return optstring[0] == ':' ? ':' : '?';
  }
     }
   d->__nextchar += strlen (d->__nextchar);
   if (longind != ((void *)0))
     *longind = option_index;
   if (pfound->flag)
     {
       *(pfound->flag) = pfound->val;
       return 0;
     }
   return pfound->val;
 }
      if (!long_only || argv[d->optind][1] == '-'
   || (__extension__ (__builtin_constant_p (*d->__nextchar) && !__builtin_constant_p (optstring) && (*d->__nextchar) == '\0' ? (char *) __rawmemchr (optstring, *d->__nextchar) : __builtin_strchr (optstring, *d->__nextchar))) == ((void *)0))
 {
   if (print_errors)
     {
       char *buf;
       int n;
       if (argv[d->optind][1] == '-')
  {
    n = __asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: unrecognized option '--%s'\n", __LC_MESSAGES), argv[0], d->__nextchar);
  }
       else
  {
    n = __asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: unrecognized option '%c%s'\n", __LC_MESSAGES), argv[0], argv[d->optind][0], d->__nextchar);
  }
       if (n >= 0)
  {
    ;
    int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
    ((_IO_FILE *) stderr)->_flags2 |= 2;
    __fxprintf(((void *)0), "%s", buf);
    ((_IO_FILE *) stderr)->_flags2 = old_flags2;
    ;
    free (buf);
  }
     }
   d->__nextchar = (char *) "";
   d->optind++;
   d->optopt = 0;
   return '?';
 }
    }
  {
    char c = *d->__nextchar++;
    char *temp = (__extension__ (__builtin_constant_p (c) && !__builtin_constant_p (optstring) && (c) == '\0' ? (char *) __rawmemchr (optstring, c) : __builtin_strchr (optstring, c)));
    if (*d->__nextchar == '\0')
      ++d->optind;
    if (temp == ((void *)0) || c == ':')
      {
 if (print_errors)
   {
     char *buf;
     int n;
     n = __asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: invalid option -- '%c'\n", __LC_MESSAGES), argv[0], c);
     if (n >= 0)
       {
  ;
  int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
  ((_IO_FILE *) stderr)->_flags2 |= 2;
  __fxprintf(((void *)0), "%s", buf);
  ((_IO_FILE *) stderr)->_flags2 = old_flags2;
  ;
  free (buf);
       }
   }
 d->optopt = c;
 return '?';
      }
    if (temp[0] == 'W' && temp[1] == ';')
      {
 char *nameend;
 const struct option *p;
 const struct option *pfound = ((void *)0);
 int exact = 0;
 int ambig = 0;
 int indfound = 0;
 int option_index;
 if (*d->__nextchar != '\0')
   {
     d->optarg = d->__nextchar;
     d->optind++;
   }
 else if (d->optind == argc)
   {
     if (print_errors)
       {
  char *buf;
  if (__asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: option requires an argument -- '%c'\n", __LC_MESSAGES), argv[0], c) >= 0)
    {
      ;
      int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
      ((_IO_FILE *) stderr)->_flags2 |= 2;
      __fxprintf(((void *)0), "%s", buf);
      ((_IO_FILE *) stderr)->_flags2 = old_flags2;
      ;
      free (buf);
    }
       }
     d->optopt = c;
     if (optstring[0] == ':')
       c = ':';
     else
       c = '?';
     return c;
   }
 else
   d->optarg = argv[d->optind++];
 for (d->__nextchar = nameend = d->optarg; *nameend && *nameend != '=';
      nameend++)
                      ;
 for (p = longopts, option_index = 0; p->name; p++, option_index++)
   if (!(__extension__ (__builtin_constant_p (nameend - d->__nextchar) && ((__builtin_constant_p (p->name) && strlen (p->name) < ((unsigned int) (nameend - d->__nextchar))) || (__builtin_constant_p (d->__nextchar) && strlen (d->__nextchar) < ((unsigned int) (nameend - d->__nextchar)))) ? __extension__ ({ unsigned int __s1_len, __s2_len; (__builtin_constant_p (p->name) && __builtin_constant_p (d->__nextchar) && (__s1_len = strlen (p->name), __s2_len = strlen (d->__nextchar), (!((unsigned int)(const void *)((p->name) + 1) - (unsigned int)(const void *)(p->name) == 1) || __s1_len >= 4) && (!((unsigned int)(const void *)((d->__nextchar) + 1) - (unsigned int)(const void *)(d->__nextchar) == 1) || __s2_len >= 4)) ? __builtin_strcmp (p->name, d->__nextchar) : (__builtin_constant_p (p->name) && ((unsigned int)(const void *)((p->name) + 1) - (unsigned int)(const void *)(p->name) == 1) && (__s1_len = strlen (p->name), __s1_len < 4) ? (__builtin_constant_p (d->__nextchar) && ((unsigned int)(const void *)((d->__nextchar) + 1) - (unsigned int)(const void *)(d->__nextchar) == 1) ? __builtin_strcmp (p->name, d->__nextchar) : (__extension__ ({ __const unsigned char *__s2 = (__const unsigned char *) (__const char *) (d->__nextchar); register int __result = (((__const unsigned char *) (__const char *) (p->name))[0] - __s2[0]); if (__s1_len > 0 && __result == 0) { __result = (((__const unsigned char *) (__const char *) (p->name))[1] - __s2[1]); if (__s1_len > 1 && __result == 0) { __result = (((__const unsigned char *) (__const char *) (p->name))[2] - __s2[2]); if (__s1_len > 2 && __result == 0) __result = (((__const unsigned char *) (__const char *) (p->name))[3] - __s2[3]); } } __result; }))) : (__builtin_constant_p (d->__nextchar) && ((unsigned int)(const void *)((d->__nextchar) + 1) - (unsigned int)(const void *)(d->__nextchar) == 1) && (__s2_len = strlen (d->__nextchar), __s2_len < 4) ? (__builtin_constant_p (p->name) && ((unsigned int)(const void *)((p->name) + 1) - (unsigned int)(const void *)(p->name) == 1) ? __builtin_strcmp (p->name, d->__nextchar) : (__extension__ ({ __const unsigned char *__s1 = (__const unsigned char *) (__const char *) (p->name); register int __result = __s1[0] - ((__const unsigned char *) (__const char *) (d->__nextchar))[0]; if (__s2_len > 0 && __result == 0) { __result = (__s1[1] - ((__const unsigned char *) (__const char *) (d->__nextchar))[1]); if (__s2_len > 1 && __result == 0) { __result = (__s1[2] - ((__const unsigned char *) (__const char *) (d->__nextchar))[2]); if (__s2_len > 2 && __result == 0) __result = (__s1[3] - ((__const unsigned char *) (__const char *) (d->__nextchar))[3]); } } __result; }))) : __builtin_strcmp (p->name, d->__nextchar)))); }) : strncmp (p->name, d->__nextchar, nameend - d->__nextchar))))
     {
       if ((unsigned int) (nameend - d->__nextchar) == strlen (p->name))
  {
    pfound = p;
    indfound = option_index;
    exact = 1;
    break;
  }
       else if (pfound == ((void *)0))
  {
    pfound = p;
    indfound = option_index;
  }
       else
  ambig = 1;
     }
 if (ambig && !exact)
   {
     if (print_errors)
       {
  char *buf;
  if (__asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: option '-W %s' is ambiguous\n", __LC_MESSAGES), argv[0], argv[d->optind]) >= 0)
    {
      ;
      int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
      ((_IO_FILE *) stderr)->_flags2 |= 2;
      __fxprintf(((void *)0), "%s", buf);
      ((_IO_FILE *) stderr)->_flags2 = old_flags2;
      ;
      free (buf);
    }
       }
     d->__nextchar += strlen (d->__nextchar);
     d->optind++;
     return '?';
   }
 if (pfound != ((void *)0))
   {
     option_index = indfound;
     if (*nameend)
       {
  if (pfound->has_arg)
    d->optarg = nameend + 1;
  else
    {
      if (print_errors)
        {
   char *buf;
   if (__asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: option '-W %s' doesn't allow an argument\n", __LC_MESSAGES), argv[0], pfound->name) >= 0)
     {
       ;
       int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
       ((_IO_FILE *) stderr)->_flags2
         |= 2;
       __fxprintf(((void *)0), "%s", buf);
       ((_IO_FILE *) stderr)->_flags2 = old_flags2;
       ;
       free (buf);
     }
        }
      d->__nextchar += strlen (d->__nextchar);
      return '?';
    }
       }
     else if (pfound->has_arg == 1)
       {
  if (d->optind < argc)
    d->optarg = argv[d->optind++];
  else
    {
      if (print_errors)
        {
   char *buf;
   if (__asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: option '%s' requires an argument\n", __LC_MESSAGES), argv[0], argv[d->optind - 1]) >= 0)
     {
       ;
       int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
       ((_IO_FILE *) stderr)->_flags2
         |= 2;
       __fxprintf(((void *)0), "%s", buf);
       ((_IO_FILE *) stderr)->_flags2 = old_flags2;
       ;
       free (buf);
     }
        }
      d->__nextchar += strlen (d->__nextchar);
      return optstring[0] == ':' ? ':' : '?';
    }
       }
     d->__nextchar += strlen (d->__nextchar);
     if (longind != ((void *)0))
       *longind = option_index;
     if (pfound->flag)
       {
  *(pfound->flag) = pfound->val;
  return 0;
       }
     return pfound->val;
   }
   d->__nextchar = ((void *)0);
   return 'W';
      }
    if (temp[1] == ':')
      {
 if (temp[2] == ':')
   {
     if (*d->__nextchar != '\0')
       {
  d->optarg = d->__nextchar;
  d->optind++;
       }
     else
       d->optarg = ((void *)0);
     d->__nextchar = ((void *)0);
   }
 else
   {
     if (*d->__nextchar != '\0')
       {
  d->optarg = d->__nextchar;
  d->optind++;
       }
     else if (d->optind == argc)
       {
  if (print_errors)
    {
      char *buf;
      if (__asprintf(&buf, __dcgettext (_libc_intl_domainname, "%s: option requires an argument -- '%c'\n", __LC_MESSAGES), argv[0], c) >= 0)
        {
   ;
   int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
   ((_IO_FILE *) stderr)->_flags2 |= 2;
   __fxprintf(((void *)0), "%s", buf);
   ((_IO_FILE *) stderr)->_flags2 = old_flags2;
   ;
   free (buf);
        }
    }
  d->optopt = c;
  if (optstring[0] == ':')
    c = ':';
  else
    c = '?';
       }
     else
       d->optarg = argv[d->optind++];
     d->__nextchar = ((void *)0);
   }
      }
    return c;
  }
}
*/

int _getopt_internal(int argc, char **argv, const char *optstring, const struct option *longopts, int *longind, int long_only) {
   int result;
   getopt_data.optind = optind;
   getopt_data.opterr = opterr;
   result = _getopt_internal_r(argc, argv, optstring, longopts, longind, long_only, &getopt_data);
   optind = getopt_data.optind;
   optarg = getopt_data.optarg;
   optopt = getopt_data.optopt;
   return result;
}

int getopt(int argc, char **argv, const char *optstring) {
   return _getopt_internal(argc, argv, optstring,(const struct option *)0, (int *)0, 0);
}

int main(int argc, char **argv) {
   int c;
   int digit_optind = 0;
   
   while (1) {
      //printf("optind = %d\n", optind);
      int this_option_optind = optind ? optind : 1;
      
      c = getopt(argc, argv, "abc:d:0123456789");
      if (c == -1) break;
      
      switch (c) {
         case '0':
         case '1':
         case '2':
         case '3':
         case '4':
         case '5':
         case '6':
         case '7':
         case '8':
         case '9':
            if (digit_optind != 0 && digit_optind != this_option_optind) printf("digits occur in two different argv-elements.\n");
            digit_optind = this_option_optind;
            printf("option %c\n", c);
            break;
         case 'a':
            printf("option a\n");
            break;
         case 'b':
            printf("option b\n");
            break;
         case 'c':
            printf("option c with value '%s'\n", optarg);
            break;
         case '?':
            break;
         default:
            printf("?? getopt returned character code 0%o ??\n", c);
      }
   }
   if (optind < argc) {
      printf("non-option ARGV-elements: ");
      while (optind < argc) printf("%s ", argv[optind++]);
      printf("\n");
   }
   return 0;
}

