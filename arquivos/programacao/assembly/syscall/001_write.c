// gcc -Wall -static -o 001_write.elf 001_write.c
// gcc -S -masm=intel 001_write.c -o 001_write.s

// Write N bytes of BUF to FD. 
// Return the number written, or -1.

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int write(int __fd, const void *__buf, unsigned long int __n);

int main() {
  char string[] = "TESTE T\n";
  write(1, string, 8);
  return 0;
}
