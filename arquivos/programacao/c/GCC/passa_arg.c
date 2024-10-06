
// clear ; /usr/lib/gcc/i486-linux-gnu/4.3.3/cc1 -Wall -o passa_arg.s passa_arg.c ; as passa_arg.s -o passa_arg.o ; ld passa_arg.o -o teste ; ./teste argumento1 ; echo $?

int main(int argc, char *argv[])
{
   return(argc);
}

void _start()
{
   asm(
	"popl	%ebp \n"
       "call	main \n"
       "movl	%eax, %ebx \n"
       "movl	$1, %eax \n"
       "int	$0x80 \n"
      );
}

