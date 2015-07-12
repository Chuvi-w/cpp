#include <iostream>

using namespace std;

// ������ Singletone - "��������"
class MyClass {
  // private constructor
  MyClass() {
    id = ++count;
  };
  static int count;
  static MyClass* instanse; // private
 public:
  int id; // �������������� �������
  static MyClass* getInstanse() {
    if(instanse == NULL)
      instanse = new MyClass; // ����� ������������

    return instanse;
  }
};

int MyClass::count = 0;
MyClass* MyClass::instanse = NULL;

int main() {
  MyClass* a = MyClass::getInstanse();
  MyClass* b = MyClass::getInstanse();

  cout << "a->id = " << a->id << endl;
  cout << "b->id = " << b->id << endl;
  return 0;
}
