#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QRegExp rx("(\\d+)");
    QString str = "Offsets:   12  sdgsd 14 99 231 7";
    //QStringList list;
    int pos = 0;

    while ((pos = rx.indexIn(str, pos)) != -1) {
       //list << rx.cap(1);
       qDebug() << rx.cap(1);
       int len = rx.matchedLength();
       pos += len;
       qDebug() << len;
    }

    //MainWindow w;
    //w.show();

    return a.exec();
}
