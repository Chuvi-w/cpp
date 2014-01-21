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
    // QCOMPARE( вычисление, ожидаемое_значение );
    QCOMPARE(a.max(1,   0), 1);  // 1 тест
    QCOMPARE(a.max(-1,  1), 1); // 2 тест
    QCOMPARE(a.max(4,   8), 8);  // 3 тест
    QCOMPARE(a.max(0,   0), 0);  // 4 тест
    QCOMPARE(a.max(1,   1), 1);  // 5 тест
    QCOMPARE(a.max(-10,-5), -5); // 6 тест
}

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

    try{
        long res = Smart::factorial(-1);
        QFAIL("Exception expected!");
    } catch(QString q){
        QCOMPARE( q, QString("N > 0"));
    }
}
