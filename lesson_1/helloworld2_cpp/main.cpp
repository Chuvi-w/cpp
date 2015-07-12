// C++
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");

  int a = 2;
  int b = 3;
  int c = a + b;

  printf("Это моя первая программа!\n");

  cout << a << "+" << b << "=" << c << endl;
  return 0;
}
