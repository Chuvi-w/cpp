// Ссылки в C++
#include <iostream>

using namespace std;

void f1(int x){
    x++;
    cout << "x = " << x << endl;
}

void f2(int& x){
    x++;
    cout << "x = " << x << endl;
}

void f3(int* x){
    (*x)++;
    cout << "x = " << *x << endl;
}


void example1(){
    int a = 2;
    int &b = a;
    int *c = &a;
    b = 3;
    cout << "a = " << a << "  b = " << b << endl;
    a = 5;
    cout << "a = " << a << "  b = " << b << endl;
    *c = 4;
    cout << "a = " << a << "  b = " << b << " c = " << *c << endl;
}

void example2(){
    int a = 2;
    f1(a);
    cout << "a = " << a << endl;
    f2(a);
    cout << "a = " << a << endl;
    f3(&a);
    cout << "a = " << a << endl;
}

int main()
{
    example2();

    return 0;
}
