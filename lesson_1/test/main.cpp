#include <iostream>
#include <cstdlib>

using namespace std; // ������������ ���, ����� �� ������ ����� std::cin

int main() { // �������� �������
  cout << "Hello World!" << endl; // ������� �� �����
  cout << "Enter two numbers" << endl;
  int a, b; // ��������� 2 ���������� ������ ����
  cin >> a >> b; // ������ �� � ����������
  cout << a << " + " << b << " = " << a + b << endl; // ����� �����
  system("pause"); // ������� ����� �������...
  return 0; // ��������� ����������� ������, 0 - ��� ��������
}
