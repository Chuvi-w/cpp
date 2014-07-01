#include <iostream>

using namespace std;

struct X {
  void show(){
    cout << "X" << endl;
  };
};

struct A {
  virtual
  void show(){
    cout << "A" << endl;
  };
};

struct B : public virtual A {
  void show(){
    cout << "B" << endl;
  };
};

struct C : public virtual A {
  void show(){
    cout << "C" << endl;
  };
};

struct D : public B, public C {
  void show(){
    cout << "D" << endl;
    //B::show();
  };
};

int main()
{
  //D d;
  //d.show();

  // Полиморфизм
  //A* x[3] = { new B, new A, new C };
  A* x[4];
  x[0] = new C;
  x[1] = new B;
  x[2] = new A;
  x[3] = new D;

  cout << "sizeof(X) = " << sizeof(X) << endl;
  cout << "sizeof(*X) = " << sizeof(X*) << endl;

  cout << "+ VMT" << endl;
  cout << "sizeof(A) = " << sizeof(A) << endl;
  cout << "sizeof(*A) = " << sizeof(A*) << endl;

  for(int i = 0; i < 4; ++i)
    x[i]->show();

  for(int i = 0; i < 4; ++i)
    delete x[i];

  return 0;
}
