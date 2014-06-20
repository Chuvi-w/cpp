#include <iostream>

#define X(t) cout << "sizeof(" << #t << ") = " << sizeof(t) << endl;

using namespace std;

struct Point {
    int x,y;
};

int main()
{
    int i = 1;

    X(int);
    X(char);
    X(long long);
    X(float);
    X(double);
    X(long double);
    X(char[10]);
    X(int*)
    X(int[10][20]);
    X(Point);


    return 0;
}
