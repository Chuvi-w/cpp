#include "smart.h"
#include <QString>

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
