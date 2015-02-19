.\000_intro.md

﻿Template. Шаблонные функции. Стратегии
======================================

Обобщённое программирование
---------------------------

Описание шаблона. Шаблонные функции (min, max и т.д.). Шаблонные классы
-----------------------------------------------------------------------

Контейнеры
----------

Стандартная библиотека шаблонов STL: контейнеры, итераторы, алгоритмы, адаптеры, функторы (vector, algorithm)
-------------------------------------------------------------------------------------------------------------


.\00_HomeWork_Done\main.cpp

Домашнее задание: Реализовать стек и очередь
--------------------------------------------
Разбор домашнего задания
Полезные макросы для отладки
``` cpp
#define D(x) cout << #x << endl; x;
#define SHOW(x) cout << #x << " = " << x << endl;
```

Элемент стека и очереди
``` cpp
struct E {
  int value; // Значение элемента
  E* next; // Указатель на следующий элемент
};

// Стек
struct Stack {
  E* top = NULL; // Вершина стека
};

// Значение поместить на вершину стека
void push(Stack& s, int value) {
  // newElement - переменная в стеке
  //  - указатель на новый элемент стека
  E* newElement = new E;

  // Записываем значение,
  // которое надо поместить
  // на вершину стека
  (*newElement).value = value;
  // второй вариант:
  newElement->value = value;

  // Новый элемент на вершине стека
  // поэтому все остальные следуют за ним
  newElement->next = s.top;

  // Ставим новый элемент в начало списка
  s.top = newElement;
}
// Взять значение с вершины стека
int pop(Stack& s) {
  // Стек не пуст
  assert(s.top != NULL);

  // Запоминаем результат
  // - значение элемента-"вершины" стека
  // 1-A
  int result = s.top->value;

  // Запоминаем ссылку на удаляемый
  // элемент
  // 1-B
  E* toDelete = s.top;

  // 2. Перемещаем вершину на следующий
  s.top = s.top->next;

  // 3. Реально удаляем элемент
  delete toDelete;

  // 4. Возвращаем результат
  return result;
}

struct Queue {
  E* head = NULL; // "Голова" - начало очереди
  E* tail = NULL; // "Хвост" - конец очереди
};

// В конец очереди
void put(Queue& q, int value) {
  // Создаём новый элемент
  E* e = new E;
  e->value = value;
  e->next = NULL;

  // Если очередь пуста
  if(q.head == NULL) {
    q.head = e;
    q.tail = e;
  } else {
    // Если в очереди уже есть элементы
    // "Присоединяем" элемент к последнему
    // элементу в очереди
    q.tail->next = e;
  }
}
// Забрать первый элемент из очереди
int get(Queue& q) {
  // Запоминаем первый элемент
  E* firstElement = q.head;
  // Значение, которое мы в конце вернём
  int value = firstElement->value;
  // Передвигаем указатель на начало
  // очереди на следующий элемент
  q.head = q.head->next;

  // Если очередь пуста, то
  // хвост очереди не указывает ни на
  // какой элемент
  if(q.head == NULL)
    q.tail = NULL;

  // Удаляем первый элемент из
  // динамической памяти
  delete firstElement;

  // Возвращаем его значение
  return value;
}
```

.\00_HomeWork_Done_OOP\main.cpp

Домашнее задание: Реализовать стек и очередь
--------------------------------------------
Разбор домашнего задания
``` cpp
// Элемент стека и очереди
struct E {
  int value; // Значение элемента
  E* next; // Указатель на следующий элемент
};

// Стек
struct Stack {
  E* top; // Вершина стека
  // Конструктор
  Stack() : top(NULL) {}
  // Значение поместить на вершину стека
  void push(int value) {
    E* newElement = new E;
    // Записываем значение,
    // которое надо поместить
    // на вершину стека
    newElement->value = value;
    // Новый элемент на вершине стека
    // поэтому все остальные следуют за ним
    newElement->next = top;

    // Ставим новый элемент в начало списка
    top = newElement;
  }
  // Взять значение с вершины стека
  int pop() {
    int result = top->value; // 1. Сохраняем результат - значение элемента-"вершины" стека
    E* e = top; // 2. Запоминаем ссылку на удаляемый элемент
    top = top->next; // 3. Перемещаем вершину стека на следующий элемент
    delete e; // 4. Реально удаляем элемент
    return result; // 5. Возвращаем результат
  }
};

struct Queue {
  E* head; // "Голова" - начало очереди
  E* tail; // "Хвост" - конец очереди
  // Конструктор
  Queue() : head(NULL), tail(NULL) {};
  // В конец очереди
  void put(int value) {
    // Создаём новый элемент
    E* e = new E;
    e->value = value;
    e->next = NULL;

    // Если очередь пуста
    if(head == NULL) {
      head = e;
      tail = e;
    } else {
      // Если в очереди уже есть элементы
      // "Присоединяем" элемент к последнему
      // элементу в очереди
      tail->next = e;
    }
  }
  // Забрать первый элемент из очереди
  int get() {
    // Запоминаем первый элемент
    E* firstElement = head;
    // Значение, которое мы в конце вернём
    int value = firstElement->value;
    // Передвигаем указатель на начало
    // очереди на следующий элемент
    head = head->next;

    // Если очередь пуста, то
    // хвост очереди не указывает ни на
    // какой элемент
    if(head == NULL)
      tail = NULL;

    // Удаляем первый элемент из
    // динамической памяти
    delete firstElement;

    // Возвращаем его значение
    return value;
  }
};
```

