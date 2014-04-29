// ѕример на погрешность вычислений
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float f = 0.023; // 4 байта

    double a = 0.1; // 8 байт
    double b = 0.9;
    double c = 1;

    long double ld = 0.12; // 10 байт

    if( fabs((a + b) - c) < 0.001)   {
      cout << a << " + " << b << " == " << c << endl;
    } else {
      cout << a << " + " << b << " != " << c << endl;
    }


    return 0;
}
