#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union IntAsByte {
    int i;
    unsigned char b[sizeof(int)];
};

struct MyStruct {
  int i;
  double d;
  char s[10];
  float f;
  union IntAsByte iab;
} p;

int main()
{
    char* s;
    s = malloc(100); // 100 байт
    strcpy(s, "Test\n");
    printf("s = %s\n", s);
    free(s);
    s = NULL;

    struct MyStruct m;
    m.i = 2;
    m.d = 3;
    m.iab.i = 258; // Младший байт 2
      // чуть постарше 1

    return 0;
}
