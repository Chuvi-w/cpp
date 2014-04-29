#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  cout << "a = ";
  int a; // int - тип переменной, a - им€
  cin >> a;

  cout << "b = ";
  int b;
  cin >> b;

  // * - умножение
  // / - деление
  // % - остаток от делени€ (вз€тие по модулю)

  cout << "a - b = " << (a-b) << endl; // endl вместо "\n"

  system("NetTakoiComandy"); // ѕример, когда мы пытаемс€ 
    // вызвать несуществующую команду операционной системы
  system("pause");

  return 0;
}
