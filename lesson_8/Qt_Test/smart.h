#ifndef SMART_H
#define SMART_H

#include <QObject>
#include <QStringList>

// a + b = c
int sum(int a, int b){

}


// Корни квадратного уравнения
struct Roots {
    int numberOfRoots;
    double x[2];
};

// Тестируемый класс
class Smart : public QObject
{
    Q_OBJECT
public:
    explicit Smart(QObject *parent);

public slots:
    // Вычисление максимума
    int max(int a, int b);
    // Вычисление минимума
    int min(int a, int b);

    static long factorial(int n);

    Roots quadraticEquation(double a, double b, double c);

    // Число в строку
    QString intToStr(int N);
};
#endif
