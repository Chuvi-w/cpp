#include <QtTest/QTest>
#include "test_smart.h"
#include "smart.h"

Test_Smart::Test_Smart(QObject *parent) :
    QObject(parent)
{
}

// Тестирование вычисления максимума
void Test_Smart::max()
{
    Smart a(this);
    // QCOMPARE( вызов_тестируемой_функции, ожидаемое_значение );
    QCOMPARE(a.max(1,   0), 1);  // 1 тест
    QCOMPARE(a.max(-1,  1), 1);  // 2 тест
    QCOMPARE(a.max(4,   8), 8);  // 3 тест
    QCOMPARE(a.max(0,   0), 0);  // 4 тест
    QCOMPARE(a.max(1,   1), 1);  // 5 тест
    QCOMPARE(a.max(-10,-5), -5); // 6 тест
}

// Тестирование вычисления факториала
void Test_Smart::factorial(){
    QCOMPARE( Smart::factorial(1), 1L );
    QCOMPARE( Smart::factorial(2), 2*1L );
    QCOMPARE( Smart::factorial(3), 3*2*1L );
    QCOMPARE( Smart::factorial(4), 4*3*2*1L );
    QCOMPARE( Smart::factorial(5), 5*4*3*2*1L );
    QCOMPARE( Smart::factorial(6), 6*5*4*3*2*1L );
    QCOMPARE( Smart::factorial(7), 7*6*5*4*3*2*1L );
    QCOMPARE( Smart::factorial(8), 8*7*6*5*4*3*2*1L );
    QCOMPARE( Smart::factorial(9), 9*8*7*6*5*4*3*2*1L );

    // Пример проверки исключения (ожидаемое исключение)
    try{
        long res = Smart::factorial(-1);
        QFAIL("Exception expected!");
    } catch(QString q){
        QCOMPARE( q, QString("N > 0"));
    }
}

void Test_Smart::rootsTest(){
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
    try{
        a.quadraticEquation(0, 0, 0);
        QFAIL("Exception expected!");
    } catch(QString q){
        QCOMPARE( q, QString("Бесконечное число решений"));
    }
}
