#include <stdio.h> /* ���������� ���������� */
#include <clocale>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Russian");
  printf("C: ������ ���!\n");
  return 0;
}