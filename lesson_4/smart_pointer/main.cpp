#include <iostream>
#include <locale.h>

using namespace std;

class MyClass {
  int* bigArray;
public:
  int savedA;
  MyClass(int a){
    cout << "a = " << a << endl;
    bigArray = new int[1000000];
    savedA = a;
  }
  ~MyClass(){
    cout << "Деструктор MyClass" << endl;
    delete[] bigArray;
  }
  void show(){
    cout << "MyClass a = " << savedA << endl;
  }
};

template <class T>
class SmartPtr {
  T* ptr;
public:
  SmartPtr(T* p){
    ptr = p;
  }
  ~SmartPtr(){
    delete ptr;
  }
  T* operator ->(){ // Переход по ссылке
    return ptr;
  }
  T& operator*() { // Оператор разыменования
    return *ptr;
  }
};

int main()
{
  setlocale(LC_ALL, "Russian");

//  SmartPtr<int[]> m2 = new int[10];

  SmartPtr<MyClass> m = new MyClass(2);
  //MyClass* m = new MyClass(2);
  m->show();
  cout << m->savedA << endl;
  cout << (*m).savedA << endl;

  return 0;
}
