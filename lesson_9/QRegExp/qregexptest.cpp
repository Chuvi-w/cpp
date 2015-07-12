#include <QtTest/QTest>
#include "qregexptest.h"

QRegExpTest::QRegExpTest(QObject* parent) :
  QObject(parent) {
}

// Символы
void QRegExpTest::symbols() {
  QRegExp rx("\\s"); // Любой пробельный символ
  QCOMPARE(2, rx.indexIn("a "));
  QCOMPARE(3, rx.indexIn("ab\n")); // Перевод строки
  QCOMPARE(5, rx.indexIn("abcd\tsdf")); // Табуляция
  QCOMPARE(2, rx.indexIn("a "));



}

// Группы символов
void QRegExpTest::groups() {

}

// Кванторы
void QRegExpTest::quantors() {
  // + - один и больше
  QRegExp rx("\\d+"); // Любое число
  rx.indexIn("ab123");
}
