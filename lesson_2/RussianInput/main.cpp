#include <iostream>
#include <locale.h>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    char src[200];
    char dst[300];

    cout << "¬ведите предложение по-русски: ";
    cin >> src;
    OemToAnsi(src, dst);
    cout << "Ёто же предложение: " << dst << endl;

    return 0;
}
