#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double d;
    cout << "������� �����: ";
    cin >> d;

    cout << d << " � �������� ����� " << d*d << endl;
    return 0;
}
