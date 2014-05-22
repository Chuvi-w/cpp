#include "observer.h"
#include <iostream>

using namespace std;

Observer::Observer(QObject *parent) :
    QObject(parent)
{
}

void Observer::T1_finished(){
    cout << "Observer::T1_finished()" << endl;
}
