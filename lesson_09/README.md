.\000_intro.md
﻿SQL (на примере sqlite), QtSql
==============================

https://lisiynos.googlecode.com/git/dp/cpp_6_sql.html

Firefox Plugin:
https://addons.mozilla.org/ru/firefox/addon/sqlite-manager/


Язык SQL: SELECT, INSERT, UPDATE, DELETE
----------------------------------------

**SQL (structured query language - «структурированный язык запросов»)** - формальный непроцедурный язык программирования,
применяемый для создания, модификации и управления данными в произвольной реляционной базе данных,
управляемой соответствующей системой управления базами данных (СУБД). SQL основывается на исчислении кортежей.

**Data Definition Language (DDL)** - язык описания данных: CREATE.

``` sql
SELECT * FROM имяТаблицы  -- Получить все записи из таблицы
SELECT поле1 FROM имяТаблицы  -- Получить только поле поле1 из таблицы
SELECT поле1,поле2 FROM имяТаблицы
SELECT * FROM имяТаблицы WHERE поле1 = 'Значение' -- Только записи где поле1 равно значению
```

Выбираем Фамилию, Имя, Отчество через пробел как одну строчку:

``` sql
SELECT surname || ' ' || name || ' ' || middlename FROM contacts
```

Убираем пробелы в начале и конце строк:

``` sql
UPDATE contacts SET name = trim(name), surname=trim(surname), middlename=trim(middlename)
```

``` sql
SELECT * FROM contacts WHERE name='Иван' AND surname='Иванов'
```

``` sql
SELECT contacts.surname, contacts.name, contacts.middlename,
   phones.phone,
   phone_type.name AS type
  FROM phones JOIN contacts ON phones.id_contact = contacts.id
    JOIN phone_type ON phones.id_type = phone_type.id
```

LEFT JOIN - строки из таблицы слева всегда присутствуют.

``` sql
SELECT contacts.surname, contacts.name, contacts.middlename, phones.phone, phone_type.name AS type
FROM contacts LEFT JOIN phones ON phones.id_contact = contacts.id LEFT JOIN phone_type ON phones.id_type = phone_type.id
``

``` sql
-- Ищем нужные данные
SELECT * FROM contacts WHERE surname = 'Сидоров'
-- Обновляем записи
UPDATE contacts SET middlename='Петрович' WHERE surname = 'Сидоров'
```

``` sql
INSERT INTO contacts(surname, name, middlename, sex) VALUES('Иванов', 'Сидор', 'Матвеевич', 'M')
```

``` sql
DELETE FROM contacts WHERE surname = 'Иванов'
```

```sql
BEGIN TRANSACTION  -- Начало транзакции
COMMIT -- Фискируем изменения
ROLLBACK -- Отменяем все изменения
```

Подключение к Базе Данных из Qt
-------------------------------

Класс **QSqlDatabase** представляет подключение к базе данных.

Соединение предоставляет доступ к базе данных через один из поддерживаемых драйверов баз данных, которые унаследованы от QSqlDriver.

Как написать собственный драйвер БД:
http://doc.crossplatform.ru/qt/4.5.0/sql-driver.html#how-to-write-your-own-database-driver

Названия драйверов для Qt: http://qt-project.org/doc/qt-5/sql-driver.html

Как создать и открыть соединение по умолчанию к базе данных **PostgreSQL**:
``` cpp
QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
db.setHostName("acidalia");
db.setDatabaseName("customdb");
db.setUserName("mojito");
db.setPassword("J0a1m8");
bool ok = db.open();
```

``` cpp
  // Подключаем драйвер для работы с SQLite
  QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
  // Имя файла с SQLite базой данных
  dbase.setDatabaseName("my_db.sqlite");
    // Для других БД - строка соединения
  if (!dbase.open()) {
    qDebug() << "Не получилось открыть/создать файл с базой данных!";
    return -1;
  }
```

Выполнение инструкций SQL. Выполнение запроса и навигация по результирующей выборке
-----------------------------------------------------------------------------------

``` cpp
  // -- Создание схемы БД --
  // DDL query - создаём новую таблицу
  // Data Definition Language (DDL) - язык описания данных
  // Создаём табалицу контактов
  SQL_Execute("CREATE TABLE contacts ("
              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
              "name TEXT,"
              "surname TEXT,"
              "birthday TEXT);");
  // Создаём таблицу телефонов
  SQL_Execute("CREATE TABLE phones ("
              "contact_id NUMERIC,"
              "phone TEXT);");
