
// TYPEOF atribui o tipo de uma variável a uma nova variável

extern int printf(char *, ...);

int main() {
  auto unsigned long int var1;
  var1 = 5;
  
  typeof(var1) t;
  t = 1000;
  printf("\n%lu\n\n",t);
  
  return 0;
}
