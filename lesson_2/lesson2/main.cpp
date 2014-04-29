// Тернарный оператор
#include <iostream>

using namespace std;

int main()
{
    int a = 4, b = 0;

    const bool cond = a > 3;

    // Может находиться слева от оператора присваивания
    (cond ? a : b) = 1;

    cout << "a = " << a << "  b = " << b << endl;
    return 0;
}