``` cpp
  D(Stack s);
  D(s.push(2));
  D(s.push(3));
  cout << "3 - " << s.pop() << endl;
  cout << "2 - " << s.pop() << endl;

  D(Stack s2);
  D(s2.push(10));
  D(s.push(11));
  cout << "11 - " << s.pop() << endl;
  cout << "10 - " << s2.pop() << endl;

  D(Queue q);
  D(q.put(10));
  D(q.put(14));
  cout << "10 - " << q.get() << endl;
  cout << "14 - " << q.get() << endl;
```

.\00_HomeWork_Taison4eg\main.cpp

Домашнее задание: Реализовать стек и очередь - разбор
-----------------------------------------------------
* FIFO - очередь - First Input First Output
* LIFO - стек - Last Input First Output

Средства отладки:
* Отладчик (пошаговое выполнение,
точки останова, просмотр переменных и т.д.)
* Модульные тесты (проверять утверждения)
* Писать лог/протокол работы
* Ручное тестирование
Элемент стека и очереди
Стек
Конструктор
Значение поместить на вершину стека
Взять значение с вершины стека
Конструктор
Функция, которая вернет
последний элемент,
не работает...
Контракт: очередь не пуста
Элемент у которого
ссылка на следующий отсутствует
Очередь пуста?
Положить значение
в конец очереди
Забрать первый элемент из очереди
Выводить ли сообщения на консоль
argc - количество аргументов командной
строки
argv - аргументы командной строки
Выводим все аргументы командной строки
Перенаправляем вывод в файл
assert(s.pop()==3);
.\01_OOP_Food\main.cpp

Приготовление ужина
-------------------
Дано: набор продуктов
их можно смешивать, подогревать
Нужно: хранить набор продуктов,
+ добавлять новый продукт
Компонент еды - конкретный продукт
Список продуктов
Корневой элемент списка
Список пуст?
Добавляем элемент в начало списка
Добавляем элемент в начало
как в стек
Количество данного компонента
Нашли нужный компонент
Если не нашли такого продукта?
Минимум из всех компонент
Сколько у нас данного продукта есть?
Сколько мы можем приготовить
учитывая только этот компонент
Пустой список продуктов
Единица измерения
Новый список - список, что нужно для
приготовления блинов
.\01_StackDemo\main.cpp

``` cpp
class Stack {
  const static int STACK_SIZE = 100;
  int data[STACK_SIZE];
  // Текущий размер стека
  int count = 0;
 public:
  // Положить данные на вершину стека
  void push(int value) {
    if(count == STACK_SIZE) {
      cout << "Stack is full!" << endl;
      return;
    }

    data[count++] = value;
  }
  // Забрать данные с вершины стека
  int pop() {
    if(count == 0) {
      cout << "Stack is empty!" << endl;
      return -1;
    }

    return data[--count];
  }
};
```

.\02_vectors\main.cpp

Конструктор - вызывается после создания объекта в памяти
Деструктор - вызывается перед удалением объекта из памяти
Конструктор копирования
.\13_constructor_destructor\main.cpp

Конструкторы и деструкторы
--------------------------
``` cpp
// struct - С
// class - С++

// Ключевое слово class
// Имя_класса
class MyClass {
  // Количество объектов
  static int count;
  // Идентификатор данного объекта
  int id;
  int* data;
 public:
  // Конструктор
  MyClass();
  // Деструктор
  ~MyClass();
};

// Инициализация static-переменной
int MyClass::count = 0;

MyClass::MyClass() {
  count++;
  id = count;
  cout << "Constructor #" << id << endl;

  data = new int[1000];
  data[0] = 10;
}

MyClass::~MyClass() {
  cout << "Destructor #" << id << endl;

  cout << data << " " << data[0] << endl;
  delete[] data;
}

struct A {
  int w;
  A(int v) {
    w = v;
  }
};
```

.\14_copy_contructor\main.cpp