```

Вставка, изменение и удаление записей
-------------------------------------



Транзакции
----------

Использование классов-моделей SQL (модель запроса, модель таблицы). Отображение данных в таблице-представлении
--------------------------------------------------------------------------------------------------------------



Сетевое программирование. QtNetwork
===================================

Клиент-серверные приложения. Общие принципы. Обработка подключений в отдельном потоке
-------------------------------------------------------------------------------------

Написание HTTP- и FTP-клиентов с помощью классов QHttp и QFtp
-------------------------------------------------------------

Использование TCP с помощью классов QTcpSocket и QTcpServer
-----------------------------------------------------------

Многопоточное программирование
------------------------------

Системы контроля версий, git. Юнит-тестирование. QtTest. Shell
==============================================================

Системы контроля версий: централизованные (SVN), децентрализованные (git)
-------------------------------------------------------------------------

Основные команды git (pull, push, commit, fetch..). Использование TortoiseGit. Хостинг на github и bitbucket
------------------------------------------------------------------------------------------------------------
* https://github.com
* https://bitbucket.org
* https://code.google.com

Виды тестов: модульные, приёмочные (общее и отличия). Ручное тестирование. Модульные тесты в С/C++: CUnit, CppUnit (возможности)
--------------------------------------------------------------------------------------------------------------------------------

QtTest
------

Test Driven Development - разработка через тестирование ("красная" и "зелёная" полоса, цикл: тест - разработка - рефакторинг)
-----------------------------------------------------------------------------------------------------------------------------

Объекты заглушки (MockObjects) и их использование (цели, применимость)
----------------------------------------------------------------------




Регулярные выражения
====================

Что такое регулярные выражения?
-------------------------------

Математический аппарат конечных автоматов, теория формальных языков и грамматик
-------------------------------------------------------------------------------

Базовые понятия: перечисление, группировка, квантификация
---------------------------------------------------------

Наборы символов. Утверждения
----------------------------

Использование QRegExp
---------------------




.\00_HomeWork_Browser\README.md
﻿Мой собственный Браузер
=======================

Чтобы работал QWebView надо добавить модуль **webkitwidgets** в **.pro** файл.

Нужно
-----
* Реализовать сохранение сайта в *Избранное* (специальная панель)
* Переходы по сайтам из избранного (при нажатии на кнопку)

Создание кнопки и добавление на панель
--------------------------------------
``` cpp
// Создаём новую кнопку
QPushButton *button = new QPushButton(this);
  // parent = this чтобы кнопки удалились при закрытии окна
// Сохраняем текущий URL в текст кнопки
button->setText(ui->urlEdit->text());

// При нажатии на кнопку переходим на адрес
// Соединяем сигнал clicked() с нужным слотом
connect(button, SIGNAL(clicked()), this, SLOT(on_goToHistory_clicked()));

// Добавляем кнопку на панель
ui->historyTools->addWidget(button);
```

Как получить нажатую кнопку в обработчике (в слоте):
``` cpp
// Кто отправил сигнал?
QPushButton *button = (QPushButton *)QObject::sender();
if(button == NULL){
  qDebug() << "Должны быть только объекты QPushButton";
  return;
}

