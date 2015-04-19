#include <iostream>
#include "module1.h"
#include "vars.h"

using namespace std;

void v1() {
  cout << "v1" << endl;
  globalVar = 1;
  cout << "globalVar = " << globalVar << endl;
}

void show1() {
  cout << "globalVar = " << globalVar << endl;
}


/// Определение глобальной переменной в **module1.cpp**
///-->
int globalVar = 2;
///<--
