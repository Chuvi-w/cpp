#include <iostream>
#include <vector>
#include <set>

#include <locale.h>

using namespace std;

template <class T>
void show(T a){
  int i = 0;
  for(typename T::iterator k = a.begin();
      k != a.end();
      k++){
    cout << (++i) << ". " << *k << endl;
  };
}


int main()
{
  setlocale(LC_ALL, "Russian");

  cout << "���������" << endl;
  set<int> s;
  s.insert(2);
  s.insert(2);
  s.insert(2);
  s.insert(2);
  s.insert(20);
  s.insert(3);
  s.erase(3);
  s.erase(2);
  show(s);

  cout << "������ �����" << endl;
  vector<int> a(2, 1);
  a.push_back(10);
  a.push_back(23);
  a.push_back(50);
  a.push_back(123);

  show(a);

  return 0;

  cout << "������ �������: " << a.front() << endl;
  cout << "��������� �������: " << a.back() << endl;

  for(vector<int>::iterator k = a.begin();
      k != a.end();
      k++){
    cout << *k << endl;
    if(*k == 23){
      cout << "������� ������� " << *k << endl;
      a.erase(k);
    }
  }

  for(size_t i = 0; i < a.size(); i++)
    cout << (i+1) << ". " << a[i] << endl;

  cout << "������� ���������" << endl;
  //a.insert(2, 10);
  //a.remove(3);
  a.clear();
  cout << "��������� 10" << endl;
  a.push_back(10);

  show(a);

  return 0;
}
