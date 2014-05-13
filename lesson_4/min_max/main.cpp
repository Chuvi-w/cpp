#include <iostream>
#include <assert.h>

template <class T>
T min(T a, T b){
    return (a < b) ? a : b;
}

template <class T>
T max(T a, T b){
    return (a > b) ? a : b;
}

// ��������� �������
template <class T>
T findMax(T* a, size_t size){ // size_t - ���, ������� ���������� ���������� ��� ���������� ��������
  // �����������
  assert(size >= 1); //, "������ ������ ���������� ������!");
  T curMax = a[0];
  for(size_t i = 1; i < size; i++)
    if(a[i] > curMax)
      curMax = a[i];
  return curMax;
}

// ��������� ��������:
//   ����: class G / typename T
//   ����� �� �����: int I

// �������, ����������� ���������
template <class T, int A>
T add(T value){
  return value + A;
}

using namespace std;

int main() {
  double x[] = {5.2, 10.10, 13.5, 11.1};
  cout << findMax(x, 4) << endl;

  int c[] = {5, 6, 4, 2, 3};
  cout << findMax(c, 5) << endl;

  char d[] = {'x', 'f', 'B', 'K', 'L' };
  cout << findMax(d, 5) << endl;

  string s[] = {"hi", "test", "aa", "bb", "test2"};
  cout << findMax(s, 5) << endl;

  int h[3][3] = {
    { 1, 2,  3 },
    { 4, 16, 5 },
    { 3, 8,  6 },
  };

  cout << findMax((int*)h, 9) << endl;
}
