#include <QCoreApplication>
#include <QtTest/QTest>
#include "tests.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTest::qExec(new Tests, argc, argv);

    return a.exec();
}
