#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Singletone
class A {
  int id;

  A(){
      id = rand() % 10000;
      cout << "Constructor A #" << id << endl;
  }

  static A* uniqueInstance;

public:
  ~A(){
      cout << "Destructor A #" << id << endl;
  }
  void show(){
      cout << "id = " << id << endl;
  }

  static A& instance(){
      // Если объект ещё не создан
      if(uniqueInstance == NULL){
          // Создаём его
          uniqueInstance = new A();
           // Можно вызывать private конструктор, т.к.
           // мы внутри класса A
      }
      return *uniqueInstance;
  }
};

A* A::uniqueInstance = NULL;

int main(int argc, char *argv[])
{
    srand (time(NULL));
    A a = A::instance();
    A aa = A::instance();
    return 0;
}
