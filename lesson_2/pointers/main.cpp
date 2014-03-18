#include <iostream>

using namespace std;

void f(int i){
  i++;
  cout << "i = " << i << endl;
}

void f2(int &i){
  i++;
  cout << "i = " << i << endl;
  cout << "Address = " << &i << endl;
}

void f3(int *i){
  cout << i << endl;
  i++;
  cout << i << endl;
  cout << "i = " << *i << endl;
}

int main()
{
  int i = 1;
  f3(&i);
  cout << "! i = " << i << endl;
  return 0;
}
