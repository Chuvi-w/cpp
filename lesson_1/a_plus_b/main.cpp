#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  cout << "a = ";
  int a; // int - тип переменной, a - имя
  cin >> a;

  cout << "b = ";
  int b;
  cin >> b;

  // * - умножение
  // / - деление
  // % - остаток от деления (взятие по модулю)

  cout << "a - b = " << (a-b) << endl; // endl вместо "\n"

  system("NetTakoiComandy");
  system("pause");

  return 0;
}
