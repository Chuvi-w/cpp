#include <QCoreApplication>

struct MyClass {};
struct MyClass1 : public MyClass {};
struct MyClass2 : public MyClass {};


template<>
MyClass* Create<1>() {
  return new MyClass1();
}

template<>
MyClass* Create<2>() {
  return new MyClass2();
}

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  return a.exec();
}
