// ���� � ����� ������ (�������) � C � � C++. ���� � ����� �� ���������� �����.
#include <iostream>
#include <clocale>
#include <stdio.h>
#include <cstdlib>

using namespace std;

static int staticVar = 3;

int f() {
  static int local = 3;
  local++;
  return local;
}

// ���������, ������� ���������� ��� �����
int main() {
  // ���� � ����� �� ���������� �����
  // ����������������� ��� ����� �� �����
  //    freopen("input.txt", "r", stdin);
  // ����������������� ��� ������ � ����
  //    freopen("result.txt", "w", stdout);
  //    static int a = 3;
  setlocale(LC_ALL, "Russian");
  // ���� ���� �����
  int a, b; // ���������� ����������
  //cout << "������� A � B: ";
  cin >> a >> b; // Console INput
  // ��������
  int c = a + b;
  // ����� ����������
  cout << a << " + " << b << " = " << (a + b) << endl;
  system("pause");
  return 0;
}
