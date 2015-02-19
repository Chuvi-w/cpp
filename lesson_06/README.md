.\000_intro.md
﻿Введение в Qt, Qt Creator, QtCore, QtGui, отладка
=================================================

Ссылки для скачивания
---------------------
* Qt Creator: http://qt-project.org/downloads
* http://www.qt.io/download-open-source/

При установке снимите галочку с **msvc 2013 ..** и поставьте на **MinGW 4.9.1**.

QT - история
------------

Первый выход в свет библиотеки Qt состоялся в мае 1995 года.
Первоначально она разрабатывалась Хаавардом Нордом (главный управляющий Trolltech) и Эриком Чамбенгом (президент компании Trolltech).
Хаавард и Эрик встретились в стенах Норвежского Технологического Института, в городе Тронхейме, где они получали высшее образование.

В 1991 году Хаавард написал первые несколько классов, из которых потом и появилась Qt.
Эрик занялся разработкой общего дизайна библиотеки.
На следующий год Эрику пришла в голову идея реализации "сигналов и слотов" - простой но очень мощной парадигмы программирования графического интерфейса.
Хаавард подхватил идею и воплотил ее в код.
К 1993 году они завершили разработку первого графического ядра и приступили к созданию визуальных компонентов (widgets).
В конце года Хаавард предложил Эрику открыть совместное дело и выпустить "лучшую в мире библиотеку реализации графического интерфейса на C++".

**Сигнал** генерируется когда происходит определенное событие.

**Слот** - функция (обработчик), которая вызывается в ответ на определенный сигнал.

В качестве префикса в именах классов был выбран символ "Q", поскольку Хааварду очень нравилось как он выглядел в Emacs.
Символ "t" был выбран потому, что с него начиналось слово "toolkit", по аналогии с "Xt" -- "X toolkit".
Компания была зарегистрирована 4 марта 1994 года под названием "Quasar Technologies", которое затем было преобразовано в "Troll Tech", а затем и в "Trolltech".

В апреле 1997 года вышла Qt 1.2.

В 2001 году вышла Qt 3.

Летом 2005 года была выпущена Qt 4.0.
Имея около 500 классов и более 9000 функций, Qt 4 оказалась больше и богаче любой предыдущей версии;
она была разбита на несколько библиотек, чтобы разработчики могли использовать только нужные им части Qt.
Версия Qt 4 представляет собой большой шаг вперёд по сравнению с предыдущими версиями;
она содержит полностью новый набор эффективных и простых в применении классов-контейнеров, усовершенствованную функциональность архитекторы модель/представление,
быстрый и гибкий фреймфорк графики 2D и мощные классы для просмотра и редактирования текста в кодировке Unicode,
не говоря уже о тысячах небольших улучшений по всему спектру классов Qt.
Qt 4 является первой версией Qt, доступной на всех поддерживаемых платформах как для коммерческой разработки, так и для разработки с открытым исходным кодом.

2012 год - выход Qt 5.0.
Главные изменения в Qt5 связаны с модульностью Qt и активным переходом на декларативное описание интерфейса (Qt Quick).
Это не значит, что Qt перепишут на JavaScript,
просто C++ будет использоваться для написания критичных ко времени выполнения или сложных вещей.
Сохраняется и базовая обратная совместимость: в Qt 5 вошли почти все компоненты Qt 4, кроме устаревших,
большинство модулей из Qt Mobility (теперь это уже не отдельный продукт) и некоторые экспериментальные разработки.

Установка и запуск Qt Creator. Qt Designer
------------------------------------------

Создание простейшего приложения. Сигналы и слоты. Обработка событий
-------------------------------------------------------------------

Проектирование пользовательского интерфейса с учётом требований эргономичности (компоненты, события, сигналы, слоты в Qt)
-------------------------------------------------------------------------------------------------------------------------


.\00_FirstQtApp\0_intro.md
﻿Первое приложение Qt
====================
* Запускаем Qt Creator
* Создаём главную форму
* Добавляем виджеты
* Используем сигналы и слоты

.\00_FirstQtApp\README.md
﻿Первое приложение Qt
====================
* Запускаем Qt Creator
* Создаём главную форму
* Добавляем виджеты
* Используем сигналы и слоты

Основная программа на Qt
------------------------
``` cpp
#include "mainwindow.h"
#include <QApplication>
#include <QDebug> // Отладочный вывод в консоль
#include <iostream>

using namespace std;

// argc - количество аргументов
// argv - параметры командной строки
int main(int argc, char* argv[]) {
  // Печатаем количество аргументов
  cout << "argc: " << argc << endl;

  // И сами аргументы
  for(int i = 0; i < argc; ++i)
    cout << argv[i] << endl;

  // Обработка сигналов
  // Связь сигнал -> слот
  QApplication a(argc, argv);

  // Создаём основное окно
  MainWindow w;
  // Показываем основное окно
  w.show();

  cout << "Starting..." << endl;

  // Запуск основного цикла обработки событий
  int res = a.exec();

  cout << "Closing... res = " << res << endl;
  return res;
}
```

[main.cpp]