// Получаем URL с кнопки
QString url = button->text();
// Выводим URL для отладки
qDebug() << "URL:" << url;
// Переходим по заданному адресу
ui->webView->setUrl(url);
```


.\00_HomeWork_Browser\historybutton.cpp
При нажатии на кнопку переходим на адрес
.\00_HomeWork_Browser\historybutton.h
.\00_HomeWork_Browser\main.cpp
.\00_HomeWork_Browser\mainwindow.cpp
При нажатии на кнопку Go переходим на адрес
Добавление адреса сайта в закладки
Создаём новую кнопку
Добавляем на панель
Кто отправил сигнал?
Выводим URL для отладки
.\00_HomeWork_Browser\mainwindow.h
.\01_QtBrowser\main.cpp
.\01_QtBrowser\mainwindow.cpp
.\01_QtBrowser\mainwindow.h
.\01_QtBrowser\mockurlworker.cpp
.\01_QtBrowser\mockurlworker.h
Объявление объекта-заглушки
.\01_QtBrowser\urlcomplete.cpp
.\01_QtBrowser\urlcomplete.h
.\01_QtBrowser\urlworker.h
Интерфейс, который может обрабатывать URL
.\01_QtSQL\main.cpp
Пример консольной программы для демонстрации принципов работы с БД в Qt
-------------------------------------------------------------------------
SQLite - компактная встраиваемая реляционная база данных
Слово «встраиваемый» означает, что SQLite не использует парадигму клиент-сервер,
то есть движок SQLite не является отдельно работающим процессом,
с которым взаимодействует программа, а предоставляет библиотеку,
с которой программа компонуется и движок становится составной частью программы.
Таким образом, в качестве протокола обмена используются вызовы функций (API) библиотеки SQLite.
Такой подход уменьшает накладные расходы, время отклика и упрощает программу.
SQLite хранит всю базу данных (включая определения, таблицы, индексы и данные)
в единственном стандартном файле на том компьютере, на котором исполняется программа.
query - SQL-запрос в виде строки
QSqlQuery a_query(query);
SELECT * FROM phone WHERE people_id = 1
QString sqlTemplate("SELECT * FROM phone WHERE people_id = %1");
QSqlQuery query;
bool res = query.exec(sqlTemplate.arg(1));
Можно сделать отдельную функцию для добавления контакта,
которая принимает параметрами данные о контакте
Шаблон SQL-запроса INSERT   %1 %2 %3 - параметры шаблона
Проверка что таблица существует
tableName - имя таблицы
Шаблон запроса
%1 - первый аргумент
Если exec() вернул false => при выполнении запроса
произошла ошибка => надо об этом сообщить пользователю
и завершить программу.
"Мёртвые программы не лгут" (с) "Программист-прагматик"
Читаем таблицу результатов
Получаем запись
Одна строка из результатов запроса
Выбираем следующую строку
Для Qt до версии 5
Индекс (начиная с нуля) столбца с заданным именем
в строке результатов
QVariant nameQVariant = q.value("name");
QString name = nameQVariant.toString();
Начиная с Qt5
cout << ++count << ". " << name.toLocal8Bit().constData() << " " <<
birthday.toStdString() << " " << endl;
Работаем с БД SQLite
-- Подключение к Базе Данных --
Подключаем драйвер для работы с SQLite
Названия драйверов для Qt:
http://qt-project.org/doc/qt-5/sql-driver.html
Sqlite3
Имя файла с SQLite базой данных
База данных открыта и можно выполнять запросы
-- Создание схемы БД --
DDL query - создаём новую таблицу
Data Definition Language (DDL) - язык описания данных
Создаём таблицу контактов
Создаём таблицу телефонов
-- Добавление данных --
DML
Data Manipulation Language (DML) - язык управления (манипулирования) данными
-- Выполнение запроса и навигация по результирующей выборке --
Сложный запрос с JOIN'ами
setlocale(LC_ALL, "Russian");
.\02_QtSQL_GUI\main.cpp
.\02_QtSQL_GUI\mainwindow.cpp
Задаём на нашего компонента view
db.setDatabaseName(":memory:");
.\02_QtSQL_GUI\mainwindow.h
.\03_QThreads_QMutex\commondata.cpp
.\03_QThreads_QMutex\commondata.h
#define USE_MUTEX
.\03_QThreads_QMutex\decthread.cpp
msleep(20); // 20 миллисекунд
.\03_QThreads_QMutex\decthread.h
.\03_QThreads_QMutex\incthread.cpp
msleep(10); // 20 миллисекунд
.\03_QThreads_QMutex\incthread.h
.\03_QThreads_QMutex\main.cpp
QThread::currentThread()->sleep(1);
.\04_QtThreads\inputthread.cpp
Вводим целое число
sleep(5);
Выводим восклицательные знаки
cout << "!!!!";
QCoreApplication::exit();
.\04_QtThreads\inputthread.h
.\04_QtThreads\main.cpp
Отслеживаем события в потоке 1
Создаём поток для ввода данных
Мы можем присоединить сколько угодно
обработчиков к одному сигналу,
в частности к событию finished()
Можем вывести, запущен ли поток
.\04_QtThreads\mythread.cpp
Перед этим генерируется сигнал started()
Замедляем поток
Генерируется сигнал finished()
.\04_QtThreads\mythread.h
Имя потока
Количество итераций
.\04_QtThreads\observer.cpp
Получили сигнал что поток 1 завершился
.\04_QtThreads\observer.h
.\05_QtThreadGUI\main.cpp
.\05_QtThreadGUI\mainwindow.cpp
Передаём все необходимые данные
при старте
.\05_QtThreadGUI\mainwindow.h
.\05_QtThreadGUI\primecalcthread.cpp
Будем каждое число проверять на простоту
Проверяем n на простоту
Если простое, то выводим в интерфейс
.\05_QtThreadGUI\primecalcthread.h
.\06_QtBrowser\main.cpp
.\06_QtBrowser\mainwindow.cpp
.\06_QtBrowser\mainwindow.h
.\07_HTML_CSS\main.cpp
.\07_HTML_CSS\mainwindow.cpp
.\07_HTML_CSS\mainwindow.h
.\10_QtCreateSQLiteDBFromFile\main.cpp
Имя файла с SQLite базой данных
Читаем SQL оператор
Выполняем в базе данных
.\BuildCmdLine\a.cpp
.\HomeWork_SQL\main.cpp
Пример консольной программы для демонстрации принципов работы с БД в Qt
-------------------------------------------------------------------------
SQLite - компактная встраиваемая реляционная база данных
Слово «встраиваемый» означает, что SQLite не использует парадигму клиент-сервер,
то есть движок SQLite не является отдельно работающим процессом,
с которым взаимодействует программа, а предоставляет библиотеку,
с которой программа компонуется и движок становится составной частью программы.
Таким образом, в качестве протокола обмена используются вызовы функций (API) библиотеки SQLite.
Такой подход уменьшает накладные расходы, время отклика и упрощает программу.
SQLite хранит всю базу данных (включая определения, таблицы, индексы и данные)
в единственном стандартном файле на том компьютере, на котором исполняется программа.
query - SQL-запрос в виде строки
QSqlQuery a_query(query);
SELECT * FROM phone WHERE people_id = 1
QString sqlTemplate("SELECT * FROM phone WHERE people_id = %1");
QSqlQuery query;
bool res = query.exec(sqlTemplate.arg(1));
Можно сделать отдельную функцию для добавления контакта,
которая принимает параметрами данные о контакте
Шаблон SQL-запроса INSERT   %1 %2 %3 - параметры шаблона
Проверка что таблица существует
tableName - имя таблицы
Шаблон запроса
%1 - первый аргумент
Если exec() вернул false => при выполнении запроса
произошла ошибка => надо об этом сообщить пользователю
и завершить программу.
"Мёртвые программы не лгут" (с) "Программист-прагматик"
Читаем таблицу результатов
Выбираем следующую строку
Для Qt до версии 5
Индекс (начиная с нуля) столбца с заданным именем
в строке результатов
QVariant nameQVariant = q.value("name");
QString name = nameQVariant.toString();
cout << ++count << ". " << name.toLocal8Bit().constData() << " " <<
birthday.toStdString() << " " << endl;
Работаем с БД SQLite
-- Подключение к Базе Данных --
Подключаем драйвер для работы с SQLite
Названия драйверов для Qt:
http://qt-project.org/doc/qt-5/sql-driver.html
Sqlite3
Имя файла с SQLite базой данных
База данных открыта и можно выполнять запросы
-- Создание схемы БД --
DDL query - создаём новую таблицу
Data Definition Language (DDL) - язык описания данных
Создаём таблицу контактов
Создаём таблицу телефонов
-- Добавление данных --
DML
Data Manipulation Language (DML) - язык управления (манипулирования) данными
-- Выполнение запроса и навигация по результирующей выборке --
Сложный запрос с JOIN'ами
setlocale(LC_ALL, "Russian");
.\QDateTime\datetime.cpp
.\QDateTime\datetime.h
.\QDateTime\main.cpp
.\QDateTime\wnd.cpp
.\QDateTime\wnd.h
.\QtSQL_Student_Console\main.cpp
system("chcp 65001");
setlocale(LC_ALL, "Russian.UTF-8");
SetConsoleCP(65001);
SetConsoleOutputCP(65001);
QTextCodec* tc = QTextCodec::codecForName("IBM 866");
cout << QString(tc->fromUnicode("Юникод СТрока :)")).data() << endl;
MySQL   number_of_lessons
MSSQL   NumberOfLessons
ORACLE  NUMBER_OF_LESSONS
.\QtSQL_Students\main.cpp
.\QtSQL_Students\mainwindow.cpp
.\Qt_Assert\main.cpp
fact(0);
.\firefox_sqlite\README.md
﻿Установка расширения для Firefox
================================



![Install](install.png "Установка расширения")

![Setup](move_to_toolbar.png "Добавляем расширение в интерфейс")

![Main window](sqlite_main_window.png "Основное окно программы")

