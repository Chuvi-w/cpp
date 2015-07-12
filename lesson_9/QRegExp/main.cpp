#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtTest/QTest>
#include "qregexptest.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  QTest::qExec(new QRegExpTest, argc, argv);

  MainWindow w;
  w.show();

  return a.exec();
}
