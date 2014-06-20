#include <iostream>

using namespace std;

// typedef �����������_���� ���_������_����;
typedef unsigned long MyType;

union InMemoryPresentation {
  MyType field;
  unsigned char b[sizeof(MyType)];
};

union HH {
    int a;
    int b;
    char c;
};

int main()
{
  MyType i = 10;
  MyType b, a = 132;
  a = i * b;

  InMemoryPresentation u;
  u.field = 5;// 'A';
  for(int i = 0; i < sizeof(MyType); ++i){
    cout << i << ". ";
    for(int b = 7; b >= 0; --b){
      unsigned char byte = u.b[i];
      // �����:    01101110  00001101
      // ���.����: 76543210         1
      cout << ((byte >> b) & 1);
    }
    cout << endl;
  }

  return 0;
}
