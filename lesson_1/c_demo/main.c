#include <stdio.h>
#include <stdlib.h>
//#include <conio.h> // ������� getch()

// �������
int myFunction() {
  return 10;
}

int globalVariable = 21;

int main() { // �������� ������� ���������
  printf("Hello world!\n"); // 13  13,10
  int c; // ���������� ����������
  scanf("%d", &c); // ������ � ����������
  //getch(); // ������ ������� ������� � ���������� � ASCII ���
  return 0;
}