Конструктор копирования
-----------------------
``` cpp
// Класс "строка"
class string {
  static int count; // Количество строк
  char*    Str;
  int     size;
 public:
  int id; // Идентификатор данной строки
  string(string&); // Конструктор копирования
  // Конструктор
  string(const char* str) {
    id = ++count;
    std::cout << "Constructor #" << id << " \"" << str << "\"" << std::endl;
    size = strlen(str); // "ABC\0"
    Str = new char[size + 1];
    strcpy(Str, str);
  };
  // Вывод строки на экран
  void show() {
    std::cout << Str << std::endl;
  }
  // Деструктор
  ~string() {
    std::cout << "Destructor #" << id << std::endl;
    delete[] Str; // Очищаем динамическую память
  }
  // Перегрузка операции присваивания
  string& operator=(string& right) {
    if(Str != NULL)
      delete[] Str;

    std::cout << "= #" << id << std::endl;
    // if(Str != NULL)
    //   delete[] Str;
    Str = new char[right.size + 1];
    size = right.size;
    strcpy(Str, right.Str);
  }
};

// Конструктор копирования
// Создает копии динамических переменных и ресурсов
string::string(string& x) {
  id = ++count;
  std::cout << "Copy constructor #" << id << std::endl;
  // if(Str != NULL)
  //   delete[] Str;
  Str = new char[x.size + 1];
  size = x.size;
  strcpy(Str, x.Str);
}

int string::count = 0;
```

.\15_ListExample\main.cpp

Один элемент списка
следующий элемент списка
Список целиком, с всеми операциями
Указатель на первый элемент списка
ListElement *root = NULL;
Конструктор - метод, который вызывается
при создании объекта (экземпляра класса)
NULL - означает что нет ни одного элемента в списке
Деструктор (очистка памяти)
Запоминаем 2-ой элемент списка
(следующий после первого элемента)
Удаляем первый элемент списка
delete:
1. Вызывается деструктор (если есть)
2. Освобождается динамическая память
Показать список
cur->value <-> (*cur).value
Добавить элемент в начало
Заводим новый элемент в динамической памяти
Заполняем новый элемент
Подвешиваем к новому элементу старый список
Теперь root должен ссылаться на новый элемент
Добавить элемент в конец
Если список пуст, то добавить в конец
это то же что и добавить в начало
Ищем последний элемент
Убеждаемся в том, что это последний элемент
списка
Заводим новый элемент
Подвешиваем новый элемент в конец списка
.\16_inherit\00_intro.md

﻿Наследование и уровни доступа
-----------------------------


.\16_inherit\main.cpp

Наследование и уровни доступа
-----------------------------
**Наследование** - способность производного класса
наследовать характеристики существующего базового класса
Базовый класс A
``` cpp
class A {
 public: // Доступно всем
  int a;  // A test;  test.a = 10;
 protected: // Доступно внутри класса и наследникам
  int forChilds; // из методов этого и наследников
 private:  // Доступно только внутри методов
  int privateA; // этого класса
};
```

B - наследник класса A
``` cpp
class B : public A { // Все поля и методы
 public: // кроме private доступны
  int a;
  int b;
  void method1() {
    a = 1;
    b = 2;
    forChilds = 10;
    A::a = 10;
    B::a = 11;
    // privateA = 1; // Невозможно
    // this->privateA;
  }
};

class C : public B {
 public:
  int c;
  int a;
  // if(dynamic_cast<A>(this) != NULL)
};
```

Извне можно обратиться только
к public-полям и методам
b1.forChilds = 5;
```

.\16_inherit_sameName\main.cpp

Наследование: поле с тем же имененем
------------------------------------
Пусть есть класс **A**
с полем **x** и методом **show**
``` cpp
class A {
 public:
  int x = -1;
  void show() {
    cout << "x = " << x << endl;
  }
};
```

И его наследник **B**
тоже с полем **x** и методом **show**
``` cpp
class B : public A {
 public:
  int x = -2;
  void show() {
    A::x++;
    cout << "A::x = " << A::x << endl;
    cout << "B::x = " << B::x << endl;
  }
};
```

Как получить доступ к каждому из полей **x**?
``` cpp
int main() {
  A a;
  B b;
  a.x = 1;
  a.show();
  b.x = 2;
  b.show();
  return 0;
}
```

.\17_inherit\main.cpp

Наследование
------------
struct A <--> class A { public:
class A <--> struct A { private:
``` cpp
struct A {
  static int staticInClass;
  int a; // Поле доступно отовсюду

