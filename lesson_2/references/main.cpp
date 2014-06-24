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
    int a = 2; // a - локальная переменная, в ней 2
    int &b = a; // b - ссылка на a, т.е. та же переменная с другим именем
    int *c = &a; // с - указатель на a..
    int d = 10;
    b = 3;
    cout << "a = " << a << "  b = " << b << endl;
    a = 5;
    cout << "a = " << a << "  b = " << b << endl;
    cout << c; // Выводим адрес
    cout << *c; // Выводим значение
    *c = 4;
    cout << "a = " << a << "  b = " << b << " c = " << *c << endl;

    // В с теперь будет адрес d
    c = &d;
    cout << *c << endl; // Теперь выведем значение d
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
    example1();
    //example2();

    return 0;
}
