
/*
/usr/lib/gcc/i486-linux-gnu/4.3.3/cc1 -masm=intel putw.c -o putw.asm \
&& \
as putw.asm -o putw.o \
&& \
/usr/bin/ld \
-m elf_i386 \
-static \
-o putw.elf \
-z relro \
/usr/lib/crt1.o \
/usr/lib/crti.o \
/usr/lib/gcc/i486-linux-gnu/4.3.3/crtbeginT.o \
-L/usr/lib/gcc/i486-linux-gnu/4.3.3 \
-L/usr/lib/ \
./putw.o \
\
--start-group \
-lgcc \
-lgcc_eh \
-lc \
--end-group \
\
/usr/lib/gcc/i486-linux-gnu/4.3.3/crtend.o \
/usr/lib/crtn.o \
&& \
./putw.elf ; echo $?
*/

// Write a doubleword (int) to STREAM.
// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *saida, const char *string_com_formatos, ...);
extern int putw (int __w, FILE *__stream);

int main()
{
   putw(0x0A353637,stdout);
   return(0);
}

