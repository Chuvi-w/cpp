#include <iostream>
#include <fstream>
#include <locale.h>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    char src[200];
    char dst[200];

    ofstream of("text.txt");

    cout << "������� ����������� ��-������: ";
    cin >> src;
    OemToAnsi(src, dst);
    cout << "��� �� �����������: " << dst << endl;
    of << "��� �� �����������: " << dst << endl;

    of.close();

    return 0;
}
