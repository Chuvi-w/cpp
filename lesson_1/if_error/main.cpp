// Самая характерная (распространённая)
// ошибка при применении if
#include <iostream>

using namespace std;

int main()
{
  int i = 0, j;
  if(i == 0){
    cout << "True!" << endl;
  } else {
    cout << "False!" << endl;
  }

  if(j = (i = 5)){  // Использование присваивания "=" вместо "==" 
    cout << "True!" << endl;
  } else {
    cout << "False!" << endl;
  }
  cout << "j = " << j << endl;
  return 0;
}
