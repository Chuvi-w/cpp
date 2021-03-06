#include <iostream>

// Виды памяти
// -----------
// * Статическая
// * Стек: локальные переменные + вызов функций / методов
// * Динамическая: new / delete, [m/c]alloc / free

using namespace std;

// *Статическая* память: глобальные переменные
//-->
int staticArray[1000];
int staticConsts[3] = {3, 4, 5};
//<--

// Переменные с модификатором static.
// Переменная *count* видна только внутри функции ff,
// но при этом сохраняет своё значение между вызовами ff
//-->
int ff() {
  static int count = 0;
}
//<--

// *Стек*: локальные переменные + вызов функций / методов
//-->
int f() {
  int x = 10; // в стеке
  x++;
  f();
}
//<--

int main() {
  int hh = 10;
  {
    int a[100]; // <-- создан в стеке

  } // <-- удалён из стека
  // *Динамическая*: new / delete, [m/c]alloc / free
  // КУЧА / HEAP
  //-->
  int N; // = 100;
  int* p = new int[N];
  p[10] = 1;
  delete[] p;
  //p[10] =
  //<--
  return 0;
}