Слот (обработчик сигнала) - реализуется как обычный метод
``` cpp
void MainWindow::on_closeButton_clicked() {
  qDebug() << "on_closeButton_clicked()";
}

void MainWindow::on_concatButton_clicked() {
  // ui - Ui::MainWindow *ui;
  // Указатель на сгенерированный
  // по *.ui файлу класс Ui::MainWindow
  QLineEdit* line1 = ui->lineEdit_1;
  // line1 - указатель на виджет
  // Чтобы получить текст мы вызываем
  // метод text()
  // который возвращает QString
  QString s1 = line1->text();
  qDebug() << s1;
  qDebug() << ui->lineEdit_2->text();

  // Свойство называется так:
  //    имяСвойства
  // Чтобы получить значение вызываем метод:
  //    имяСвойства()
  // Чтобы поменять значение вызываем метод:
  //   setИмяСвойства(Новое_значение)
  ui->resEdit->setText(s1 +
                       ui->lineEdit_2->text());
}
```

[mainwindow.cpp]

``` cpp
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  // parent - объект при уничтожении которого
  //  должен быть уничтожен и этот объект
  // Обычно основное (главное) окно программы
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  // Слоты - методы-обработчики сигналов
  void on_pushButton_clicked();

  void on_closeButton_clicked();

  void on_concatButton_clicked();

  void on_enableButton_clicked();

 private:
  Ui::MainWindow* ui;
};
```

[mainwindow.h]


.\00_FirstQtApp\dialog.cpp
.\00_FirstQtApp\dialog.h
.\00_FirstQtApp\main.cpp
Основная программа на Qt
------------------------
``` cpp
#include "mainwindow.h"
#include <QApplication>
#include <QDebug> // Отладочный вывод в консоль
#include <iostream>

using namespace std;

// argc - количество аргументов
// argv - параметры командной строки
int main(int argc, char* argv[]) {
  // Печатаем количество аргументов
  cout << "argc: " << argc << endl;

  // И сами аргументы
  for(int i = 0; i < argc; ++i)
    cout << argv[i] << endl;

  // Обработка сигналов
  // Связь сигнал -> слот
  QApplication a(argc, argv);

  // Создаём основное окно
  MainWindow w;
  // Показываем основное окно
  w.show();

  cout << "Starting..." << endl;

  // Запуск основного цикла обработки событий
  int res = a.exec();

  cout << "Closing... res = " << res << endl;
  return res;
}
```

.\00_FirstQtApp\mainwindow.cpp
/ Слот (обработчик сигнала) - реализуется как обычный метод
``` cpp
void MainWindow::on_closeButton_clicked() {
  qDebug() << "on_closeButton_clicked()";
}

void MainWindow::on_concatButton_clicked() {
  // ui - Ui::MainWindow *ui;
  // Указатель на сгенерированный
  // по *.ui файлу класс Ui::MainWindow
  QLineEdit* line1 = ui->lineEdit_1;
  // line1 - указатель на виджет
  // Чтобы получить текст мы вызываем
  // метод text()
  // который возвращает QString
  QString s1 = line1->text();
  qDebug() << s1;
  qDebug() << ui->lineEdit_2->text();

  // Свойство называется так:
  //    имяСвойства
  // Чтобы получить значение вызываем метод:
  //    имяСвойства()
  // Чтобы поменять значение вызываем метод:
  //   setИмяСвойства(Новое_значение)
  ui->resEdit->setText(s1 +
                       ui->lineEdit_2->text());
}
```

.\00_FirstQtApp\mainwindow.h
``` cpp
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  // parent - объект при уничтожении которого
  //  должен быть уничтожен и этот объект
  // Обычно основное (главное) окно программы
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  // Слоты - методы-обработчики сигналов
  void on_pushButton_clicked();

  void on_closeButton_clicked();

  void on_concatButton_clicked();

  void on_enableButton_clicked();

 private:
  Ui::MainWindow* ui;
};
```

.\00_FirstQtApp\release\a.cpp
.\00_FirstQtApp\ui_dialog.h
.\00_FirstQtApp\ui_mainwindow.h
.\00_HomeWork_Done\main.cpp
/ НОД - Наибольший общий делитель
/ GCD - Greatest Common Divisor
/ Алгоритм Евклида с делением
``` cpp
ll GCD(ll a, ll b) {
  return (b == 0) ? a : GCD(b, a % b);
}
```

