#include <iostream>

using namespace std;

class MyFirstClass { // MyFirstClass - ��� ������
 private:
  int privateVar;
 public:
  int i; // ���� i ������ ����
  MyFirstClass() { // �����������
    i = 2; // ����������� ��������
    //commonVar = 4;
    count++;
    cout << "Object #" << count << endl;
  }
  static int commonVar;
  static int count;
};

int MyFirstClass::commonVar = 3;
int MyFirstClass::count = 0;

int main() {
  // �������� 2 ���������� (�������) ������
  MyFirstClass a;
  MyFirstClass b;
  //a.privateVar = 2;
  // ���������� i � ������� ������� ����
  b.i = 3;
  // commonVar - ����� ��� ���� �������� ����� ������
  a.commonVar = 10;
  cout << "a.commonVar = " << a.commonVar << endl;
  b.commonVar = 13;
  cout << "a.i = " << a.i << endl;
  cout << "b.i = " << b.i << endl;
  cout << "a.commonVar = " << a.commonVar << endl;
  cout << "b.commonVar = " << b.commonVar << endl;

  return 0;
}
