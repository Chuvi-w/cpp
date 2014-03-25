#include <iostream>

using namespace std;

// TODO: SmartPtr для обработки этой ситуации

int main()
{
  int *intArray = new int[100];
  for(int i = 0; i < 10; i++){
    SmartPtr<int[]> intArray = new int[100];

    //delete intArray;
  }
  //delete[] intArray;

  return 0;
}

// Реализовать с использованием STL

//   Самое часто встречающееся число
//   Максимум в массиве
//   Переводчик текста на основе map

