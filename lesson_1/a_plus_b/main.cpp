#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  cout << "a = ";
  int a; // int - ��� ����������, a - ���
  cin >> a;

  cout << "b = ";
  int b;
  cin >> b;

  // * - ���������
  // / - �������
  // % - ������� �� ������� (������ �� ������)

  cout << "a - b = " << (a-b) << endl; // endl ������ "\n"

  system("NetTakoiComandy"); // ������, ����� �� �������� 
    // ������� �������������� ������� ������������ �������
  system("pause");

  return 0;
}