  void doA() {
    cout << "doA()" << endl;
    onlyInA = 2;
    cout << "onlyInA = " << onlyInA << endl;
    forChilds = 10;
  };
 private:
  int onlyInA; // Только внутри класса A
 protected:
  int forChilds; // Внутри класса A и в наследниках
};
```

B - наследник A
``` cpp
struct B : public A {
  int b;
  int forChilds; // Поле с тем же именем
  void doB() {
    cout << "doB()" << endl;
    //onlyInA = 2; // Недоступно в наследниках
    doA();
    //cout << "onlyInA = " << onlyInA << endl;
    A::forChilds = 12;
    forChilds = 20; // Работает
    this->forChilds = 20; // Работает

    cout << "A::forChilds = " << A::forChilds << endl;
    cout << "B::forChilds = " << B::forChilds << endl;
  };
};
```


Множественное наследование
show(); // Ошибка компиляции
Мы должны явно указать из какого предка вызываем метод
потому что это глобальная переменная
a.onlyInA = 3; // 'int A::onlyInA' is private
'int A::forChilds' is protected
cout << a.forChilds << endl;
Нет доступа, т.к. onlyInA private
b.onlyInA = 10;
c.a = 1; // Ошибка из-за protected наследования
c.b = 2; // Ошибка из-за protected наследования
c.doA();
c.doB();
x.doL();
.\18_polymorph\main.cpp

``` cpp
// Фигура
struct Shape {
  //virtual void show(){
  //  cout << "Shape" << endl;
  //};
  virtual void show() = 0; // Абстрактный метод
 protected:
  // virtual void doA() = 0;
  // virtual void doB() = 0;
  // virtual void doC() = 0;
  // virtual void doD() = 0;
  // virtual void doE() = 0;
  //int x;
 private:
  char c1;
  char c2;
  char c3;
  char c4;
  char c5;
} __attribute__((packed));
```

Квадрат
``` cpp
struct Square : public Shape {
  double side;
  Square(double s) : side(s) { }
  void show() {
    cout << "Square side = " << side << endl;
  }
};
```

Прямоугольник
``` cpp
struct Rectangle : public Shape {
  double height, width;
  Rectangle(double h, double w) :
    height(h), width(w) { }
  void show() {
    cout << "Rectangle " << height <<
         " x " << width << endl;
  }
};
```

``` cpp
int main() {
  // Shape shape; // Ошибка компиляции
  cout << sizeof(Shape) << endl;
  Shape* s[] = {
    new Square(10),
    new Rectangle(2, 3),
    new Square(15),
    // new Shape(),
  };

  for(int i = 0; i < 3; ++i)
    s[i]->show();

  return 0;
}
```

.\19_setter_getter\main.cpp

``` cpp
struct A {
 private:
  int a;

 public:
  A() {
    a = 33;
  }

  // setter - метод для установки значения поля
  void setA(int value) {
    cout << "a = " << value << endl;
    a = value;
  }
  // getter - метод для получения значения поля
  int getA() {
    return a;
  }
};


int main() {
  A a1; // A - класс, a1 - объект
  a1.setA(20);
  cout << a1.getA() << endl;
  return 0;
}
```

.\20_getter_setter_square\main.cpp

Зачем нужны get/set методы?
---------------------------
Don’t Repeat Yourself
http://ru.wikipedia.org/wiki/Don%E2%80%99t_repeat_yourself
Дублирование данных
``` cpp
class Square2 {
  double side; // Сторона
  double area; // Площадь
 public:
  // Просто возвращаем значение
  double getSide() {
    return side;
  }
  double getArea() {
    return area;
  }
  // При изменении меняем одновременно
  void setSide(double value) {
    side = value;
    area = value * value;
  }
  void setArea(double value) {
    side = sqrt(value);
    area = value;
  }
};
```

.\20_getter_setter_square\square.cpp

Реализация метода в отдельном C++ файле
``` cpp
void Square::setArea(double value) {
#ifdef SIDE
  side = sqrt(value);
#else
  area = value;
#endif
}
```

.\20_getter_setter_square\square.h

Инкапсуляция
------------
Объект должен быть "скромным"
Класс "Квадрат"
``` cpp
class Square {
  //private: // Инкапсуляция
#ifdef SIDE
  double side; // Сторона
#else
  double area; // Площадь - сторона в квадрате
#endif // SIDE
 public:
  // Получить сторону квадрата
  double getSide() {
#ifdef SIDE
    return side;
#else
    return sqrt(area);
#endif // SIDE
  }
  // Задать сторону квадрата
  void setSide(double value) {
#ifdef SIDE
    side = value;
#else
    area = value * value;
#endif // SIDE
  }
  // Получить площадь
  double getArea() {
#ifdef SIDE
    return side * side;
#else
    return area;
#endif // SIDE
  }
  // Задать площадь
  void setArea(double value);
};
```

.\21_task_rational\main.cpp

Перегрузка операторов в C++. Вывод в поток
------------------------------------------
**Оператор в C++** - это некоторое действие или функция обозначенная специльным символом (символами).
Чтобы распространять действие операторов на новые (свои) типы данных в C++ их можно перегружать.
Для перегрузки используется ключевое слово **operator** вместе с прототипом и объявлением функции.
Практика: класс "рациональная дробь"
------------------------------------
Сокращение типа
``` cpp
typedef long long ll;
```

НОД - Наибольший общий делитель.
GCD - Greatest common divisor.
``` cpp
long GCD(long a, long b) {
  return (b == 0) ? a : GCD(b, a % b);
}
```

``` cpp
// Рациональная дробь: p/q
class Rational {
  long p, q; // p - числитель, q - знаменатель
  // Сокращение дроби
  void normalize() {
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    p /= d; // делим на него числитель
    q /= d; // делим на него знаменатель
  }
  void show(ostream& os) const {
    // Сокращаем дробь если надо
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    long px = p / d; // делим на него числитель
    long qx = q / d; // делим на него знаменатель

    if(qx < 0) {
      px = -px;
      qx = -qx;
    }

    // Если знаменатель равен 1
    // то это целое число
    if(qx == 1)   // Условие (1)
      os << px << endl;
    else {
      // Целая часть
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
      os << px << "/" << qx << endl;
    }
  }
 public:
  // TODO: Конструктор
  Rational(long pi, long qi) :
    p(pi), q(qi) {
    assert(q != 0);
    //if(q == 0){
    //  cout << "q == 0" << endl;
    //  halt(1);
    //}
  }
  Rational(const char* message) {
    cout << message << " ";
    cout << "p = ";
    cin >> p;
    cout << "q = ";
    cin >> q;
    normalize();
  }
  // Показать дробь на экран (в консоль)
  void show() {
    show(cout);
  }

