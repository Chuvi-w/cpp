#include "smart.h"
#include <QString>
#include <math.h>

Smart::Smart(QObject *parent) :
    QObject(parent)
{
}

int Smart::max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int Smart::min(int a, int b)
{
    if(a < b)
        return a;
    return b;
}

long Smart::factorial(int n){
    if(n <= 0)
        throw QString("N > 0");
    if(n > 2)
        return n * factorial(n-1);
    return n;
}

Roots Smart::quadraticEquation(double a, double b, double c){
    Roots r;
    if(a == 0){
        if(b == 0){
            if(c == 0){
                throw QString("Бесконечное число решений");
            }
            r.numberOfRoots = 0;
            return r;
        }
        r.numberOfRoots = 1;
        r.x[0] = -c/b;
        return r;
    }
    double D = b*b - 4*a*c;
    if(D > 0){
       r.numberOfRoots = 2;
       r.x[0] = (-b + sqrt(D)) / (2*a);
       r.x[1] = (-b - sqrt(D)) / (2*a);
    } else if(D < 0){
       r.numberOfRoots = 0;
    } else {
       r.numberOfRoots = 1;
       r.x[0] = 0.0;
    }
    return r;
}
