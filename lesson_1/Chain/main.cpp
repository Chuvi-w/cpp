#include <iostream>

using namespace std;

int main() {
  // ���������� 2-� ����������
  // ������ ����
  int a = 3, b = 5;

  a = a * b; /* <=> */ a *= b;
  a = a + b; /* <=> */ a += b;
  a = a - b; /* <=> */ a -= b;
  a = a / b; /* <=> */ a /= b;
  a = a % b; /* <=> */ a %= b;

  // ���������
  a++;
  a = a + 1; // ����������� �����
  ++a; // ���������� �����

  b = (++--++a);

  a--;
  --a;

  a = 20;
  int c = (++a)++;
  cout << "c = " << c << " a = " << a << endl;

  a += b += c = 2; // PL/1

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;

  // ������ �������� 2-� ���������� �������
  // ��� ������������� 3-�� (�������������)
  a = 34634;
  b = -684;
  cout << "a = " << a << "  b = " << b << endl;

  a ^= b ^= a ^= b;

  cout << "a = " << a << "  b = " << b << endl;

  a = 2;
  b = 3;
  cout << "a==b " << (a == b) << endl;


  return 0;
}
