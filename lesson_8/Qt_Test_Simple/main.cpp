#include <QCoreApplication>
#include <QtTest/QTest>
#include "tests.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
  //freopen("debug.txt", "w", stdout);

  QCoreApplication a(argc, argv);

  QTest::qExec(new Tests, argc, argv);

  return a.exec();
}
