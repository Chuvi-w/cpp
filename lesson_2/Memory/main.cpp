#include <iostream>
#include <stdlib.h>

// Статическая память
int globalVar = 2;

void myFunc() {
  int localVar = 3; // Стек
  static int staticVar = 10; // Статическая память

}

using namespace std;

// int a; - статическая память
// int *a;

void func() {
  char buf[10000];
}

int main() {
  int varInMain = 22; // Стек
  int* intArray; // Стек
  intArray = (int*)malloc(100); // Дин. память

  int* a, b; // a - указатель, b - значение
  // int *a,b;
  // int *a; int b;
  // int *a,*b; - теперь оба указателя
  a = (int*)malloc(sizeof(int));
  // a = (int *)12312;
  *a = 2;
  b = 3;

  return 0;
}
