#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    // Win1251 � � �������� ������ � � �������
    setlocale(LC_ALL, "Russian");

    cout << "��������� ��� ���������� ����� �����" << endl;
    cout << "������� ����� ����� ��� ������������" << endl;
    cout << "��� ��������� ����� ������� 0" << endl;

    int sum = 0; // ������� �������� �����

    int num;

    // ���� � ������������
    // repeat until()
    do {
        // ���� �����
        cout << "������� �����: ";
        cin >> num;

        if(num != 0)
            sum += num;

    } while(num != 0);  /* ������� ����������� ����� */

    cout << "�����: " << sum << endl;

    return 0;
}
