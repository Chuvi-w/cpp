// Простейший пример ООП
#include <iostream>

double
  x[100], y[100];

// Создали класс точка
struct Point {
  double x,y;
};

// Массив из точек
Point p[140];

class Point2D {
  double x,y;
};

// public / private / protected

using namespace std;

int main() {
    // Два отдельных массива
    x[0] = 1; y[0] = 2;
    // ООП
    p[0].x = 1; p[0].y = 2;

    Point p1;
    p1.x = 2;

    Point2D p2;
    p2.x = 2;

    cout << "Hello world!" << endl;
    return 0;
}
