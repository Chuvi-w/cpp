#include <QCoreApplication>
#include <mythread.h>
#include <iostream>
#include <QObject>
#include "observer.h"
#include "inputthread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread t1(NULL, "T1", 5),
             t2(NULL, "T2", 10);
    t1.start();
    t2.start();


    InputThread it(&a);

    Observer obs;

    a.connect(&t1, SIGNAL(finished()),
            &obs, SLOT(T1_finished()));

    a.connect(&it, SIGNAL(finished()),
              &a, SLOT(quit()));

   // t1.isRunning();
    it.start();

    return a.exec();
}
