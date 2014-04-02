#include "mythread.h"
#include <iostream>

MyThread::MyThread(QObject *parent,
                   QString name) :
    QThread(parent), name(name)
{
}


void MyThread::run(){
    for(int i = 1; i < 1000; i++){
        std::cout << name.toStdString() << " " << i << std::endl;
        sleep(1);
    }
}
