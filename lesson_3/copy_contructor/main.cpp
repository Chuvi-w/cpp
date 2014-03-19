#include <iostream>
#include <string.h>

class string {
  char    *Str;
  int     size;
public:
  string(string&); // Конструктор копирования
  // Конструктор
  string(const char* str){
    size = strlen(str); // "ABC\0"
    Str = new char[size + 1];
    strcpy(Str, str);
  };
  // Вывод строки на экран
  void show(){
    std::cout << Str << std::endl;
  }
};

// Создает копии динамических переменных и ресурсов
string::string(string& myVar) {
  Str = new char[myVar.size + 1];
  strcpy(Str,myVar.Str);
}

int main()
{
  char* myStr = "Test2";
  std::cout << myStr << std::endl;

  int i = (int)myStr;
  std::cout << i << std::endl;
  string s("Test");
  s.show();
  string s2 = s;
  s2.show();
  return 0;
}
