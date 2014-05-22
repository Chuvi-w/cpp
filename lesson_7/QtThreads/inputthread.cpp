#include "inputthread.h"
#include <iostream>

using namespace std;

InputThread::InputThread(QObject *parent) :
    QThread(parent)
{
}

void InputThread::run(){
   int i;
   cin >> i;
  //  sleep(5);
   cout << "!!!!";
   //QCoreApplication::exit();
}
