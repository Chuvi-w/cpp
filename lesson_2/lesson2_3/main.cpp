#include <iostream>
#include <clocale> // setlocale

using namespace std;

int main()
{
    // Win1251 � � �������� ������ � � �������
    setlocale(LC_ALL, "Russian");

    cout << "== ������������ �����-���������� ==" << endl;
    cout << "������� ����� ����� ����� �����: ";
    int metro;
    cin >> metro;
    switch(metro){
    case 1:
        cout << "�������: ��������-����������. ����� ������ ����� �����." << endl;
        break;
    case 2:
        cout << "�����: ���������-�������������. " << endl;
        break;
    case 3:
        cout << "������: ����������������" << endl;
        break;
    case 4:
        cout << "Ƹ����: �������������" << endl;
        break;
    case 5:
        cout << "����������: �������-��������������" << endl;
        break;
    default:
        cout << "� �� ���� :) ����� ����� ��� �� ��������� � 2013 ����." << endl;
    }

    //double d = 1.1;
    //switch(d){ <-- ������ ����������, �.�. d ���������� � ������ ����
    //case 1.1:
    // break;
    //}

    char c = 'A';
    switch(c){
    case 'A':
      cout << "A!!" << endl;
      break;
    }

    return 0;
}
