#include <iostream>

using namespace std;

struct Point {
  double x,y;
};

int main()
{
    int *intArray;
    intArray = new int[1000];
    intArray[0] = 10;
    intArray[1] = 23;
    delete[] intArray;

    Point *p = new Point;
    delete p; // delete без скобочек []

    return 0;
}