Рациональная дробь: p/q
``` cpp
class Rational {
  ll p, q; // p - числитель, q - знаменатель
  // Сокращение дроби
  //  4/6 -> НОД(4,6)=2 -> 2/3
  void normalize() {
    ll d = GCD(p, q); // Вычисляем наибольший общий делитель
    p /= d; // делим на него числитель
    q /= d; // делим на него знаменатель

    if(q < 0) {
      p = -p;
      q = -q;
    }
  }
 public:
  // Конструктор
  Rational(ll pi, ll qi) : p(pi), q(qi) {
    assert(q != 0);
    normalize();
  };
  // Ввод с клавиатуры
  Rational(const char* message) {
    cout << message << " ";
    cout << "p = ";
    cin >> p;
    cout << "q = ";
    cin >> q;
    normalize();
  }
  // Показать дробь на экран (в консоль)
  void show(ostream& os = cout) const {
    // normalize(); // Нельзя, т.к. он меняет объект
    // Сокращаем дробь если надо
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    long px = p / d; // делим на него числитель
    long qx = q / d; // делим на него знаменатель

    // Заменяем дроби вида -1/-2 на 1/2
    if(qx < 0) {
      px = -px;
      qx = -qx;
    }

    // Если знаменатель равен 1
    // то это целое число
    if(qx == 1)    // Условие (1)
      os << px;
    else { // Иначе есть дробная часть
      // Вычисляем целую часть
      long whole = px / qx;

      if(whole != 0)
        os << whole << " ";
      else if(px < 0)
        os << "-";

      px -= whole * qx;
      px = abs(px);
      assert(px > 0);
      // Если число целое, то должно было сработать
      // первое условие (1)
      assert(px % qx != 0);
      os << px << "/" << qx;
    }
  }
  // Сложение дробей
  // a + b
  Rational operator+(Rational& r) {
    // this - указатель на текущий объект
    // *this - текущий объект
    return Rational(p * r.q + r.p * q,
                    q * r.q  );
  }

  // прибавить к дроби целое число
  Rational operator+(int right) {
    return Rational(p + right * q,
                    q);
  }

  // прибавить к целому число дробь
  friend Rational
  operator+(long left, Rational& r) {
    return Rational(left * r.q + r.p,
                    r.q);
  }

  // вычитание
  Rational operator-(Rational& r) {
    return Rational(p * r.q - r.p * q,
                    q * r.q  );
  }

  // Конструктор копирования
  Rational(const Rational& r) {
    p = r.p;
    q = r.q;
  }

  // cout - типа ostream
  friend ostream& operator << (ostream& os,
                               Rational r) {
    r.show(os);
    return os;
  }

  // stream - поток
  // thread - поток/нить
};

int main() {
  //SetConsoleOutputCP(65001);
  //setlocale(LC_ALL, "Russian.UTF-8");

  const Rational r(-1, -2);
  SHOW(r);

  const Rational r2(-3, 2);
  SHOW(r2);

  Rational a(4, 6), b(11, 2);
  SHOW(a);
  SHOW(b);

  cout << a << " + " << b << " = " << (a + b) << endl;

  // Rational c = b + a;
  int i = 2, j = 3;
  int tt = i + j;
  Rational c1 = i + b;

  SHOW(b);
  SHOW(c1);

  Rational yy("Enter:");
  SHOW(yy);

  return 0;
}
.\01_OOP\01_copy_contructor\main.cpp
Конструктор копирования
-----------------------
Создаем собственный класс "Строчка"
``` cpp
struct String {
  char* str;
  int x; // Дополнительное поле
  // Конструктор
  String(char* initStr) {
    str = new char[strlen(initStr) + 1];
    strcpy(str, initStr);
  }
  // Конструктор копирования
  String(String& s) : String(s.str)  {
    cout << "Copy constructor" << endl;
    x = s.x;
  }
  // Деструктор
  ~String() {
    delete[] str;
  }
};
```

Если написать так, то получим ошибку выполнения,
т.к. пытаемся переписать константу
```cpp
const char *str = "Hello";
str[0] = 'X';
```
.\01_OOP\02_virtual_destructor\task1.cpp
Виртуальный деструктор
----------------------
Базовый класс
``` cpp
class Test {
 public:
  static int alive;
  virtual void init() {
    printf("Test::init()\n");
  }
  Test() { // Конструктор
    printf("Test::Test()\n");
    alive++;
  }
  virtual ~Test() { // Деструктор
    printf("Test::~Test()\n");
    alive--;
  }
};

int Test::alive = 0;
```

Наследник:
``` cpp
class Test2 : public Test {
 public:
  static int alive2;
  virtual void init() {
    printf("  Test2::init()\n");
  }
  Test2() { // Неявный вызов конструктора Test
    printf("  Test2::Test2()\n");
    alive2++;
  }
  ~Test2() {
    printf("  Test2::~Test2()\n");
    alive2--;
  }
};

int Test2::alive2 = 0;
```

При выполнении new:
1. отводится область динамической памяти
2. вызывается конструктор объекта
``` cpp
    Test2 tt;
    tt.init();
```

.\01_OOP\03_iostream_files\a_sum.cpp
Файловый ввод и вывод с помощью потоков
---------------------------------------
.\01_OOP\03_iostream_files\main.cpp
cin - istream;
cout - ostream;
ifstream - input file stream

Открываем текстовый файл для ввода
``` cpp
  ifstream in("data.txt");
  string s;
  double x, y;
  in >> s >> x >> y;
  cout << s << " " << x << " " << y <<
       "   x + y = " << (x + y) << endl;
  in.close();
```

Перенаправляем вывод в файл **log.txt**:
``` cpp
  freopen("log.txt", "a", stdout);

  cout << "Квадраты чисел:" << endl;

  for(int i = 0; i < 10; ++i)
    cout << i << "^2 = " << i* i << endl;

```

Выходной файл автоматически
закрывается при закрытии программы
.\01_OOP\03_iostream_files\redirect_output.cpp
Перенаправление консольного ввода/вывода
----------------------------------------
Подключаем cstdio для **freopen**
``` cpp
#include <cstdio>
```

Ввод из файла вместо консоли:
``` cpp
  freopen("sum.in", "r", stdin); // stdin - поток ввода с консоли
```

Вывод в файл вместо консоли:
``` cpp
  freopen("sum.out", "w", stdout);
```

Дальше работаем с файлами как с консолью
``` cpp
  long long a, b;
  cin >> a >> b;
  cout << a << " + " << b << " = " << (a + b) << endl;
