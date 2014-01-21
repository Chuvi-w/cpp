#ifndef SMART_H
#define SMART_H

#include <QObject>
#include <QStringList>

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

};
#endif
