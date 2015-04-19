Перечисления (enum)
-------------------
Направления движения:
``` cpp
const int X_UP = 0;
const int X_DOWN = 1;
const int X_LEFT = 2;
const int X_RIGHT = 3;
int direction = X_UP;

enum Direction {
  UP = 4 /* 0 */, DOWN = 13 /* 1 */,
  LEFT = (1LL << 31) - 1 /* 2 */, RIGHT = 7/* 3 */
};

enum DirectionX {
  T_UP /* 0 */, T_DOWN /* 1 */,
  T_LEFT /* 2 */, T_RIGHT /* 3 */
};
```

#pragma pack(4)
[main.cpp](main.cpp)