  // Сложение дробей
  void add(Rational& right) {
    //   p    right.p
    //  --- + -------
    //   q    right.q
    p = p * right.q + right.p * q;
    //  --------------------------
    q =       q * right.q;

    // Для предотвращения переполнений
    normalize();
  }

  // a + b
  const Rational operator+(Rational& right) {
    Rational res = *this;
    res.add(right);
    return res;
  }

  Rational operator+(int right) {
    Rational res = *this;
    Rational r(right, 1);
    res.add(r);
    return res;
  }

  friend
  Rational
  operator+(long left, Rational& right) {
    Rational res(left, 1);
    res.add(right);
    return res;
  }

  void sub(Rational& right) {
    p = p * right.q - right.p * q;
    //  --------------------------
    q =       q * right.q;

    normalize();
  }

  Rational operator-(Rational& right) {
    Rational res = *this;
    res.sub(right);
    return res;
  }

  // Конструктор копирования
  /* Rational(const Rational &r){
     //cout << r.p << "/" << r.q << endl;
     p = r.p;
     q = r.q;
     //cout << "Copy contructor " << p << "/" << q << endl;
   } */

  friend ostream& operator <<(ostream& os, const Rational& r) {
    r.show(os);
    return os;
  }
};

#define SHOW(x) { cout << #x << " = " << (x) << endl; }

int main() {
  /* Rational x(3, 1);
   x.show();

   Rational y(6, 4);
   y.show(); */

  Rational aa(2, 6), bb(3, 6);
  SHOW(aa);
  SHOW(bb);
  SHOW(aa - bb);

  Rational a(4, 6), b(11, 2);
  SHOW(a);
  SHOW(b);
  Rational c = a + b;
  SHOW(c);
  SHOW(a + b);
  SHOW(a - b);
  SHOW(a / b);
  SHOW(a * b);
  SHOW(a);
  SHOW(b);

  // Rational c = b + a;

  int i = 2, j = 3;
  int tt = i + j;
  Rational c1 = i + b;

  b.show();
  c1.show();

  Rational x(4, 6), y(1, 3);
  x.add(y);
  x.show();

  Rational yy("Vvedite:");
  yy.show();

  return 0;
}
```

.\22_this_demo\main.cpp

Работа с this
-------------
``` cpp
class Boy;

class Girl {
 public:
  Boy* boy;
  void reg(Boy* b) {
    boy = b;
  }
  void answer();
};

class Boy {
 public:
  Girl* girl;
  void reg(Girl* g) {
    girl = g;
    girl->reg(this);
  }
  void dialog() {
    cout << "Boy: hi!" << endl;
    girl->answer();
  }
  void answer() {
    cout << "Boy: I'm find! And how are you?" << endl;
  }
};

void Girl::answer() {
  cout << "Girl: Hi! How are you?" << endl;
  boy->answer();
}


int main() {
  Girl g;
  Boy b;
  b.reg(&g);

  b.dialog();

  return 0;
}
```

.\23_diamond_inherit\main.cpp

Diamond Inheritance
-------------------
``` cpp
//   A
//  / \
// B   C
//  \ /
//   D
#include <iostream>

using namespace std;

struct X {
  void show() {
    cout << "X" << endl;
  };
};

struct A {
  char name;
  A() : name('A') {};
  virtual
  void show() {
    cout << "show_A " << name << endl;
  };
};

struct B : virtual public A {
  B() {
    A::name = 'B';
  };
  void show() {
    cout << "show_B " << name << endl;
  };
};

struct C : virtual public A {
  C() {
    A::name = 'C';
  };
  void show() {
    cout << "show_C " << name << endl;
  };
};

struct D : public B, public C {
  D() {
    B::name = 'D';
  };
  void show() {
    cout << "show_D " << B::name << endl;
    B::show();
    C::show();
    C::A::show();
    B::A::show();
  };
};