```

.\01_OOP\README.md
.\01_copy_contructor\main.cpp
Конструктор копирования
-----------------------
Создаем собственный класс "Строчка"
``` cpp
struct String {
  char* str;
  int x; // Дополнительное поле
  // Конструктор
  String(char* initStr) {
    str = new char[strlen(initStr) + 1];
    strcpy(str, initStr);
  }
  // Конструктор копирования
  String(String& s) : String(s.str)  {
    cout << "Copy constructor" << endl;
    x = s.x;
  }
  // Деструктор
  ~String() {
    delete[] str;
  }
};
```

Если написать так, то получим ошибку выполнения,
т.к. пытаемся переписать константу
```cpp
const char *str = "Hello";
str[0] = 'X';
```
.\02_virtual_destructor\task1.cpp
Виртуальный деструктор
----------------------
Базовый класс
``` cpp
class Test {
 public:
  static int alive;
  virtual void init() {
    printf("Test::init()\n");
  }
  Test() { // Конструктор
    printf("Test::Test()\n");
    alive++;
  }
  virtual ~Test() { // Деструктор
    printf("Test::~Test()\n");
    alive--;
  }
};

int Test::alive = 0;
```

Наследник:
``` cpp
class Test2 : public Test {
 public:
  static int alive2;
  virtual void init() {
    printf("  Test2::init()\n");
  }
  Test2() { // Неявный вызов конструктора Test
    printf("  Test2::Test2()\n");
    alive2++;
  }
  ~Test2() {
    printf("  Test2::~Test2()\n");
    alive2--;
  }
};

int Test2::alive2 = 0;
```

При выполнении new:
1. отводится область динамической памяти
2. вызывается конструктор объекта
``` cpp
    Test2 tt;
    tt.init();
```

.\03_iostream_files\main.cpp
cin - istream;
cout - ostream;
ifstream - input file stream

Открываем текстовый файл для ввода
``` cpp
  ifstream in("data.txt");
  string s;
  double x, y;
  in >> s >> x >> y;
  cout << s << " " << x << " " << y <<
       "   x + y = " << (x + y) << endl;
  in.close();
```

Перенаправляем вывод в файл **log.txt**:
``` cpp
  freopen("log.txt", "a", stdout);

  cout << "Квадраты чисел:" << endl;

  for(int i = 0; i < 10; ++i)
    cout << i << "^2 = " << i* i << endl;
```

Выходной файл автоматически
закрывается при закрытии программы
.\03_iostream_files\redirect_output.cpp
Перенаправление консольного ввода/вывода
----------------------------------------
Подключаем cstdio для **freopen**
``` cpp
#include <cstdio>
```

Ввод из файла вместо консоли:
``` cpp
  freopen("sum.in", "r", stdin); // stdin - поток ввода с консоли
```

Вывод в файл вместо консоли:
``` cpp
  freopen("sum.out", "w", stdout);
```

Дальше работаем с файлами как с консолью
``` cpp
  long long a, b;
  cin >> a >> b;
  cout << a << " + " << b << " = " << (a + b) << endl;
