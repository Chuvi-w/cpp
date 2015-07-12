#include <iostream>
#include <vector>
#include <set>

#include <locale.h>

#define SHOW(x) { cout << #x << " = " << x << endl; };

using namespace std;

template <class T>
void show(T a) {
  int i = 0;

  for(typename T::iterator k = a.begin();
      k != a.end();
      k++)
    cout << (++i) << ". " << *k << endl;;
}

int main() {
  setlocale(LC_ALL, "Russian");

  // set - множество (неповторяющиеся элементы)
  cout << "set " << endl;
  set<int> s;
  s.insert(2);
  s.insert(2);
  s.insert(2);
  s.insert(2);
  show(s);
  s.insert(20);
  s.insert(3);
  s.erase(3);
  s.erase(2);
  show(s);

  // Вектор - аналог массива
  cout << "Vector (int) " << endl;
  vector<int> a(2, 1); // { 1, 1 }
  cout << "Capacity: " << a.capacity() << "  size: " << a.size() << endl;
  a.push_back(10);
  cout << "Capacity: " << a.capacity() << "  size: " << a.size() << endl;
  a.push_back(23);
  cout << "Capacity: " << a.capacity() << "  size: " << a.size() << endl;
  a.push_back(50);
  cout << "Capacity: " << a.capacity() << "  size: " << a.size() << endl;
  a.push_back(123);
  cout << "Capacity: " << a.capacity() << "  size: " << a.size() << endl;

  show(a);

  SHOW(a[0]);
  SHOW(a[1]);
  SHOW(a[2]);
  SHOW(a[3]);

  a.clear(); // Удалить все значения

  return 0;

  cout << "Первый элемент: " << a.front() << endl;
  cout << "Последний элемент: " << a.back() << endl;

  for(vector<int>::iterator k = a.begin();
      k != a.end();
      k++) {
    cout << *k << endl;

    if(*k == 23) {
      cout << "Нашли число 23: " << *k << endl;
      a.erase(k);
    }
  }

  for(size_t i = 0; i < a.size(); i++)
    cout << "a[" << (i + 1) << "] =  " << a[i] << endl;

  //a.insert(2, 10);
  //a.remove(3);
  a.clear();
  cout << "Добавляем 10 в конец вектора" << endl;
  a.push_back(10);

  show(a);

  return 0;
}
