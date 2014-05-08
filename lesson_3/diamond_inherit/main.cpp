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

struct C : public A {
  void show(){
    cout << "C" << endl;
  };
};

struct D : public B, public C {
  void show(){
    C::show();
  };
};

int main()
{
  D d;
  d.show();

  // Полиморфизм
  A* a[3] = { new B, new A, new C };
  for(int i = 0; i < 3; ++i)
    a[i]->show();

  for(int i = 0; i < 3; ++i)
    delete a[i];

  return 0;
}
