// DonТt Repeat Yourself
// http://ru.wikipedia.org/wiki/Don%E2%80%99t_repeat_yourself
#include <iostream>
#include <math.h>

using namespace std;

// »нкапсул€ци€
class Square {
//private:
//  double side;
  double area;
public:
  double getSide(){
    return sqrt(area);
  }
  void setSide(double value){
    area = value*value;
  }
  // ѕолучить площадь
  double getArea(){
    return area;
  }
  void setArea(double value){
    area = value;
  }
};

int main()
{
  Square s;
  s.setSide(12);
  cout << "side = " << s.getSide() << endl;
  cout << "area = " << s.getArea() << endl;

  s.setArea(100);
  cout << "side = " << s.getSide() << endl;
  cout << "area = " << s.getArea() << endl;

  return 0;
}
