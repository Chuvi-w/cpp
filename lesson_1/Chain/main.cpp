#include <iostream>

using namespace std;

int main()
{
    int a = 3, b = 5;

    a = a * b; /* <=> */ a *= b;
    a = a + b; /* <=> */ a += b;
    a = a - b; /* <=> */ a -= b;
    a = a / b; /* <=> */ a /= b;
    a = a % b; /* <=> */ a %= b;

    a++;   a = a + 1;
    ++a;

    b = (++--++a++);

    a--; --a;



    //a += b += c = 2; // PL/1

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
