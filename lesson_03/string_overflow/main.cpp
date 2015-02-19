#include <iostream>
#include <stdio.h>
#include <windows.h> // WinAPI
#include <math.h>

using namespace std;

union Bytes {
  int i; // ��� int �������� 4 �����
  char bytes[4]; // �� �� � ���� 4-� ���������
};

struct Shape {
  char type; // type = 'C' - ����, 'S' - �������
  double x, y;
  union {
    double R;
    double Side;
  };
};

struct Point {
  double x, y;

  // ���������� ����� �������
  double dist(Point b) {
    return sqrt(pow(x - b.x, 2) +
                pow(y - b.y, 2));
  }

};


int main() {
  setlocale(LC_ALL, "Russian");
  SetConsoleCP(1251); // ���� � ������� � ��������� 1251
  SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251.

  Point p1 = {2, 3};
  Point p2 = {3, 5};
  Point p3 = {3, 7};
  cout << "����������: " << p1.dist(p2) << endl;

  //
  //    char str[10]; // ������ �� 9 ��������, ��������� ������ 0
  //
  //    cout << "������� ������ ������ 10 ��������: ";
  //    cin >> str;
  //
  //    //freopen("result.txt", "w", stdout);
  //    cout << str << endl;
  int i = 0;
  i++;

  return 0;
}
