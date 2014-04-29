#include <iostream>

using namespace std;

const int arraySize = 3;

int a[] = { 3, 10, 7 },
 b[arraySize][arraySize] = {
   { 1, 2, 3 },
   { 4, 5, 6 },
   { 7, 8, 9 }
 };

void f(){
  static int calls = 0; // Статические переменные храняться в 
    // статической памяти и сохраняют своё значение между вызовами
  calls++;
  cout << "f -> " << calls << endl;
}

int main()
{
  static int ii = 3; // В Статической области памяти
  int hh = 10; // В Стеке

  f();
  f();f();f();
  f();
  f();

    cout << "a[0] = " << a[0] << endl;
    cout << "b[2][2] = " << b[2][2] << endl;

    int sum = 0;
    for(int i=0; i < arraySize; ++i)
      sum += a[i];

    cout << "sum = " << sum << endl;
    return 0;
}
