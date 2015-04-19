Перечисления (enum)
-------------------
Направления движения:
``` cpp
const int X_UP = 0;
const int X_DOWN = 1;
const int X_LEFT = 2;
const int X_RIGHT = 3;
int direction = X_UP;

enum Direction {
  UP = 4 /* 0 */, DOWN = 13 /* 1 */,
  LEFT = (1LL << 31) - 1 /* 2 */, RIGHT = 7/* 3 */
};

enum DirectionX {
  T_UP /* 0 */, T_DOWN /* 1 */,
  T_LEFT /* 2 */, T_RIGHT /* 3 */
};
```

#pragma pack(4)
[01_Enums\main.cpp](01_Enums\main.cpp)

Печать в строку как в поток
``` cpp
  ostringstream sstream;
  sstream << sum;
```

[01_QtWidgets\demowidgetswindow.cpp](01_QtWidgets\demowidgetswindow.cpp)

Определение глобальной переменной в **module1.cpp**
``` cpp
int globalVar = 2;
```

[01_extern_vars\module1.cpp](01_extern_vars\module1.cpp)

В **module2.cpp** тоже можно использовать
**globalVar**
``` cpp
void v2() {
  cout << "v2" << endl;
  globalVar = 2;
  cout << "globalVar = " << globalVar << endl;
}

void show2() {
  cout << "globalVar = " << globalVar << endl;
}
```

[01_extern_vars\module2.cpp](01_extern_vars\module2.cpp)

Глобальная переменная в **vars.h**
``` cpp
extern int globalVar;
```

[01_extern_vars\vars.h](01_extern_vars\vars.h)

Работа с QString
----------------
QString("%1 - %2").arg(s1).arg(s2)
s1 заканчивается на s2
[02_QString\mainwindow.cpp](02_QString\mainwindow.cpp)

Положение и размеры виджетов
----------------------------
``` cpp
  QRect r = ui->object->geometry();
  r.setBottom(r.bottom() - ui->step->value());
  r.moveTop(r.top() - ui->step->value());
  ui->object->setGeometry(r);
```

``` cpp
  // Получаем прямоугольник с координатами перемещаемого объекта
  QRect r = ui->object->geometry();
  // Двигаем прямоугольник
  r.translate(0, ui->step->value());
  // Задаём новое положение объекта
  ui->object->setGeometry(r);
```

[03_Qt_Geometry\mainwindow.cpp](03_Qt_Geometry\mainwindow.cpp)

Исключения
----------
throw QString("ERROR");
[05_Exceptions\main.cpp](05_Exceptions\main.cpp)

Задание "Русская рулетка"
-------------------------
Очищаем лог игры
Инициализируем генератор случайных
чисел по таймеру
``` cpp
  qsrand(time(0));
```

Добавление строки в "Протокол" (log) игры
``` cpp
void MainWindow::log(QString s) {
  ui->gameLog->append(s);
}
```

Один раунд игры
``` cpp
  round++;
  log(QString("<strong>Раунд %1:</strong>").arg(round));

  // Ставка
  double bet = ui->betEdit->value();
  // На какое число ставим
  int betNumber = ui->numberEdit->value();
  log(QString("Ваша ставка %1 на %2.").
      arg(bet).arg(betNumber));

  // Крутим рулетку
  // qrand() 0..MAX_INT = 2^31-1
  int randNumber = random(1, 10); // Число 1..10
  log(QString("Выпало: %1.").arg(randNumber));

  // Пересчитываем баланс
  // QString.toDouble() - преобразует строку
  //  вида "213.1" в число типа double
  double balance = ui->balanceLabel->text().toDouble();
  // Запоминаем баланс
  double prev = balance;

  if(randNumber == betNumber) {
    balance += bet * 10;
    log(QString("Выйграли! Новый счёт: %1 + %2 = %3")
        .arg(prev).arg(balance - prev).arg(balance));
  } else {
    balance -= bet;
    log(QString("Проиграли! Новый счёт: %1 - %2 = %3")
        .arg(prev).arg(prev - balance).arg(balance));
  }

  // Баланс показываем в интерфейсе
  ui->balanceLabel->setText(
    QString("%1").arg(balance, 0, 'f', 1)
  );
```

[HomeWork_RussianRoulette\mainwindow.cpp](HomeWork_RussianRoulette\mainwindow.cpp)

Генерация случайного целого числа в диапазоне
low..high
``` cpp
int random(int low, int high) {
  return low + qrand() % (high - low + 1);
}
```

[HomeWork_RussianRoulette\random.cpp](HomeWork_RussianRoulette\random.cpp)

Генерация случайного целого числа в диапазоне
low..high
``` cpp
int random(int low, int high);
```

[HomeWork_RussianRoulette\random.h](HomeWork_RussianRoulette\random.h)

Назначаем имя файлу
Открываем БД
Создаём экземпляр класса QSqlQuery чтобы выполнить запрос
Выполняем запрос, если ошибка в запросе,
то метод возвращает false
Выводим подробное сообщение об ошибке
[HomeWork_SQL\main.cpp](HomeWork_SQL\main.cpp)

Главная форма в динамической памяти
-----------------------------------
Создание главной формы:
``` cpp
  MainWindow* w = new MainWindow;
  // Вызов главной формы через указатель
  w->show();

  // Сохраняем результат выполнения...
  int res = a.exec();

  // ...чтобы очистить память...
  delete w;
  // ...и только потом выйти!
  return res;
```

[QtButtonTextToEdit2\main.cpp](QtButtonTextToEdit2\main.cpp)

При нажатии на любую клавишу с текстом
``` cpp
  // Получаем источник сигнала :)
  QPushButton* button = (QPushButton*)QObject::sender();

  // Если это не кнопка, показываем сообщение и выходим
  if(button == NULL) {
    // Сообщение об ошибке
    QMessageBox::critical(this, "Ошибка", "on_digitButton_clicked() работает только для QPushButton",
                          QMessageBox::Ok);
    return;
  }

  // TODO: дописать
  QString s = button->text();
  // Получим строчку из lineEdit
  QString line = ui->lineEdit->text();
  // Соединим две строки
  QString res = line + s;
  // Отправим результат в интерфейс
  ui->lineEdit->setText(res);
```

Ещё один обработчик для кнопки 1 :)
[QtButtonTextToEdit2\mainwindow.cpp](QtButtonTextToEdit2\mainwindow.cpp)

Задание: работа с базой данных
------------------------------
0. Создаём БД для работы нашего приложения
1. Подключаем драйвер нужной БД
2. Подкчаемся к самой БД
3. Выполняем SQL-операторы
4. Получаем результаты их выполнения
5. Связываем с интерфейсом
[QtDatabase\main.cpp](QtDatabase\main.cpp)

Загрузка текста из файла
Utf-8
[QtReadTextToInterface\mainwindow.cpp](QtReadTextToInterface\mainwindow.cpp)

ui->gridLayout->
TODO: Вывести сообщение: а мы и не сомневались!
[QtWidgets\mainwindow.cpp](QtWidgets\mainwindow.cpp)

1. Получаем данные из интерфейса
2. Соединяем 2 строки в одну (конкатенация)
3. Отправляем результат в интерфейс
[StringConcat\mainwindow.cpp](StringConcat\mainwindow.cpp)

