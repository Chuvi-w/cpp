#ifndef TEST_SMART_H
#define TEST_SMART_H

#include <QObject>
#include <QString>

// Класс, который содержит тесты
class Test_Smart : public QObject
{
    Q_OBJECT
public:
    explicit Test_Smart(QObject *parent = 0);

private slots: // должны быть приватными
    void max();

    // Новый тест для вычисления факториала
    void factorial();

    // Тест для квадратного уравнения
    void rootsTest();

    // Число в строку
    void intToStrBefore100();

    void intToStr_100_to_199();

    void intToStr_200_to_299();
};

#endif // TEST_SMART_H
