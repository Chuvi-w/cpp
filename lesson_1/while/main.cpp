#include <iostream>
using namespace std;

int main() {
  // ����� �� ������� �����
  setlocale(LC_ALL, "Russian");
  int i = 0; // �������������� ������� �����
  int sum = 0; // �����

  while(i < 1000) {
    i++;
    sum += i;
  }

  cout << "����� ����� �� 1 �� 1000 = " << sum << endl;
  return 0;
}

// ��������� ��� �������� ������
struct addr {
  char name[40];
  char street[40];
  char city[40];
  char state[3];
  char zip[10];
};

struct addr* get_struct(void) {
  struct addr* p;

  if((p = malloc(sizeof(struct addr))) == NULL) {
    printf("������ ��� ������������� ������\n");
    exit(1);
  }

  return p;
}

#define MAX(a,b) ((a) > (b) ? (a) : (b))

// � ����� C:
Point* p = (Point*) malloc(sizeof(Point));
free(p);

// � ����� C++
Point* p = new Point;
delete p;







