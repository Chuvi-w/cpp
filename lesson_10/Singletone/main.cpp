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
