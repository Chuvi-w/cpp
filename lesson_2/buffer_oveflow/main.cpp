// Переполнение строки символов
// Смертный Грех программиста №1 - источник уязвимостей
#include <iostream>

using namespace std;

int main()
{
  char password[8];
  int i = 0;

  cin >> password;
  cout << "i = " << i << endl;

  return 0;
}
