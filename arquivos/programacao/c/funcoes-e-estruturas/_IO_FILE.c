struct _IO_marker {
   struct _IO_marker *_next;
   struct _IO_FILE *_sbuf;
   int _pos;
};

struct _IO_FILE {
   int _flags;
   char *_IO_read_ptr;
   char *_IO_read_end;
   char *_IO_read_base;
   char *_IO_write_base;
   char *_IO_write_ptr;
   char *_IO_write_end;
   char *_IO_buf_base;
   char *_IO_buf_end;
   char *_IO_save_base;
   char *_IO_backup_base;
   char *_IO_save_end;
   struct _IO_marker *_markers;
   struct _IO_FILE *_chain;
   int _fileno;
   int _flags2;
   long int _old_offset;
   unsigned short _cur_column;
   signed char _vtable_offset;
   char _shortbuf[1];
   void *_lock;
   long long int _offset;
   void *__pad1;
   void *__pad2;
   void *__pad3;
   void *__pad4;
   unsigned int __pad5;
   int _mode;
   char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (unsigned int)];
};

extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int printf(char *, ...);


int main(int argc, char **argv) {
   printf("(stdout)->_flags  . . . . . 0x%X\n", (stdout)->_flags);
   printf("(stdout)->_IO_read_ptr  . . 0x%X\n", (stdout)->_IO_read_ptr);
   printf("(stdout)->_IO_read_end  . . 0x%X\n", (stdout)->_IO_read_end);
   printf("(stdout)->_IO_read_base . . 0x%X\n", (stdout)->_IO_read_base);
   printf("(stdout)->_IO_write_base  . 0x%X\n", (stdout)->_IO_write_base);
   printf("*(stdout)->_IO_write_ptr . . 0x%X\n", *(stdout)->_IO_write_ptr);
   printf("(stdout)->_IO_write_end . . 0x%X\n", (stdout)->_IO_write_end);
   printf("(stdout)->_IO_buf_base  . . 0x%X\n", (stdout)->_IO_buf_base);
   printf("(stdout)->_IO_buf_end . . . 0x%X\n", (stdout)->_IO_buf_end);
   printf("(stdout)->_IO_save_base . . 0x%X\n", (stdout)->_IO_save_base);
   printf("(stdout)->_IO_backup_base . 0x%X\n", (stdout)->_IO_backup_base);
   printf("(stdout)->_IO_save_end  . . 0x%X\n", (stdout)->_IO_save_end);
//   struct _IO_marker *_markers;
//   struct _IO_FILE *_chain;
//   int _fileno;
//   int _flags2;
//   long int _old_offset;
//   unsigned short _cur_column;
//   signed char _vtable_offset;
//   char _shortbuf[1];
   printf("(stdout)->_lock = 0x%X\n", (stdout)->_lock);
//   long long int _offset;
   printf("(stdout)->__pad1 = 0x%X\n", (stdout)->__pad1);
   printf("(stdout)->__pad2 = 0x%X\n", (stdout)->__pad2);
   printf("(stdout)->__pad3 = 0x%X\n", (stdout)->__pad3);
   printf("(stdout)->__pad4 = 0x%X\n", (stdout)->__pad4);
//   unsigned int __pad5;
//   int _mode;

   printf("(stdout)->_flags  . . . . . 0x%X\n", (stdout)->_flags);
   printf("(stdout)->_IO_read_ptr  . . 0x%X\n", (stdout)->_IO_read_ptr);
   printf("(stdout)->_IO_read_end  . . 0x%X\n", (stdout)->_IO_read_end);
   printf("(stdout)->_IO_read_base . . 0x%X\n", (stdout)->_IO_read_base);
   printf("(stdout)->_IO_write_base  . 0x%X\n", (stdout)->_IO_write_base);
   printf("*(stdout)->_IO_write_ptr . . 0x%X\n", *(stdout)->_IO_write_ptr);
   printf("(stdout)->_IO_write_end . . 0x%X\n", (stdout)->_IO_write_end);
   printf("(stdout)->_IO_buf_base  . . 0x%X\n", (stdout)->_IO_buf_base);
   printf("(stdout)->_IO_buf_end . . . 0x%X\n", (stdout)->_IO_buf_end);
   printf("(stdout)->_IO_save_base . . 0x%X\n", (stdout)->_IO_save_base);
   printf("(stdout)->_IO_backup_base . 0x%X\n", (stdout)->_IO_backup_base);
   printf("(stdout)->_IO_save_end  . . 0x%X\n", (stdout)->_IO_save_end);
//   struct _IO_marker *_markers;
//   struct _IO_FILE *_chain;
//   int _fileno;
//   int _flags2;
//   long int _old_offset;
//   unsigned short _cur_column;
//   signed char _vtable_offset;
//   char _shortbuf[1];
   printf("(stdout)->_lock = 0x%X\n", (stdout)->_lock);
//   long long int _offset;
   printf("(stdout)->__pad1 = 0x%X\n", (stdout)->__pad1);
   printf("(stdout)->__pad2 = 0x%X\n", (stdout)->__pad2);
   printf("(stdout)->__pad3 = 0x%X\n", (stdout)->__pad3);
   printf("(stdout)->__pad4 = 0x%X\n", (stdout)->__pad4);
//   unsigned int __pad5;
//   int _mode;

   return 0;
}

