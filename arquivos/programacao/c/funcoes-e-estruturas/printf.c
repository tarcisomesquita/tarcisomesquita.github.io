

//#include<stdarg.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = 
typedef __builtin_va_list va_list;
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)


//#include"/usr/lib/gcc/i486-linux-gnu/4.3/include/stddef.h" // = = = = = = = 
typedef long unsigned int size_t;


//#include<libio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;

struct _IO_marker
{
   struct _IO_marker *_next;
   struct _IO_FILE *_sbuf;
   int _pos;
};

struct _IO_FILE
{
   int _flags;		// High-order word is _IO_MAGIC; rest is flags.
   
   // The following pointers correspond to the C++ streambuf protocol.
   // Note:  Tk uses the _IO_read_ptr and _IO_read_end fields directly.
   char* _IO_read_ptr;	// Current read pointer 
   char* _IO_read_end;	// End of get area. 
   char* _IO_read_base;	// Start of putback+get area.
   char* _IO_write_base;	// Start of put area.
   char* _IO_write_ptr;	// Current put pointer.
   char* _IO_write_end;	// End of put area. 
   char* _IO_buf_base;	// Start of reserve area.
   char* _IO_buf_end;	// End of reserve area.
   // The following fields are used to support backing up and undo.
   char *_IO_save_base; // Pointer to start of non-current get area.
   char *_IO_backup_base;  // Pointer to first valid character of backup area
   char *_IO_save_end; // Pointer to end of non-current get area.
   
   struct _IO_marker *_markers;
   
   struct _IO_FILE *_chain;
   
   int _fileno;
   
   int _flags2;
   
   long int _old_offset; // This used to be _offset but it's too small.
   
   unsigned short _cur_column;
   signed char _vtable_offset;
   char _shortbuf[1];
   
   void *_lock;
   long long int _offset;
   void *__pad1;
   void *__pad2;
   void *__pad3;
   void *__pad4;
   size_t __pad5;
   int _mode;
   char _unused2[15 * sizeof(int) - 4 * sizeof(void *) - sizeof(size_t)];
};


//#include<stdio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//extern int printf(char *, ...);
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;
extern int vfprintf (FILE *s, const char *format, va_list arg);


int tprintf(const char *format, ...)
{
   va_list arg;
   int done;
   va_start(arg,format);
   done = vfprintf(stdout, format, arg);
   va_end(arg);
   return(done);
}


int main()
{
   tprintf("1 2 3 testando \n");
   return(0);
}

