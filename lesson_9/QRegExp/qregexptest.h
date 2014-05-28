#ifndef QREGEXPTEST_H
#define QREGEXPTEST_H

#include <QObject>
#include <QString>

// Тестирование стандартных выражений QRegExp (PCRE - Perl Comp Reg Exp)
class QRegExpTest : public QObject
{
public:
    QRegExpTest();

    // Символы
    void symbols();

    // Группы символов
    void groups();

    // Кванторы
    void quantors();
};

#endif // QREGEXPTEST_H
