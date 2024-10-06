
// Jump to the environment saved in ENV, making the `setjmp' call there return VAL, or 1 if VAL is 0.

//#include<setjmp.h>  // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct __jmp_buf_tag;
extern void longjmp (struct __jmp_buf_tag __env[1], int __val);

