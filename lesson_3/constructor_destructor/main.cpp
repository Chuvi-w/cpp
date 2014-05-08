#include <iostream>

using namespace std;

class MyClass {
    // Количество объектов
    static int count;
    // Идентификатор данного объекта
    int id;
    int *data;
public:
    // Конструктор
    MyClass();
    // Деструктор
    ~MyClass();
};

// Инициализация static-переменной
int MyClass::count = 0;

MyClass::MyClass(){
  count++;
  id = count;
  cout << "Constructor #" << id << endl;
  data = new int[1000];
  data[0] = 10;
}

MyClass::~MyClass(){
  cout << "Destructor #" << id << endl;
  cout << data << " " << data[0] << endl;
  delete[] data;
}

int main() {
  MyClass a; // , b;
 /* {
      MyClass d[2];
  }
  {
      MyClass e[2];
  } */
  MyClass f = a;
  return 0;
}
