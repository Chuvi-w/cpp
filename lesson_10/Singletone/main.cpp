#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class T>
class Singletone {
    static T* uniqueInstance;

public:
    static T& instance(){
        // Если объект ещё не создан
        if(uniqueInstance == NULL){
            // Создаём его
            uniqueInstance = new T();
             // Можно вызывать private конструктор, т.к.
             // мы внутри класса T
        }
        return *uniqueInstance;
    }
};

template <class T>
T* Singletone<T>::uniqueInstance = NULL;

// Singletone
class A : public Singletone<A> {
  friend class Singletone<A>;

  int id;

  A(){
      id = rand() % 10000;
      cout << "Constructor A #" << id << endl;
  }

public:

  ~A(){
      cout << "Destructor A #" << id << endl;
  }
  void show(){
      cout << "id = " << id << endl;
  }
};

int main()
{
    srand (time(NULL));
    A a = A::instance();
    A aa = A::instance();
    return 0;
}

