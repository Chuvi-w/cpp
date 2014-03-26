#include <iostream>
#include <map>
#include <locale.h>

using namespace std;

int main()
{
  // Контейнеры:
  //   vector
  //   set
  //   map
  setlocale(LC_ALL, "Russian");

  map<string, string> dict;

  dict["Hi"] = "Привет";
  dict["I"] = "Я";

  dict["You"] = "Ты";
  cout << dict["You"] << endl;

  dict["You2"] = "Ты2";
  cout << dict["You"] << endl;

  return 0;
}
