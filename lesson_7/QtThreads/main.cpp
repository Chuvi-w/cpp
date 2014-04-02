#include <QCoreApplication>
#include <mythread.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread t1(NULL, "T1"),
             t2(NULL, "T2");
    t1.start();
    t2.start();

    int i;
    std::cin >> i;

    return a.exec();
}
