#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int a = 2, b = 3;
    // && - ���������� �
    // || - ���������� ���
    // ! - ���������� ��
    if(a != 2) {
        cout << "�����!" << endl;
    } else
        cout << "�������!" << endl;

    a + b;
    int min = (a < b) ? a : b;

    return 0;
}