int main() {
  /*A a;
  a.show();
  B b;
  b.show();
  C c;
  c.show(); */

  D d;
  d.show();

  /*A* x[4] = {new A, new B, new C, new D};
  for(int i = 0; i < 4; ++i)
    x[i]->show();
  */
  // Полиморфизм
  A* x[4] = { new B, new A, new C, new D };
  /* A* x[4];
   x[0] = new C;
   x[1] = new B;
   x[2] = new A;
   x[3] = new D; */

  cout << "sizeof(X) = " << sizeof(X) << endl;
  cout << "sizeof(*X) = " << sizeof(X*) << endl;

  cout << "+ VMT" << endl;
  cout << "sizeof(A) = " << sizeof(A) << endl;
  cout << "sizeof(*A) = " << sizeof(A*) << endl;

  for(int i = 0; i < 4; ++i)
    x[i]->show();

  for(int i = 0; i < 4; ++i)
    delete x[i];

  return 0;
}
```

.\25_iterator\main.cpp

Итерируемся по set
for(vector<int>)
.\26_private_constructor_singletone\00_main.cpp

Private-конструктор
-------------------
Шаблон Singletone - "Одиночка"
``` cpp
class MyClass {
  // private constructor
  MyClass() {
    id = ++count;
  };
  static int count;
  static MyClass* instanse; // private
 public:
  int id; // Индентификатор объекта
  static MyClass* getInstanse() {
    if(instanse == NULL) {
      instanse = new MyClass;    // Вызов конструктора
    }

    return instanse;
  }
};

int MyClass::count = 0;
MyClass* MyClass::instanse = NULL;

int main() {
  MyClass* a = MyClass::getInstanse();
  MyClass* b = MyClass::getInstanse();

  cout << "a->id = " << a->id << endl;
  cout << "b->id = " << b->id << endl;
  return 0;
}
```

.\26_private_constructor_singletone\main.cpp

Для чего использовать private-конструкторы?
-------------------------------------------
Шаблон проектирования Singletone
``` cpp
// Создаем класс S
// Задача: сделать чтобы в программе
// был только один экземпляр этого класса
// Singletone / Одиночка
class S {
  //private: // по-умолчанию и так private
  static int count;
  int id;
  // private (частный) конструктор
  S() {
    count++;
    id = count;
    cout << "Constructor #" << id << endl;
  }
  // Один-единственный экземпляр класса S
  static S* instance;
 public:
  // Единственный способ получить экземпляр
  // класса S - вызвать этот метод
  static S& getInstance() {
    if(instance == NULL)
      instance = new S;

    return *instance;
  }
  void show() {
    cout << "S #" << id << endl;
  }
  ~S() {
    cout << "Destructor: #" << id << endl;
  }
};

int S::count = 0;
S* S::instance = NULL;

int main() {
  //S s1;
  //S *s = new S;
  S a = S::getInstance(), b = S::getInstance();
  a.show();
  b.show();
  S c = S::getInstance();
  c.show();
  return 0;
}
```

.\27_string_overflow\main.cpp

Переполнение строки
-------------------
``` cpp
union Bytes {
  int i; // Тип int занимает 4 байта
  char bytes[4]; // Он же в виде 4-х отдельных
};
```

``` cpp
struct Shape {
  char type; // type = 'C' - круг, 'S' - квадрат
  double x, y;
  union {
    double R;
    double Side;
  };
};
```

``` cpp
struct Point {
  double x, y;

  // Расстояние между точками
  double dist(Point b) {
    return sqrt(pow(x - b.x, 2) +
                pow(y - b.y, 2));
  }

};
```

SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
``` cpp
  char str[10]; // Строка до 9 символов, последний символ 0

  cout << "Введите строку больше 10 символов: ";
  cin >> str;

  freopen("result.txt", "w", stdout);
  cout << str << endl;
```

.\28_Russian\README.md

﻿Список всех поддерживаемых консолей?
------------------------------------

Unix / MacOS
``` bash
locale -a
```

.\28_Russian\c.cpp

.\28_Russian\hw_cp866.c

.\28_Russian\hw_cp866.cpp

.\28_Russian\hw_utf8.cpp

C++
Вывод в консоль по-русски:
``` cpp
  system("chcp 65001");
  SetConsoleOutputCP(CP_UTF8);
  std::locale::global(std::locale ("en_US.UTF-8"));
  printf("Это моя первая программа!\n");
  cout << "Текст в UTF-8" << endl;
  cout << "И он нормально читается в Windows-консоли!" << endl;
```

.\28_Russian\hw_utf8_2.cpp

C++
Вывод в консоль по-русски:
``` cpp
  //setlocale(LC_ALL, "Russian_Russia.65001");
  setlocale(LC_ALL, "Russian.UTF-8");
  //SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);
