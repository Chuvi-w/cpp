// Самая характерная (распространённая)
// ошибка при применении if
#include <iostream>

using namespace std;

#define MY_CONST 3

int main() {
  int a = 2, b = 3;

  if(MY_CONST == a)
    cout << "a == b" << endl;
  else
    cout << "a != b" << endl;

  int i = 0, j;

  if(i == 0)
    cout << "True! i = 0" << endl;
  else
    cout << "False! i != 0" << endl;

  if(j = (i = 5))   // Использование присваивания "=" вместо "=="
    cout << "True!" << endl;
  else
    cout << "False!" << endl;

  cout << "j = " << j << endl;
  return 0;
}
