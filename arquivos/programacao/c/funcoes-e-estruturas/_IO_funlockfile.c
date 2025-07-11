

//#include<libio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
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

typedef struct _IO_FILE _IO_FILE;

extern void _IO_funlockfile(_IO_FILE *);


