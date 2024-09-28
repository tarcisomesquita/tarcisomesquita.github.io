const guarantee that its reference parameters are not going to be modified
A passagem por referência evita fazer uma nova cópia na memória. Imagine se a string for enorme.

string concatenate(const string &a, const string &b) {
  return a+b;
}

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <iostream>
using namespace std;

void duplicate(int &a, int &b, int &c) {
  a*=2;
  b*=2;
  c*=2;
}

int main () {
  int x=1, y=3, z=8;
  duplicate (x, y, z);
  cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
  return 0;
}

/*
void duplicate(int *a, int *b, int *c) {
  *a*=2;
  *b*=2;
  *c*=2;
}

int main () {
  int x=1, y=3, z=8;
  duplicate (&x, &y, &z);
  cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
  return 0;
}
*/
