// ������������ �������������� ������ � "������" �
#include <stdio.h>
#include <stdlib.h>

int main() {
  // ����� ������ �����
  int i = 12;
  printf("%d %d\n", i, sizeof(i));
  i = 254;
  printf("%x\n", i);
  printf("%X\n", i);
  printf("%04X\n", i);
  printf("%4X\n", i);
  // ����� �������� ������
  long l = 2123456789;
  printf("%ld %d\n", l, sizeof(l));
  // ����� ��� ����� �������� ������ :)
  long long ll = 912345678900L;
  printf("%lld %d\n", ll, sizeof(ll));

  // signed / unsigned
  // �������� / �����������
  unsigned int ui = 3000000000;
  printf("%u\n", ui);

  // 'long long long' is too long for GCC
  // long long long lll = 912345678900L;
  // printf("%llld %d\n", lll, sizeof(lll));

  float f = 1.2f;
  printf("%f %d\n", f, sizeof(f));
  // 2 ����� ����� ������� (�����)
  printf("%.2f %d\n", f, sizeof(f));

  double d = 1.2;
  printf("%lf %d\n", d, sizeof(d));

  char c = 'B';
  printf("%c\n", c);

  char s[] = "HELLO";
  printf("%s\n", s);

  return 0;
}
