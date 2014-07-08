#include <QCoreApplication>
#include <QtSql> // Для работы с SQLite

int main() {
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    // Назначаем имя файлу
    dbase.setDatabaseName("../HomeWork/practic.sqlite");
    // Открываем БД
    if (!dbase.open()) {
        qDebug() << dbase.lastError().text();
        return 1;
    }

    QSqlQuery q;
    if(!q.exec("SELECT * FROM students")){
        qDebug() << q.lastError().text();
        return 1;
    }

    while(q.next()){
        qDebug() << q.value("name").toString() <<
                   "  " << q.value("surname").toString();
    }

    return 0;
}
