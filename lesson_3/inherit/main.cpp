// ������������
#include <iostream>

using namespace std;

// struct A <--> class A { public:
struct A {
  int a; // ���� �������� ��������
  void doA(){
    cout << "doA()" << endl;
    onlyInA = 2;
    cout << "onlyInA = " << onlyInA << endl;
    forChilds = 10;
  };
private:
  int onlyInA; // ������ ������ ������ A
protected:
  int forChilds; // ������ ������ A � � �����������
};

struct B : public A {
  int b;
  int forChilds; // ���� � ��� �� ������
  void doB(){
    cout << "doB()" << endl;
    // ���������� � �����������
    //onlyInA = 2;
    //cout << "onlyInA = " << onlyInA << endl;
    A::forChilds = 12;
    forChilds = 20; // ��������
    this->forChilds = 20; // ��������

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

  void doA(){
      A::doA();
  }
};

struct D : public C {
  int d;
  void doD(){
    doA();
    doB();
  }
};

// ������������� ������������
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
    L::doL();
  }
};

class G {
public:
    void show(){
        cout << "Class G" << endl;
    }
    void a(int x, double y){
    }
    void show(double x){
        cout << "Class G " << x << endl;
    }
};

class H {
public:
    void show(){
        cout << "Class H" << endl;
    }
    void show(int x){
        cout << "Class H " << x << endl;
    }
};

class W : public G, protected H {
public:
    void w(){
       //show(); // ������ ����������
       // �� ������ ���� ������� �� ������ ������ �������� �����
       G::show();
       H::show();
    }
    void a(double y, int x){
       a(x, y);
    }
    void show1(){
        G::show(2);
        H::show(2.2);
    }
};

int main()
{
  A a;
  a.a = 1;
  a.doA();

  B b;
  // ��� �������, �.�. onlyInA private
  // b.onlyInA = 10;
  b.a = 1;
  b.b = 2;
  b.doA();
  b.doB();

  C c;
  // c.a = 1; // ������ ��-�� protected ������������
  // c.b = 2; // ������ ��-�� protected ������������
  c.c = 3;
// c.doA();
// c.doB();
  c.doC();

  X x;
  //x.doL();

  return 0;
}
