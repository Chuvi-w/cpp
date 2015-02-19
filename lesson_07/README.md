.\01_Enums\main.cpp
Перечисления
------------
``` cpp
// Направления
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
case DOWN:
;
.\01_QtWidgets\demowidgetswindow.cpp
ostringstream sstream;
sstream << sum;
.\01_QtWidgets\demowidgetswindow.h
.\01_QtWidgets\main.cpp
.\01_extern_vars\main.cpp
.\01_extern_vars\module1.cpp
.\01_extern_vars\module1.h
.\01_extern_vars\module2.cpp
.\01_extern_vars\module2.h
.\01_extern_vars\vars.h
Глобальная переменная
.\02_QString\main.cpp
.\02_QString\mainwindow.cpp
QString("%1 - %2").arg(s1).arg(s2)
s1 заканчивается на s2
.\02_QString\mainwindow.h
.\03_Qt_Geometry\main.cpp
.\03_Qt_Geometry\mainwindow.cpp
Получаем прямоугольник с координатами перемещаемого объекта
Двигаем прямоугольник
Задаём новое положение объекта
.\03_Qt_Geometry\mainwindow.h
.\05_Exceptions\main.cpp
throw QString("ERROR");
.\HomeWork_06\main.cpp
.\HomeWork_06\mainwindow.cpp
.\HomeWork_06\mainwindow.h
.\HomeWork_RussianRoulette\main.cpp
.\HomeWork_RussianRoulette\mainwindow.cpp
Очищаем лог игры
Инициализируем генератор случайных
чисел по таймеру
"Протокол" (log) игры
Один раунд игры
Ставка
На какое число ставим
Крутим рулетку
qrand() 0..MAX_INT = 2^31-1
Пересчитываем баланс
QString.toDouble() - преобразует строку
вида "213.1" в число типа double
Запоминаем баланс
Баланс показываем в интерфейсе
.\HomeWork_RussianRoulette\mainwindow.h
Номер раунда
.\HomeWork_RussianRoulette\random.cpp
Генерация случайного целого числа в диапазоне
low..high
.\HomeWork_RussianRoulette\random.h
Генерация случайного целого числа в диапазоне
low..high
.\HomeWork_SQL\main.cpp
Назначаем имя файлу
Открываем БД
Создаём экземпляр класса QSqlQuery чтобы выполнить запрос
Выполняем запрос, если ошибка в запросе,
то метод возвращает false
Выводим подробное сообщение об ошибке
.\QtButtonTextToEdit2\main.cpp
Вызов главной формы через указатель
Сохраняем результат выполнения...
...чтобы очистить память...
...и только потом выйти!
.\QtButtonTextToEdit2\mainwindow.cpp
При нажатии на любую клавишу с текстом
Получаем источник сигнала :)
Если это не кнопка, показываем сообщение и выходим
Сообщение об ошибке
TODO: дописать
Получим строчку из lineEdit
Соединим две строки
Отправим результат в интерфейс
Ещё один обработчик для кнопки 1 :)
.\QtButtonTextToEdit2\mainwindow.h
.\QtButtonTextToEdit2\mypushbutton.cpp
.\QtButtonTextToEdit2\mypushbutton.h
.\QtDatabase\main.cpp
0. Создаём БД для работы нашего приложения
1. Подключаем драйвер нужной БД
2. Подкчаемся к самой БД
3. Выполняем SQL-операторы
4. Получаем результаты их выполнения
5. Связываем с интерфейсом
.\QtReadTextToInterface\main.cpp
.\QtReadTextToInterface\mainwindow.cpp
Загрузка текста из файла
Utf-8
.\QtReadTextToInterface\mainwindow.h
.\QtWidgets\main.cpp
.\QtWidgets\mainwindow.cpp
ui->gridLayout->
Вывести сообщение: а мы и не сомневались!
.\QtWidgets\mainwindow.h
.\Qt_Geometry\main.cpp
.\Qt_Geometry\mainwindow.cpp
.\Qt_Geometry\mainwindow.h
.\StringConcat\main.cpp
.\StringConcat\mainwindow.cpp
1. Получаем данные из интерфейса
2. Соединяем 2 строки в одну (конкатенация)
3. Отправляем результат в интерфейс
.\StringConcat\mainwindow.h
