#include <iostream> // cin/cout

#include <vector> // ��������� vector
#include <set> // ��������� ���������
#include <map> // ��������� map

using namespace std;

// template<���������>
//   class ���_������{}
//   ���_�������������_�������� �������(���������)

// ���������:
//    int aa, char A, class T / typename T
//  template<template<int> class X>

template<template<int> class X>
class MyClass{
//    X
};

template<class T>
void print_vector(vector<T> v){
  typename vector<T>::iterator i;
  for(i = v.begin(); i != v.end(); i++)
    cout << *i << endl;
}

template<class V> // class V, typename V, int size
void print(const char *title, V v){
  cout << title << endl;
  int cnt = 0;
  if(v.empty()){
      cout << "Container is empty" << endl;
      return;
  }
  cout << "size: " << v.size() << endl;
  for(typename V::iterator i = v.begin(); i != v.end(); i++)
    cout << ++cnt << ". " << *i << endl;
}

// ���� �� ������ �������
template<typename T, int size>
class Stack {
  // ��-��������� private
  T data[size]; // ������
  int count; // ���������� ���������
public:
  Stack() : count(0) {}
  //Stack() { count = 0; }
  // ��������� �� ������� �����
  void push(T x){ data[count++] = x; }
  // �������� �������� � ������� �����
  T pop(){ return data[--count]; }
};

int main(int argc, char *argv[])
{    
    Stack<int, 20> stack;
    stack.push(10);
    cout << stack.pop() << endl;

    setlocale(LC_ALL, "Russian");

    // vector<���> ���_����������(����������, ���������_��������)
    vector<int> intVector;      // ������ (���� ���������) ������ �� ��������� ���� int
    vector<float> floatVector(10); // ������ �� 10-� ��������� ���� float
    vector<char> charVector(5, '#'); // ������, ��������� �� 5-� �������� '#'

    // ��������� � ����� �������
    intVector.push_back(3);
    intVector.push_back(10);
    intVector.push_back(3);

    cout << "Vector size: " << intVector.size() << endl;

    print_vector<int>(intVector);
    print<vector<int> >("intVector:", intVector);
    print<vector<char> >("charVector:", charVector);

    for(unsigned int i = 0; i < intVector.size(); i++){
        cout << intVector[i] << endl;
    }

    // ���_�������::iterator
    vector<int>::iterator it;
    for(it = intVector.begin(); it != intVector.end(); it++){
        cout << *it << endl;
    }
    it = intVector.end();
    for(it--; it != intVector.begin(); --it){
        cout << *it << endl;
    }
    cout << *it << endl;

    intVector.clear(); // ��������� ��� �������� � ������ ����� ����� 0
    cout << "capacity: " << intVector.capacity() << endl;

    // ���������
    set<int> intSet;
    // ��������� ��������
    intSet.insert(1);
    //if(intSet.find(1))
    //    cout << "1 exists" << endl;
    intSet.insert(1);
    intSet.insert(2);
    // ������� �������
    intSet.erase(1);
    intSet.erase(2);
    print<set<int> >("intSet: ",intSet);

    // map - �������
    //map<���_�����, ���_��������>
    map<char, int> m;
    pair<char, int> pair = make_pair<char, int>('A', 10);
    m.insert(pair);
    cout << pair.first << " " << pair.second << endl;

    //m.insert('D', 30);
    m['E'] = 35;

    return 0;
}
