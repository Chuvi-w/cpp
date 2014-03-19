// Наследование
#include <iostream>

using namespace std;

// struct A <--> class A { public:
struct A {
  int a;
  void doA(){
    cout << "doA()" << endl;
    onlyInA = 2;
    cout << "onlyInA = " << onlyInA << endl;
    forChilds = 10;
  };
private:
  int onlyInA;
protected:
  int forChilds;
};

struct B : public A {
  int b;
  int forChilds;
  void doB(){
    cout << "doB()" << endl;
    //onlyInA = 2;
    //cout << "onlyInA = " << onlyInA << endl;
    A::forChilds = 12;
    this->forChilds = 20;

    cout << "A::forChilds = " << A::forChilds << endl;
    cout << "B::forChilds = " << B::forChilds << endl;
  };
};

struct C : protected B {
  int c;
  void doC(){
    cout << "doC()" << endl;
    forChilds = 20;
    a = 1;
    b = 3;
    doA();
    doB();
  };
};

struct D : public C {
  int d;
  void doD(){
    doA();
    doB();
  }
};

// Множественное наследование
class E : public D {
  void doE(){
  }
};

class L {
public:
  void doL(){
  }
};

class X : public E, private L {
  void doX(){
    doL();
  }
};

int main()
{
  A a;
  a.a = 1;
  a.doA();

  B b;
  b.a = 1;
  b.b = 2;
  b.doA();
  b.doB();

  C c;
//  c.a = 1;
//  c.b = 2;
  c.c = 3;
// c.doA();
// c.doB();
  c.doC();

  X x;
  //x.doL();

  return 0;
}
