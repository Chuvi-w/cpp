#include <iostream>

using namespace std;

struct Shape {
  //virtual void show(){
  //  cout << "Shape" << endl;
  //};
  virtual void show() = 0; // ����������� �����
protected:
  virtual void doA() = 0;
  virtual void doB() = 0;
  virtual void doC() = 0;
  virtual void doD() = 0;
  virtual void doE() = 0;
  //int x;
private:
  char c;
} __attribute__((packed));

struct Square : public Shape {
  double side;
  Square(double s) : side(s) { }
  void show(){
    cout << "Square side = " << side << endl;
  }
};

struct Rectangle : public Shape {
  double height, width;
  Rectangle(double h, double w) :
    height(h), width(w) { }
  void show(){
    cout << "Rectangle " << height <<
      " x " << width << endl;
  }
};

int main()
{
  //cout << sizeof(Shape) << endl;
  Shape* s[] = {
     new Square(10),
     new Rectangle(2,3),
     new Square(15),
//     new Shape(),
  };

  for(int i = 0; i < 3; ++i)
    s[i]->show();

  return 0;
}
