
int main() {
  return 1;
}


equivale à:
.section .text
.globl main
main:
mov	eax, 1
ret
