#include <iostream>

class Square {
  double side; // Сторона
  double area; // Площадь
 public:
  // Просто возвращаем значение
  double getSide() {
    return side;
  }
  double getArea() {
    return area;
  }
  // При изменении меняем одновременно
  void setSide(double value) {
    side = value;
    area = value * value;
  }
  void setArea(double value) {
    side = sqrt(value);
    area = value;
  }

};

using namespace std;

int main() {
  cout << "Hello world!" << endl;
  return 0;
}