```

.\03_iostream_files\sum.cpp

.\02_templates\31_template_min_max\01_template_min_max\main.cpp
Базовое применение шаблонов
Без использования шаблонов
T - параметр шаблона
Шаблонная функция
Предусловия
Параметры шаблонов:
типы: class G / typename T
любой из типов: int I
Функция, добавляющая константу
assert(2*2 == 5);
.\02_templates\32_template_duck_typing\main.cpp
Утиная типизация - Duck Typing
------------------------------
t.VilyaletHvostom(); // Виляет хвостом
.\02_templates\33_print_commas\main.cpp
a - массив
N - количество элементов
T - параметр шаблона
произвольный тип, с которым можно выполнять
операции (т.е. он подходит по duck typing)
Вывести через запятую
2, 3, 4
.\02_templates\33_template_stack_queue\main.cpp
template <class T>
template <typename T>
Элемент стека и очереди
Стек
Конструктор
Значение поместить на вершину стека
Записываем значение,
которое надо поместить
на вершину стека
Новый элемент на вершине стека
поэтому все остальные следуют за ним
Ставим новый элемент в начало списка
Взять значение с вершины стека
Запоминаем результат
- значение элемента-"вершины" стека
1-A
Запоминаем ссылку на удаляемый
элемент
1-B
2. Перемещаем вершину на следующий
3. Реально удаляем элемент
4. Возвращаем результат
Конструктор
В конец очереди
Создаём новый элемент
Если очередь пуста
Если в очереди уже есть элементы
"Присоединяем" элемент к последнему
элементу в очереди
Забрать первый элемент из очереди
Запоминаем первый элемент
Значение, которое мы в конце вернём
Передвигаем указатель на начало
очереди на следующий элемент
Если очередь пуста, то
хвост очереди не указывает ни на
какой элемент
Удаляем первый элемент из
динамической памяти
Возвращаем его значение
.\02_templates\34_template_int\main.cpp
.\02_templates\35_template_sum\main.cpp
Задача:
Функция, вычисляющая сумму элементов
массива с произвольным типом данных.
Понятно, что функция применима только если
элементы массива поддерживают операцию
сложения "+"
size_t - целый тип, используемый для индексации массивов
Универсальная функция суммирования
Отдельная функция для суммирования строк
Комплексное число
re - действительная часть
im - мнимая часть
Строки тоже можно "суммировать"
Это называется "Конкатенация строк"
.\02_templates\36_template_sort\main.cpp
Демонстрация "зачем нужны шаблоны"
Задача: мы хотим написать функции сортировки для всех типов данных
Если не использовать шаблоны,
то для 2 типов (int, сhar) требуется две реализации
функции сортировки
Используем простейший алгоритм сортировки
На i-ом шаге сделаем, чтобы на i-ом месте
был минимальный элемент на отрезке массива от i до конца массива
i - начало интервала, пусть j пробегает все элементы после i
на i-ом месте
Меняем два элемента
чтобы на i-ом месте стоял минимальный
элемент
Вторая реализация точно такая же, но int заменяем на char
Меняем два элемента
чтобы на i-ом месте стоял минимальный
элемент
Универсальная сортировка (для любых типов)
template <class T>
Меняем два элемента
чтобы на i-ом месте стоял минимальный
элемент
Массив целых чисел
s<int>(a,3)
Массив букв
Можно применить и к действительным числам
..и к строкам...
...и к любым другим типам данных (в том числе своим)..
..к которым применима операция "меньше"..
.\02_templates\38_template_many_functions\main.cpp
В цикле мы не можем создавать реализации шаблона
т.к. они создаются на этапе компиляции
error: no matching function for call to 'add(int&)'|
.\02_templates\l5_template2\main.cpp
MyClass c1, c2;
add<MyClass>(c1,c2);
.\02_templates\l5_template\main.cpp
template: реализация структуры данных "Список"
----------------------------------------------
Шаблонная функция
Элемент списка
Конструктор
Так нельзя (!!!):
root->next = NULL;
Деструктор - метод, который вызывается при
уничтожении объекта
Добавить в начало списка
Заводим новый элемент списка в динамической памяти
Записываем в него новое значение
(*newElement).value = newValue;
Этот элемент должен встать в начало списка,
т.е. все остальные элементы будут после него.
Показать список
Текущий элемент - сначала 1-ый
Добавить элемент в конец списка
Идём до последнего элемента
for(ListElement* cur = root;
cur->next != NULL; cur = cur->next)
/* Ничего не надо делать :) */;
Создаём новый элемент
Новый элемент ставим в конец списка
myFunction<double>()
make_pair(234, 'c');
List - класс
list - объект этого класса
.\02_templates\main.cpp
Базовое применение шаблонов
---------------------------
Функция в C до шаблонов
Шаблоны есть только в C++
Без использования шаблонов
Шаблонная функция
T - параметр шаблона (произвольный тип данных)
Шаблонная функция
Предусловия
Параметры шаблонов:
типы: class G / typename T
любой из типов: int I
Функция, добавляющая константу
Перегрузка операции '<' для точки
assert(2*2 == 5);
Шаблоны умеют автоматически определять
тип по типам аргументов
Явно указать параметр шаблона
.\02_templates\task_mul\main.cpp
Произведение всех чисел
в массиве A
``` cpp
template <typename T>
T mul(T A[], size_t size) {
  if(typeid(T) == typeid(int))
    cout << "int" << endl;

  if(typeid(T) == typeid(double))
    cout << "double" << endl;

  //cout << typeid(T).name() << endl;
  // TODO: реализовать
  T res = 1; // Произведение 1

  for(size_t i = 0; i < size; ++i)
    res *= A[i]; // Умножаем на все последующие

  return res;
}
```

.\03_STL\1_vector.cpp
Вектор - аналог массива
Массив строк
Вектор строк
Удаляем элемент из середины вектора
Второй пример
.\03_STL\2_set.cpp
.\03_STL\2_set_test.cpp
.\03_STL\6_map_count_chars.cpp
/ Итератор по буквам строки
/ -------------------------
map - ассоциативный массив
ключ - как индекс в массиве
size_t -
Итератор в строке пробегает по буквам
с первой буквы до последней по одной
Очередная буква строки
Не нашли букву => она первый раз
.\03_STL\7_map_dict.cpp
``` cpp
void dict() {
  // Контейнеры:
  //   vector
  //   set
  //   map
  setlocale(LC_ALL, "Russian");

  // Ассоциативный массив
  // A["Hi"] = "Привет";
  // map<key, value>
  map<string, string> dict;

  // dict[3] = 4;
  // dict[3] = 5;

  dict["Привет"] = "Hi";
  dict["Я"] = "I";

  dict["Ты"] = "You";
  cout << dict["Ты"] << endl;

  dict["Ты2"] = "You2";
  cout << dict["Ты"] << endl;

  map<MyClass, string> mm;
  MyClass m;
  mm[m] = "Test";
}
```

.\03_STL\8_sort_strings.cpp
Задача
Ввести из файла in.txt количество строк N
Ввести из файла N строк
Отсортировать их и вывести в файл
out.txt
Вектор для хранения строк
Открываем входной файл
Считываем сами строки
in.eof() in.good() - до конца файла
Сортируем
Открываем файл для вывода
Выводим строки
Закрываем файл
.\03_STL\9_sort_my_comparator.cpp
sort algorithm example
using default comparison (operator <):
myvector.size()
using function as comp
Сортировка в обратном порядке
using object as comp
print out content:
.\03_STL\common.h
``` cpp
#define SHOW(x) cout << #x << " = " << x << endl;
#define X(a,b) ((a == b) ? (void)0 : _assert(#a" != "#b, __FILE__, __LINE__))
```

``` cpp
template <class T>
void showCollection(T v) {
  for(size_t i = 0; i < v.size(); ++i)
    cout << v[i] << " ";

  cout << endl;
}
```

.\03_STL\main.cpp
.\04_Qt_templates\02_map_example\main.cpp
map<ключ, значение>
m[ключ] = значение;
...
.\04_Qt_templates\02_map_example\юю\main.cpp
.\04_Qt_templates\02_map_example\юю\mainwindow.cpp
.\04_Qt_templates\02_map_example\юю\mainwindow.h
.\04_Qt_templates\02_map_example_1\main.cpp
.\04_Qt_templates\02_map_example_1\mainwindow.cpp
.\04_Qt_templates\02_map_example_1\mainwindow.h
.\04_Qt_templates\02_map_example_2\main.cpp
.\04_Qt_templates\qt_map_example\main.cpp
Конец слова
Выделяем слово
Переводим слово
.\05_Exceptions\main.cpp
throw 2;
qDebug() << "Error: " << s;
.\05_Qt\01_QtGUI_Properties\README.md
﻿Изменение свойств объектов по событиям
======================================


.\05_Qt\01_QtGUI_Properties\main.cpp
.\05_Qt\01_QtGUI_Properties\mainwindow.cpp
Получаем у кнопки её шрифт
ui->pushButton->setText("Привет");
.\05_Qt\01_QtGUI_Properties\mainwindow.h
.\05_Qt\02_Qt_console_debug\README.md
Отладка Qt приложений
=====================

.\05_Qt\02_Qt_console_debug\main.cpp
потому что в строке символ 0 - окончание строки
Создает копии динамических переменных и ресурсов
.\05_Qt\03_QtGUI\main.cpp
.\05_Qt\03_QtGUI\mainwindow.cpp
.\05_Qt\03_QtGUI\mainwindow.h
.\05_Qt\04_QtCalc\CalcStates.h
продолжаем вводить число
бинарную операцию
.\05_Qt\04_QtCalc\main.cpp
.\05_Qt\04_QtCalc\mainwindow.cpp
Очищаем дисплей
UTF-8
(QPushButton *)QObject::sender() -
отправитель текущего сигнала
Удаляем из s все лидирующие нули
Дописываем цифру на экран
Изменяем состояние всех кнопок
Можно нажимать ".",
только если на дисплее точек ещё нет
Складываем содержимое экрана и память
Запоминаем содержимое экрана
.\05_Qt\04_QtCalc\mainwindow.h
Когда нажимаем на цифровую кнопку
вызывается этот слот
.\05_Qt\04_QtCalc\ui_mainwindow.h
.\05_Qt\10_Qt_XO\cellbutton.cpp
Параметры:
text - текст на кнопке
parent - окно, в котором кнопка будет расположена
для корретного удаления кнопки
row - строка, col - столбец на поле
game - ссылка на игру
this->game = &game;
Если на кнопке написан крестик или нолик,
то нажимать на неё нельзя
При нажатии на клетку
Выводим координаты нажатия для отладки
Делаем ход => получаем результат
для данной клетки
Больше не можем нажимать на эту клетку поля
(эту кнопку)
.\05_Qt\10_Qt_XO\cellbutton.h
Одна клетка поля, наследник стандартной Qt-кнопки
Параметры:
text - текст на кнопке
parent - окно, в котором кнопка будет расположена
для корретного удаления кнопки
row - строка, col - столбец на поле
game - ссылка на игру
Нажатие на кнопку
.\05_Qt\10_Qt_XO\game.cpp
При старте программы сразу начинается новая игра
Новая игра
Первыми ходят всегда крестики
Заполняем поле пустыми клетками, без крестиков и ноликов
Совершаем ход

QMessageBox::information(NULL, "Ход",
QString("Ход в клетку: (%1; %2)")
.arg(row+1).arg(col+1));
Три крестика или три нолика
Если не все элементы равны => не подходит
Кто-то выйграл :)
== Проверяем диагонали ==
Основная диагональ
Дополнительная диагональ
(0,0) (0,1) [0,2]
(1,0) [1,1] (1,2)
[2,0] (2,1) (2,2)
Вертикальные и горизонтальные линии
Вертикальная линия
копируем в a i-ый столбец
Горизонтальная линия
Проверяем что крестики или нолики выйграли
и выходим
Ничья = не осталось пустых клеток
Сохранение игры
Сохраняем данные
Загрузка (чтение) сохранённой игры из файла
Читаем данные
Считываем размер карты
Проверяем количество крестиков и ноликов
.\05_Qt\10_Qt_XO\game.h
Состояние игры
Все что происодит на поле и логика игрового мира
Ходы, выйгрыш/проигрыш
Игровое поле
Проверка выйгрыша
проверяется одна строка
один столбец или одна диагональ
Конструктор
Новая игра без пересоздания объекта
Получаем строку, соответствующую состоянию игры
Совершаем ход, возвращает строку для клетки на форме
Проверяем на окончание игры
Сохранение игры
Загрузка игры
Состояние ячейки
.\05_Qt\10_Qt_XO\gamesettings.cpp
Записываем текущий размер поля
Берём новое значение размера поля
из интерфейса и записываем как MapSize
.\05_Qt\10_Qt_XO\gamesettings.h
.\05_Qt\10_Qt_XO\main.cpp
Мы можем создать второе такое же окно
MainWindow w2;
w2.show();
Обработка событий - основной цикл работы программы
.\05_Qt\10_Qt_XO\mainwindow.cpp
Скрываем кнопку с прототипом
Задаём размер массиву кнопок
Заполним весь массив кнопок поля NULL
Начало игры
Выход из программы
ui->lineEdit_1->setText(QString("1"));
ui->lineEdit_2->setText(QString("2"));
После изменения состояния игры
Подстраиваем размер, т.к. эта метка не в Layout
Создаём массив MapSize на MapSize из QPushButton
Шрифт как в прототипе
Задаём размеры и положение кнопки
critical(QWidget * parent, const QString & title,
const QString & text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton)
Вызываем окно настройки размера поля
После изменения размера поля
перестартуем игру
.\05_Qt\10_Qt_XO\mainwindow.h
Новый слот
.\05_Qt\10_Qt_XO\map_size.h
Размер поля игры
const int MapSize = 3;
.\05_Qt\Airports_qt\main.cpp
freopen("log.txt", "w", stdout);
return -1;
.\05_Qt\QTableViewDemo\main.cpp
.\05_Qt\QTableViewDemo\mainwindow.cpp
Модель данных (массив 9 на 9 элементов)
В таблице в интерфейсе будет показываться именно
эта модель
Добавляем таблицу чисел
.\05_Qt\QTableViewDemo\mainwindow.h
Модель: контейнер (массив) для ячеек таблицы
.\05_Qt\QtCalc\README.md
Добавить "-" и "*"

.\05_Qt\QtCalc\main.cpp
.\05_Qt\QtCalc\mainwindow.cpp
Пока нет операции
Сейчас будем вводить новое число
Это состояние в самом начале работы,
а также после каждой операции
xbutton_clicked - слот, который может принимать
сигналы от разных кнопок: '1','2'...'9','0'
Если сейчас вводим новое число
то все "старые" цифры с дисплея убираем
Узнаём, от какой кнопки пришёл сигнал
Добавляем новую цифру на дисплей
Узнаём, от какой кнопки пришёл сигнал
1. Получаем текст с кнопки
2. Переводим из QString (UTF-8) в обычную C-строку
3. Берём только первый символ
Выводим полученную с кнопки операцию в консоль
Получаем второй аргумент
Вычисляем результат
операция не реализована
Показываем целое число в интерфейсе
Добавляем точку
try{
} catch(){
qDebug() << s << " - incorrect double";
}
.\05_Qt\QtCalc\mainwindow.h
Последняя операция
Запоминаем число набранное на калькуляторе
Сейчас будем вводить новое число
.\05_Qt\QtConsoleExample\main.cpp
Поиск минимума в двухмерном массиве
Инициализируем максимальным числом для типа int
.\05_Qt\QtConsole\main.cpp
Консольное приложение на Qt для
вычисления факториала
.\05_Qt\QtContainers\main.cpp
.\05_Qt\QtContainers\mainwindow.cpp
.\05_Qt\QtContainers\mainwindow.h
.\05_Qt\QtDLLExample\qtdllexample.cpp
.\05_Qt\QtDLLExample\qtdllexample.h
.\05_Qt\QtDLLExample\qtdllexample_global.h
.\05_Qt\QtDemo\main.cpp
.\05_Qt\QtDemo\mainwindow.cpp
Получаем 2 строки из интерфейса
Конкатенация строк
Передаём результат в интерфейс
Генерация случайной строки
Любая буква английского алфавита
Генерируем первую строку
Генерируем вторую строку
.\05_Qt\QtDemo\mainwindow.h
Генерация случайной строки
.\05_Qt\QtFirstApplication\main.cpp
.\05_Qt\QtFirstApplication\mainwindow.cpp
Получаем строчку из первого (верхнего) поля
Получаем строчку из второго поля
Складываем числа
Результат в строчку
..используем строку форматирования..
Помещаем результат обратно в интерфейс
.\05_Qt\QtFirstApplication\mainwindow.h
.\05_Qt\QtGame\main.cpp
.\05_Qt\QtGame\mainwindow.cpp
Получаем текущее расположение кнопки
Изменяем координаты кнопки
Передаём изменённые координаты обратно в интерфейс
Получаем текущее расположение кнопки
Изменяем координаты кнопки
Передаём изменённые координаты обратно в интерфейс
Получаем текущее расположение кнопки
Изменяем координаты кнопки
Передаём изменённые координаты обратно в интерфейс
Получаем текущее расположение кнопки
Изменяем координаты кнопки
Передаём изменённые координаты обратно в интерфейс
.\05_Qt\QtGame\mainwindow.h
.\05_Qt\QtInterface\main.cpp
.\05_Qt\QtInterface\mainwindow.cpp
.\05_Qt\QtInterface\mainwindow.h
.\05_Qt\QtNewDemo\demowindow.cpp
.\05_Qt\QtNewDemo\demowindow.h
.\05_Qt\QtNewDemo\main.cpp
Создаём Qt-приложение
Создаём основное окно
Показываем его
Обработка событий приложения
.\05_Qt\QtNewDemo\mainwindow.cpp
Получаем 2 строки из интерфейса
Соединяем строки
Результат в интерфейс
.\05_Qt\QtNewDemo\mainwindow.h
Главное окно программы
Текущее окно приложения
.\05_Qt\QtNewDemo\secondwindow.cpp
.\05_Qt\QtNewDemo\secondwindow.h
.\05_Qt\QtSlotsSignals\README.md
Сигналы и слоты
===============


.\05_Qt\QtSlotsSignals\main.cpp
.\05_Qt\QtSlotsSignals\mainwindow.cpp
Связываем слот и сигнал из кода
.\05_Qt\QtSlotsSignals\mainwindow.h
.\05_Qt\QtWidgets2\main.cpp
.\05_Qt\QtWidgets2\mainwindow.cpp
Получаем строку из интерфейса

QListWidgetItem *newItem = new QListWidgetItem(ui->listWidget);
newItem->setText(str);
.\05_Qt\QtWidgets2\mainwindow.h
.\05_Qt\WidgetsDemo\main.cpp
.\05_Qt\WidgetsDemo\mainwindow.cpp
.\05_Qt\WidgetsDemo\mainwindow.h
.\05_Qt\qt_GUI\main.cpp
.\05_Qt\qt_GUI\mainwindow.cpp
.\05_Qt\qt_GUI\mainwindow.h
.\05_Qt\qt_console\a.cpp
template<ПАРАМЕТРЫ>
class Имя_класса{}
Тип_возвращаемого_значения Функция(параметры)
ПАРАМЕТРЫ:
int aa, char A, class T / typename T
template<template<int> class X>
X
Стек на основе массива
По-умолчанию private
Stack() { count = 0; }
Поместить на вершину стека
Получить значение с вершины стека
vector<тип> имя_переменной(количество, начальное_значение)
Добавляем в конец вектора
Тип_вектора::iterator
Множество
Добавляем элементы
if(intSet.find(1))
cout << "1 exists" << endl;
Удаляем элемент
map - словарь
map<тип_ключа, тип_значения>
m.insert('D', 30);
.\05_Qt\qt_console\main.cpp
Подсчитать количество одинаковых элементов
Вывести в виде Значение элемента -> Количество
Пробежим по всем значениям в векторе
Если такого значения ещё нет, добавим в m значение 1
Если есть, то увеличим на 1
Выведем набор Ключ => Значение
map - словарь
map<тип_ключа, тип_значения>
Вывод отдельной пары
cout << pair.first << " " << pair.second << endl;
m.insert('D', 30);
Ключ             Значение
Количество вхождений элемента A
cout << m.count('A') << endl;
Удаляем элемент
m.erase('A');
cout << m.count('A') << endl;
.\05_Qt\qt_debug2\main.cpp
.\05_Qt\qt_qui\main.cpp
.\05_Qt\qt_qui\mainwindow.cpp
Операция конкатенации
TODO: сумму чисел
TODO: Как сделать проще?
TODO: Собрать с QWebView
.\05_Qt\qt_qui\mainwindow.h
.\05_Qt\qt_test3\main.cpp
.\06_Qt_HelloWorld\main.cpp
``` cpp
int main(int argc, char* argv[]) {
  // Очередь и обработка событий
  //  Сигнал => Слот
  //  Объект_отправитель отправляет
  //   сигнал
  //  Его получают все объекты_получатели
  //   у которых подходящие слоты
  //   подключены к этому сигналу
  // Пример:
  //   Объект отправитель - Кнопка
  //   Сигнал - нажатие кнопки
  //   При созданнии сигнала этого типа
  //   будут вызваны все функции-обработчики
  //   подключенные к этому сигналу.
  QApplication a(argc, argv);

  // Создаём основное окно программы
  MainWindow w;
  // Показываем его
  w.show();

  // Запускаем цикл обработки событий
  return a.exec();
}
```

.\06_Qt_HelloWorld\mainwindow.cpp
.\06_Qt_HelloWorld\mainwindow.h
.\HomeWork_1\main.cpp
.\HomeWork_1\mainwindow.cpp
TODO: реализовать перемещение
ui->textEdit->geometry().translate(0, 10);
TODO: реализовать перемещение
TODO: реализовать перемещение
TODO: реализовать перемещение
.\HomeWork_1\mainwindow.h
.\build-06_Qt_HelloWorld-Desktop_Qt_5_4_0_MinGW_32bit-Debug\ui_mainwindow.h
.\build-HomeWork_1-Desktop_Qt_5_4_0_MinGW_32bit-Debug\ui_mainwindow.h
.\console_utf8\main.cpp
setlocale(LC_CTYPE,"rus");
setlocale(LC_CTYPE,"rus.1251");
setlocale(LC_CTYPE,NULL);
setlocale(LC_ALL, "ru_RU.UTF-8");
setlocale(LC_CTYPE, "UTF-8");
setlocale(LC_ALL, "UTF-8");
SetConsoleOutputCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);
system("chcp 65001");
locale u("rus_RUS.utf8"); // или rus.utf8, или просто .utf8 ?
cout.imbue(u);
.\errors.md
﻿Коды ошибок
-----------
* 0xС0000005 - Access violation

.\homework.md
﻿Домашняя работа
===============

1. Посмотреть, собрать, запустить примеры + подготовить вопросы
2. Реализовать перемещение виджета по нажатию кнопок

