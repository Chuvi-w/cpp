#include <iostream>

class Square {
  double side; // �������
  double area; // �������
public:
  // ������ ���������� ��������
  double getSide(){ return side; }
  double getArea(){ return area; }
  // ��� ��������� ������ ������������
  void setSide(double value){
    side = value;
    area = value*value;
  }
  void setArea(double value){
    side = sqrt(value);
    area = value;
  }

};

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
