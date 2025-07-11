
/*
/usr/lib/gcc/i486-linux-gnu/4.3.3/cc1 -masm=intel fprintf2.c -o fprintf2.asm \
&& \
as fprintf2.asm -o fprintf2.o \
&& \
/usr/bin/ld \
-m elf_i386 \
-static \
-o fprintf2.elf \
-z relro \
/usr/lib/crt1.o \
/usr/lib/crti.o \
/usr/lib/gcc/i486-linux-gnu/4.3.3/crtbeginT.o \
-L/usr/lib/gcc/i486-linux-gnu/4.3.3 \
-L/usr/lib/ \
./fprintf2.o \
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
./fprintf2.elf ; echo $?
*/

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *saida, const char *string_com_formatos, ...);

int main(int argc, char *argv[])
{
   fprintf(stdout, "%s %u\n", "Isso é um teste",25);
   return(0);
}

