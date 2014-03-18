#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (a < b) ? a : b

int main()
{
  int a = 12, b = 4259;
  printf("MIN(%d,%d) = %d\n", a, b, MIN(a,b));
  double d1 = 0.12, d2 = 23.2;
  printf("MIN(%lf,%lf) = %lf\n", d1, d2, MIN(d1,d2));
  return 0;
}
