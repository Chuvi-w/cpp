#include <iostream>
#include <map>
#include <locale.h>

using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");

  map<string, string> dict;

  dict["Hi"] = "������";
  dict["I"] = "�";

  dict["You"] = "��";
  cout << dict["You"] << endl;

  dict["You2"] = "��2";
  cout << dict["You"] << endl;

  return 0;
}
