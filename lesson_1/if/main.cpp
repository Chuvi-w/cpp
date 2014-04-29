#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int a = 2, b = 3;
    // && - логическое И
    // || - логическое ИЛИ
    // ! - логическое НЕ
    if(a != 2) {
        cout << "Верно!" << endl;
    } else
        cout << "Неверно!" << endl;

    a + b;
    int min = (a < b) ? a : b;

    return 0;
}
