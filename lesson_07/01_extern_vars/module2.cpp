#include <iostream>
#include "module2.h"
#include "vars.h"

using namespace std;

/// В **module2.cpp** тоже можно использовать
/// **globalVar**
///-->
void v2() {
  cout << "v2" << endl;
  globalVar = 2;
  cout << "globalVar = " << globalVar << endl;
}

void show2() {
  cout << "globalVar = " << globalVar << endl;
}
///<--


