#ifndef TESTS_H
#define TESTS_H

#include <QtTest/QTest>
#include "sum.h"

// Все тесты
class Tests : public QObject
{
    Q_OBJECT

private slots:
    void testSumB(){
        // 1 тест
        QCOMPARE(sum(2,3), 5);
        // 2 тест
        QCOMPARE(sum(2,4), 6);
    }
    void testSumA(){
        QCOMPARE(sum(3,3), 6);
        QCOMPARE(sum(3,4), 7);
    }

    void divisors1(){
        QCOMPARE(divisors(10), 4);
    }

    void divisors2(){
        QCOMPARE(divisors(1), 1);
    }

};

#endif // TESTS_H
