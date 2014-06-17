// Пример на погрешность вычислений в вещественных числах
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float f = 0.023; // 4 байта

    long double ld = 0.12; // 10 байт

    double a = 0.1; // 8 байт
    double b = 0.9;
    double c = 1;

//    if(a + b == c) {
    // fabs - взять по модулю
    if( fabs((a + b) - c) < 0.001)   {
      cout << a << " + " << b << " == " << c << endl;
    } else {
      cout << a << " + " << b << " != " << c << endl;
    }

    return 0;
}
