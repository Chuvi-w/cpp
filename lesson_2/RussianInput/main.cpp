#include <iostream>
#include <locale.h>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    char src[200];
    char dst[300];

    cout << "������� ����������� ��-������: ";
    cin >> src;
    OemToAnsi(src, dst);
    cout << "��� �� �����������: " << dst << endl;

    return 0;
}
