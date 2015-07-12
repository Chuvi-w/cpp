#include <iostream>
#include <locale.h>

using namespace std;

class MyClass {
  int* bigArray;
 public:
  int savedId;
  MyClass(int id) {
    cout << "Constructor MyClass id = " << id << endl;
    bigArray = new int[1000000];
    savedId = id;
  }
  ~MyClass() {
    cout << "Destructor MyClass" << endl;
    delete[] bigArray;
  }
  void show() {
    cout << "MyClass id = " << savedId << endl;
  }
};

// Умный указатель
template <class T>
class SmartPtr {
  T* ptr;
 public:
  SmartPtr(T* p) {
    ptr = p;
  }
  // Автоматическая отчистка динамической памяти
  ~SmartPtr() {
    delete ptr;
  }
  T* operator ->() { // Переход по ссылке
    return ptr;
  }
  T& operator*() { // Оператор разыменования
    return *ptr;
  }
};

#define USE_SMART_PTR

#ifdef USE_SMART_PTR
typedef SmartPtr<MyClass> MyClassPtr;
#else
typedef MyClass* MyClassPtr;
#endif // USE_SMART_PTR

int main() {
  setlocale(LC_ALL, "Russian");

  //  SmartPtr<int[]> m2 = new int[10];


  MyClassPtr m = new MyClass(2);
  m->show();
  cout << m->savedId << endl;
  cout << (*m).savedId << endl;

  MyClassPtr m2 = new MyClass(3);

  return 0;
}