```

.\28_Russian\show_cur_locale.cpp

Получаем параметры текущей локали
``` cpp
#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  char language[256] = {0}, country[256] = {0};
  GetLocaleInfo(
    GetUserDefaultLCID(),
    LOCALE_SENGLANGUAGE,
    language, sizeof(language));
  GetLocaleInfo(
    GetUserDefaultLCID(),
    LOCALE_SENGCOUNTRY,
    country, sizeof(country));

  UINT OEM_CP = GetOEMCP(); // Возвращает системную OEM кодовую страницу как число
  // UINT ANSI_CP = GetANSICP();

  printf("%s_%s %d\n", language, country, OEM_CP);

  cout << language << "_" << country << "." << OEM_CP << endl;
}
```

.\98_dict_textfile\main.cpp

Открываем файл для чтения
Открываем файл для записи
TODO: доделайте сами :)
.\99_!x\00_class\main.cpp

.\99_!x\01_arrays_const\main.cpp

Применение модификатора const в ООП
Метод не модифицирует состояние объекта
.\99_!x\01_contructor_destructor\main.cpp

Создание объекта
1. Отводится память sizeof(размер_объекта)
2. Присваиваются значения полям
3. Список инициализации из вызванного
конструктора
4. Выполняется код конструктора
Уничтожение объекта
1. Выполняется код деструктора
2. Очищается память занятая объектом
.\99_!x\02_bitfields\main.cpp

cout
.\99_!x\02_copy_constructor\main.cpp

Конструктор копирования
.\99_!x\03_inheritance\main.cpp

до первого private наследования
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
protected - наследуем класс A
только для себя и наследников
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
В наследнике C доступны те же поля
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
private - наследуем класс A
только для себя (без наследников)
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
Недоступно ничего из A
A -> private B -> public C
publicA = 1;
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
protectedA = 3;
a.privateA = 10; // Недоступно
a.protectedA = 10; // Недоступно
bPublic.privateA = 10; // Недоступно
bPublic.protectedA = 10; // Недоступно
bProtected.publicA = 111;
C.publicA = 12;
.\99_!x\04_DoubleLinkedList\main.cpp

Добавить элемент в начало списка
Тот элемент, который раньше был первым
теперь должен ссылаться на новый первый элемент
Добавляем элемент в конец списка
Список не пустой
Идея: найти последний элемент списка
Для "старого" последнего элемента
следующий элемент - новый элемент
Для нового элемента: предыдущий -
"старый" последний элемент
Удалить первый элемент списка
Мы удаляем первый элемент, поэтому
предыдущего элемента нет
Удаляем из памяти
Ищем элемент по значению
Нашли элемент с заданным значением!
Если есть следующий
У следующего prev заменяем на на prev
Если есть предыдущий
У предыдущего next заменяем на наш next
Мы удаляем первый элемент, поэтому
root должен указывать на второй
Удалить по индексу
Удалим первый элемент
Снова посмотрим список
Удаляем средний
Удаляем первый элемент
Удаляем единственный элемент
Удаляем последний элемент
.\99_!x\04_Shapes\main.cpp

Базовый класс: Фигура
Имя фигуры (строка)
Конструктор для вызова из наследников
Каждая фигура показывает своё имя
Наследники Shape:
Конструктор
Внутри 2 точки
Конструктор
Одна точка и радиус
Конструктор
Везде метод show() -> показывает свойства фигуры
.\99_!x\06_Class_static\main.cpp

Ключевое слово: static -
поле/метод относится к классу целиком
а не к конкретному объекту.
за всё время работы программы объектов
(экземпляров) класса MyClass
т.е. оно только увеличивается и не
уменьшается при удалении объекта
Идентификатор - уникальный номер
данного экземпляра класса
Конструктор - специальный метод
который вызывается сразу после
отведения памяти под объект
Деструктор - специальный метод
который вызывается прямо перед
удалением объекта из памяти
Инициализируем статическое поле класса
.\99_!x\06_polymorph\main.cpp

abstract
interface  C# / Java
.\99_!x\07_inherit_simple\main.cpp

Класс A - предок класса B
Класс B - наследник класса A
.\99_!x\07_poly_check\main.cpp

.\99_!x\08_inherit_2\main.cpp

B - наследует поля и методы и из A и из A2
error: reference to 'x' is ambiguous|
x = 2;
Если уникальна
Хоть var из A2 и не видно, всё равно надо
указать класс
.\99_!x\08_inherit_order\main.cpp

..
Квадрат - частный случай прямоугольника
.\99_!x\09_cout_my_class\main.cpp

os = cout - типа ostream
Point = P
.\99_!x\09_private_public_protected\main.cpp

Только для "частного" использования
т.е. внутри класса Base
и в наследниках
privateVar = 122; // Недоступна
Так же, как при public-наследовании
privateVar = 122; // Недоступна
Наследуем поля только для себя
privateVar = 122; // Недоступна
base.privateVar = 1;
pub.privateVar - недоступна
p.publicVar = 11;
.\99_!x\10_public_protected_private_combinations\main.cpp

Доступны и x и y
.\99_!x\12_virtual\main.cpp

.\99_!x\13_InheritShapes\main.cpp

Фигура
Название фигуры
Цвет фигуры
Количество точек
Толщина границы (бордюра)
"ABC\0"
Точка
Квадрат
Левый правый угол
Сторона
Окружность
Координаты центра
Радиус окружности
Shape s("222",3,3,3);
.\99_!x\14_template_in_template\main.cpp

Шаблонная функция вычисления минимума
Стек заданной длины
T - тип элементов
Size - максимальное количество
(размер стека)
Массив для хранения данных
Количество элементов
Положить в стек значение
Извлечь с вершины стека значение
Очередь заданной длины
Голова и хвост очереди
Количество элементов
Положить в конец очереди
Взять из начала очереди
TODO: Разобрать пример на следующем занятии
Шаблонная функция для печати любой коллекции
.\99_!x\99_virtual\task1.cpp

.\99_!x\HomeWork\main.cpp

typedef long long ll;
НОД - Наибольший общий делитель
Рациональная дробь: p/q
Сокращение дроби
TODO: Конструктор
TODO: Ввод с клавиатуры
TODO: Показать дробь на экран (в консоль)
TODO: Сложение дробей
a + b
this - указатель на текущий объект
*this - текущий объект
TODO: прибавить к дроби целое число
TODO: прибавить к целому число дробь
TODO: вычитание
TODO: вычитание
Конструктор копирования
cout - типа ostream
stream - поток
thread - поток/нить
Rational c = b + a;
.\99_!x\PointStuct\main.cpp

Точка
Point(){};
Отрезок
p1.x = x1;  p1.y = y1;
p2.x = x2;  p2.y = y2;
Длина отрезка
Point p(2,3);
cout << "p.x = " << p.x << "  p.y = " << p.y << endl;
.\99_!x\StructNew\main.cpp

scanf("%s",c);
for(int i = 20; i < 10000; i--)
c[i] = 124;
.\99_!x\StructStaticCount\main.cpp

...
.\99_!x\TemplateFunction\main.cpp

.\99_!x\cont_textfiles\main.cpp

Перевод
Как ввести строку целиком?
Как читать
system("chcp 65001");
SetConsoleCP(65001);
SetConsoleOutputCP(65001);
freopen("out.txt","w",stdout);
Ключ - слово по-английски,
значение - слово по-русски
Словарь = Ассоциативный массив
int p = 1;
fclose(stdin); // !!!
cin >> p;
Считываем
Смотрим в словаре
const int strLen = 1024;
char phrase[strLen];
cin.getline(phrase, strLen);
cout << phrase << endl;
Ищем слово из словаря в строке
cout << inEnglish << " pos " << pos << endl;
.\99_!x\copy_constructor\main.cpp

потому что в строке символ 0 - окончание строки
Создает копии динамических переменных и ресурсов
SetConsoleCP(65001);
SetConsoleOutputCP(65001);
Добавить в конец кусок строки
Строка должна стать "TestEnd" после этой операции
.\99_!x\map_dict\main.cpp

Контейнеры:
vector
set
map
Ассоциативный массив
A["Hi"] = "Привет";
map<key, value>
dict[3] = 4;
dict[3] = 5;
.\99_!x\map_example\main.cpp

Итератор в строке пробегает по буквам
с первой буквы до последней по одной
Очередная буква строки
Не нашли букву => она первый раз
.\99_!x\memory_leaks\main.cpp

Утечки памяти
-------------
TODO: SmartPtr для обработки этой ситуации
delete intArray;
delete[] intArray;
.\99_!x\oop\main.cpp

commonVar = 4;
Объявляю 2 экземпляра (объекта) класса
a.privateVar = 2;
Переменная i у каждого объекта своя
commonVar - общая для всех объектов этого класса
.\99_!x\smart_pointer\main.cpp

Умные указатели
Умный указатель (Smart Pointer) — класс (обычно шаблонный),
имитирующий интерфейс обычного указателя и добавляющий некую новую функциональность,
например, проверку границ при доступе или очистку памяти.
В STL есть: std::auto_ptr
Обычный класс
Использует динамическую память
Умный указатель
Автоматическая отчистка динамической памяти
setlocale(LC_ALL, "Russian");
SmartPtr<int[]> m2 = new int[10];
.\99_!x\stl\main.cpp

set - множество (неповторяющиеся элементы)
Вектор - аналог массива
a.insert(2, 10);
a.remove(3);
.\99_!x\string_overflow\main.cpp

.\99_!x\struct_in_plain_c\main.c

.\99_!x\vector_MyType\main.cpp

.\99_!x\virtual_destructor\main.cpp

.\errors.md

﻿Коды ошибок
-----------

* **0xC0000005** - обращение по неправильному указателю.


.\homework.md

﻿Домашнее задание: реализовать классы геометрических фигур
---------------------------------------------------------

Базовый класс **Фигура**
``` cpp
struct Shape { // struct -> public:
  virtual void show() = 0; // Абстрактный метод
};
```
Квадрат
``` cpp
struct Square : public Shape {
  double side;
  Square(double s) : side(s) { }
  void show() {
    // TODO: реализовать
  }
};
```

Прямоугольник
``` cpp
struct Rectangle : public Shape {
  double height, width;
  Rectangle(double h, double w) :
    height(h), width(w) { }
  void show() {
    // TODO: реализовать
  }
};
```

Демонстрационная программа показывающая все фигуры:
``` cpp
int main() {
  Shape* s[] = {
    new Square(10),
    new Rectangle(2, 3),
    new Square(15),
  };

  for(int i = 0; i < 3; ++i)
    s[i]->show();

  return 0;
}
```

.\homework_2.md

﻿Домашнее задание: реализовать с использованием STL
--------------------------------------------------

* Самое часто встречающееся число
* Максимум в массиве
* Переводчик текста на основе map

