#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  // Вызов главной формы через указатель
  MainWindow* w = new MainWindow;
  w->show();

  // Сохраняем результат выполнения...
  int res = a.exec();

  // ...чтобы очистить память...
  delete w;
  // ...и только потом выйти!
  return res;
}
