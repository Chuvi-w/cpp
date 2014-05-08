#include <iostream>
#include <string.h>

class string {
  char    *Str;
  int     size;
public:
  string(string&); // ����������� �����������
  // �����������
  string(const char* str){
    size = strlen(str); // "ABC\0"
    Str = new char[size + 1];
    strcpy(Str, str);
  };
  // ����� ������ �� �����
  void show(){
    std::cout << Str << std::endl;
  }
  // ����������
  ~string(){
    delete[] Str; // ������� ������������ ������
  }
};

// ������� ����� ������������ ���������� � ��������
string::string(string& myVar) {
  Str = new char[myVar.size + 1];
  strcpy(Str,myVar.Str);
}

int main() {
  char myStr[] = "Test2";
  std::cout << myStr << std::endl;

  int i = (int)myStr;
  std::cout << i << std::endl;
  string s("Test");
  s.show();

  {
    string s2 = s; // ����� ������������ �����������
    s2.show();
  }

  s.show();


  return 0;
}
