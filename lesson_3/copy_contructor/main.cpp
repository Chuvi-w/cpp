#include <iostream>
#include <string.h>

class string {
  static int count; // ���������� �����
  char    *Str;
  int     size;
public:
  int id; // ������������� ������ ������
  string(string&); // ����������� �����������
  // �����������
  string(const char* str){
    id = ++count;
    std::cout << "Constructor #" << id << " \"" << str << "\"" << std::endl;
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
    std::cout << "Destructor #" << id << std::endl;
    delete[] Str; // ������� ������������ ������
  }
  // ���������� �������� ������������
  string& operator=(string& right){
    if(Str != NULL)
      delete[] Str;
    std::cout << "= #" << id << std::endl;
    // if(Str != NULL)
    //   delete[] Str;
    Str = new char[right.size + 1];
    size = right.size;
    strcpy(Str, right.Str);
  }
};

// ������� ����� ������������ ���������� � ��������
string::string(string& myVar) {
  id = ++count;
  std::cout << "Copy constructor #" << id << std::endl;
  // if(Str != NULL)
  //   delete[] Str;
  Str = new char[myVar.size + 1];
  size = myVar.size;
  strcpy(Str,myVar.Str);
}

int string::count = 0;

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


  {
    string s3("Hello world!");
    s3 = s; // �������� ������������
    s3.show();
  }

  s.show();


  return 0;
}
