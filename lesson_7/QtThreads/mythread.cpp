#include "mythread.h"
#include <iostream>

MyThread::MyThread(QObject *parent,
                   QString name,
                   int iterations) :
    QThread(parent), name(name),
      iterations(iterations)
{
}


void MyThread::run(){
    for(int i = 1; i <= iterations; i++){
        std::cout << name.toStdString() << " " << i << std::endl;
        sleep(1);
    }
}
