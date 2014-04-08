#include <iostream>

using namespace std;

class Point {
public:
  double x,y;
};

class Vector {
public:
  Point* p;
  const char* name;
  // �����������
  Vector(const char* name, double X, double Y) {
    p = new Point();
    p->x = X; p->y = Y;

    this->name = name;
  }
  ~Vector(){
    cout << "Destructor " << name << endl;
    delete p;
    p = NULL;
  }
  Vector(Vector& v){
    p = new Point();
    p->x = v.p->x;
    p->y = v.p->y;
  }
  void show(){
    cout << "(" << p->x << "; " << p->y << ")" << endl;
  }
};

int main()
{
  Vector a("a", 1,2), b("b", 2,4);
  {
     Vector c = a;
     c.name = "c";
     a.show();
     c.show();
     cout << "I'm here #1" << endl;
  }
  a.show();
  cout << "I'm here #2" << endl;

  return 0;
}