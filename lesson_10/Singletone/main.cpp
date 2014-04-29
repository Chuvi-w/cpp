<<<<<<< HEAD
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

=======
#include <iostream>

using namespace std;

class A {
    static int count;
    int id;
    // Конструктор
    A(){
        id = ++count;
        cout << "Constructor A " << id << endl;
    }
    static A* a;
public:
    // Деструктор
    ~A(){
        if(a == NULL)
            return;
        cout << "Destructor A " << id << endl;
        a = NULL;
    }
    static A& instance(){
        if(a == NULL){
            a = new A();
        }
        return *a;
    }
    void show(){
        cout << "A id = " << id << endl;
    }
};

int A::count = 0;
A* A::a = NULL;

int main()
{
    A a = A::instance(),
      b = A::instance();
    a.show();
    b.show();
    return 0;
}
>>>>>>> 9c9407c474873705198f17574aef541fe3184bb4
