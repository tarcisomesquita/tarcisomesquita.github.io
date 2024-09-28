// gcc -Wall -static -o write.elf write.c

// Write N bytes of BUF to FD. 
// Return the number written, or -1.

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int write(int __fd, const void *__buf, unsigned long int __n);

int main()
{
   char string[] = "TESTE T\n";
   write(1, string, 8);
   return 0;
}

