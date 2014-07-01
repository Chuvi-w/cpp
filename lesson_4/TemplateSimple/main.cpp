#include <iostream>

using namespace std;

// Без шаблонов

void sort(int a[], int size){
  for(int i = 0; i < size; ++i)
    for(int j = i + 1; j < size; ++j)
      if(a[j] < a[i]) {
        // Меняем два элемента
        // чтобы на i-ом месте стоял минимальный
        // элемент
        int temp = a[i]; // временная переменная
        a[i] = a[j];
        a[j] = temp;
      }
}

void sortc(char a[], int size){
  for(int i = 0; i < size; ++i)
    for(int j = i + 1; j < size; ++j)
      if(a[j] < a[i]) {
        // Меняем два элемента
        // чтобы на i-ом месте стоял минимальный
        // элемент
        char temp = a[i]; // временная переменная
        a[i] = a[j];
        a[j] = temp;
      }
}

template <typename T>
void s(T a[], int size){
  for(int i = 0; i < size; ++i)
    for(int j = i + 1; j < size; ++j)
      if(a[j] < a[i]) {
        // Меняем два элемента
        // чтобы на i-ом месте стоял минимальный
        // элемент
        T temp = a[i]; // временная переменная
        a[i] = a[j];
        a[j] = temp;
      }
}

int main() {
  int a[] = {20, 10, 13};
  s<int>(a,3);
  for(int i = 0; i < 3; ++i)
    cout << "a[" << i << "] = " << a[i] << endl;

  char c[] = {'g', 'a', 'c'};
  s<char>(c,3);
  for(int i = 0; i < 3; ++i)
    cout << "c[" << i << "] = " << c[i] << endl;

  return 0;
}
