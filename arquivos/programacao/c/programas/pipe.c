// gcc -static pipe.c -o pipe; echo -n -e \\x54\\x00\\x0A\\x54 | ./pipe | hexdump -C

#include <stdio.h>

int main() {
  unsigned char buf[1000];
  ssize_t byte = 0;
  
  for (;;) {
    byte = getchar();
    
    if (byte == -1) return 0;
    
    putchar(byte);
  }
}
