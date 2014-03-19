#include <iostream>

using namespace std;

struct A {
  virtual void show(){
    cout << "A" << endl;
  };
};

struct B : public A {
  void show(){
    cout << "B" << endl;
  };
};

struct C : protected A {
  void show(){
    cout << "C" << endl;
  };
};

struct D : public B, public C {
  void show(){
    B::show();
  };
};

int main()
{
  D d;
  d.show();

  return 0;
}
