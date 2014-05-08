// Для чего использовать private-конструкторы
#include <iostream>

using namespace std;

class S {
  static int count;
  int id;

  S(){
    count++;
    id = count;
  }
  static S* instance;
public:
  static S& getInstance(){
    if(instance == NULL)
      instance = new S;
    return *instance;
  }
  void show(){
    cout << "S #" << id << endl;
  }
};

int S::count = 0;
S* S::instance = NULL;

int main() {
  S a = S::getInstance(), b = S::getInstance();
  a.show();
  b.show();
  S c = S::getInstance();
  c.show();
  return 0;
}
