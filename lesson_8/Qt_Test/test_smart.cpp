#include <QtTest/QTest>
#include "test_smart.h"
#include "smart.h"

Test_Smart::Test_Smart(QObject* parent) :
  QObject(parent) {
}

// Тестирование вычисления максимума
void Test_Smart::max() {
  Smart a(this);
  // QCOMPARE( вызов_тестируемой_функции, ожидаемое_значение );
  QCOMPARE(a.max(2, 3), 3);  // 1 тест
  QCOMPARE(a.max(2, 4), 4);  // 2 тест
  QCOMPARE(a.max(5, 1), 5);
  QCOMPARE(a.max(1, 2), 2);
  QCOMPARE(a.max(-10, -20), -10);
}

// Тестирование вычисления факториала
void Test_Smart::factorial() {
  QCOMPARE( Smart::factorial(1), 1L );
  QCOMPARE( Smart::factorial(2), 2 * 1L );
  QCOMPARE( Smart::factorial(3), 3 * 2 * 1L );
  QCOMPARE( Smart::factorial(4), 4 * 3 * 2 * 1L );
  QCOMPARE( Smart::factorial(5), 5 * 4 * 3 * 2 * 1L );
  QCOMPARE( Smart::factorial(6), 6 * 5 * 4 * 3 * 2 * 1L );
  QCOMPARE( Smart::factorial(7), 7 * 6 * 5 * 4 * 3 * 2 * 1L );
  QCOMPARE( Smart::factorial(8), 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1L );
  QCOMPARE( Smart::factorial(9), 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1L );

  // Пример проверки исключения (ожидаемое исключение)
  try {
    long res = Smart::factorial(-1);
    QFAIL("Exception expected!");
  } catch(QString q) {
    QCOMPARE( q, QString("N > 0"));
  }
}

void Test_Smart::rootsTest() {
  // TDD
  Smart a(this);
  Roots roots = a.quadraticEquation(1, 0, 0);

  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], 0.0);

  roots = a.quadraticEquation(4, 0, 0);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], 0.0);

  roots = a.quadraticEquation(1, 0, -1);
  QCOMPARE(roots.numberOfRoots, 2);
  QCOMPARE(roots.x[0], 1.0);
  QCOMPARE(roots.x[1], -1.0);

  roots = a.quadraticEquation(1, 0, 1);
  QCOMPARE(roots.numberOfRoots, 0);

  roots = a.quadraticEquation(0, 1, 1);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], -1.0);

  roots = a.quadraticEquation(0, 0, 1);
  QCOMPARE(roots.numberOfRoots, 0);

  roots = a.quadraticEquation(0, 2, 1);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], -0.5);

  // 0*x*x + 0*x + 0 = 0
  try {
    a.quadraticEquation(0, 0, 0);
    QFAIL("Exception expected!");
  } catch(QString q) {
    QCOMPARE( q, QString("Бесконечное число решений"));
  }
}

// Число в строку
void Test_Smart::intToStrBefore100() {
  Smart s(this);
  QCOMPARE(s.intToStr(0), QString("Ноль"));
  QCOMPARE(s.intToStr(1), QString("Один"));
  QCOMPARE(s.intToStr(2), QString("Два"));
  QCOMPARE(s.intToStr(3), QString("Три"));
  QCOMPARE(s.intToStr(4), QString("Четыре"));
  QCOMPARE(s.intToStr(5), QString("Пять"));
  QCOMPARE(s.intToStr(9), QString("Девять"));
  QCOMPARE(s.intToStr(10), QString("Десять"));
  QCOMPARE(s.intToStr(11), QString("Одиннадцать"));
  QCOMPARE(s.intToStr(12), QString("Двенадцать"));
  QCOMPARE(s.intToStr(13), QString("Тринадцать"));
  QCOMPARE(s.intToStr(14), QString("Четырнадцать"));
  QCOMPARE(s.intToStr(15), QString("Пятнадцать"));
  QCOMPARE(s.intToStr(16), QString("Шестнадцать"));
  QCOMPARE(s.intToStr(20), QString("Двадцать"));
  QCOMPARE(s.intToStr(21), QString("Двадцать Один"));
  QCOMPARE(s.intToStr(22), QString("Двадцать Два"));
  QCOMPARE(s.intToStr(26), QString("Двадцать Шесть"));
  QCOMPARE(s.intToStr(30), QString("Тридцать"));
  QCOMPARE(s.intToStr(31), QString("Тридцать Один"));
  QCOMPARE(s.intToStr(32), QString("Тридцать Два"));
  QCOMPARE(s.intToStr(40), QString("Сорок"));
  QCOMPARE(s.intToStr(41), QString("Сорок Один"));
  QCOMPARE(s.intToStr(90), QString("Девяносто"));
  QCOMPARE(s.intToStr(91), QString("Девяносто Один"));
}

// Число в строку
void Test_Smart::intToStr_100_to_199() {
  Smart s(this);
  QCOMPARE(s.intToStr(100), QString("Сто"));
  QCOMPARE(s.intToStr(101), QString("Сто Один"));
  QCOMPARE(s.intToStr(102), QString("Сто Два"));
  QCOMPARE(s.intToStr(111), QString("Сто Одиннадцать"));
  QCOMPARE(s.intToStr(120), QString("Сто Двадцать"));
  QCOMPARE(s.intToStr(121), QString("Сто Двадцать Один"));
  QCOMPARE(s.intToStr(122), QString("Сто Двадцать Два"));
  QCOMPARE(s.intToStr(140), QString("Сто Сорок"));
  QCOMPARE(s.intToStr(141), QString("Сто Сорок Один"));
}

// Число в строку
void Test_Smart::intToStr_200_to_299() {
  /*    Smart s(this);
      QCOMPARE(s.intToStr(200), QString("Двести"));
      QCOMPARE(s.intToStr(201), QString("Двести Один"));
      QCOMPARE(s.intToStr(202), QString("Двести Два"));
      QCOMPARE(s.intToStr(211), QString("Двести Одиннадцать"));
      QCOMPARE(s.intToStr(220), QString("Двести Двадцать"));
      QCOMPARE(s.intToStr(221), QString("Двести Двадцать Один"));
      QCOMPARE(s.intToStr(222), QString("Двести Двадцать Два"));
      QCOMPARE(s.intToStr(240), QString("Двести Сорок"));
      QCOMPARE(s.intToStr(241), QString("Двести Сорок Один"));
  */
}
