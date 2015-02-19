.\00_debug.md
﻿Виды отладки: отладчик, трассировка (логгирование), модульные тесты, визуализаторы процесса выполнения
------------------------------------------------------------------------------------------------------




.\01_QtLayouts\loginform.cpp
.\01_QtLayouts\loginform.h
.\01_QtLayouts\main.cpp
.\01_QtLayouts\mainwindow.cpp
.\01_QtLayouts\mainwindow.h
.\02_QtWidgets\main.cpp
.\02_QtWidgets\mainwindow.cpp
.\02_QtWidgets\mainwindow.h
.\03_QListViewDemo\main.cpp
.\03_QListViewDemo\mainwindow.cpp
Создаём модель в динамической памяти
Первый список строк
Задаём как модель для дерева
Задаём как модель для таблицы
Когда нажимаем на кнопку "Добавить"
Добавляем запись в listView (текст берём из интерфейса)
Удалить выделенную запись
Массив (коллекция) по которой надо пробежать
.\03_QListViewDemo\mainwindow.h
Модель: контейнер (массив) для записей
Хранилище строк для отображения в списке
.\04_ItemWidgets\main.cpp
.\04_ItemWidgets\mainwindow.cpp
.\04_ItemWidgets\mainwindow.h
.\04_PhoneBook\main.cpp
.\04_PhoneBook\mainwindow.cpp
Сохраняем все изменения
Обновляем модель
TODO: разобраться с id autoincrement
.\04_PhoneBook\mainwindow.h
.\04_Qt_MouseMove\main.cpp
.\04_Qt_MouseMove\mainwindow.cpp
Отслеживаем движение мыши
QMessageBox::information(this, "Ну, конечно же...",
"А мы и не сомневались!");
return;
Остальные типы диалогов
Параметры: parent, title, message
Создаём объект
Обработчик движения мыши
qDebug() << x << y << "in" << rect.x() << rect.y();
.\04_Qt_MouseMove\mainwindow.h
Обработчик движения мыши
Сюда будем выводить координаты мыши
Обработчик при нажатии на кнопку "Да"
.\04_Qt_MouseMove\ui_mainwindow.h
.\05_QtDebug\main.cpp
Перенаправляем все сообщения
которые программа выводит в текстовую
консоль в файл
freopen("stdout.txt", "w", stdout);
freopen("stderr.txt", "w", stderr);
system("pause");
.\05_TreeWidget\main.cpp
.\05_TreeWidget\mainwindow.cpp
Добавить запись в дерево
ui->treeWidget->selectionModel()->selection()
Сортировка
.\05_TreeWidget\mainwindow.h
.\06_QFile\README.md
﻿Работа с файлами в Qt
=====================

.\06_QFile\main.cpp
Работа с файлами при помощи QFile
Выводить в текстовый файл с помощью Qt
QIODevice::WriteOnly - создаём файл для записи
QIODevice::Text - к выводу применяются правила
для текстового файла
Теперь прочитаем всё что записали
Читаем целую строку из файла
Открываем файл второй раз и дописываем текст
.\06_QWidgets\form2.cpp
.\06_QWidgets\form2.h
.\06_QWidgets\inputwidgets.cpp
.\06_QWidgets\inputwidgets.h
.\06_QWidgets\main.cpp
MainWindow w;
.\06_QWidgets\mainwindow.cpp
.\06_QWidgets\mainwindow.h
.\07_ReadWriteTextStl\main.cpp
Открыть файл для записи
Вывод как в cout
Закрыть файл
.\08_QtWidgets\main.cpp
.\08_QtWidgets\mainwindow.cpp
.\08_QtWidgets\mainwindow.h
.\FunctionTypedef\main.cpp
__stdcall
typedef int(*myfun)(int a, void *b)
.\HomeWork_Browser\README.md
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


.\HomeWork_Browser\main.cpp
.\HomeWork_Browser\mainwindow.cpp
При нажатии на кнопку Go переходим на адрес
Добавление адреса сайта в закладки
TODO: реализовать
Переход по кнопке из избранного
TODO: реализовать
Когда меняется URL в webView => меняем и URL в строке адреса
.\HomeWork_Browser\mainwindow.h
.\Miner\form2.cpp
.\Miner\form2.h
.\Miner\main.cpp
.\Miner\mainwindow.cpp
Подключаю вторую форму чтобы использовать
её из первой
Создаём поле
button->setVisible(true);
QObject::sender() - указатель на отправителя сигнала
проблема в том что этот указатель не того типа
Он типа QObject*, а не QPushButton*
Поэтому мы его приводим к нужному типу
a = (double)(23423 + 32424)
Выключаем поле
.\Miner\mainwindow.h
Свой Qt-класс
.\VersionsDemo\main.cpp
.\VersionsDemo\mainwindow.cpp
.\VersionsDemo\mainwindow.h
.\VisualStudioExample\VisualStudioExample\VisualStudioExample.cpp
VisualStudioExample.cpp : Defines the entry point for the console application.

.\VisualStudioExample\VisualStudioExample\stdafx.cpp
stdafx.cpp : source file that includes just the standard includes
VisualStudioExample.pch will be the pre-compiled header
stdafx.obj will contain the pre-compiled type information
TODO: reference any additional headers you need in STDAFX.H
and not in this file
.\VisualStudioExample\VisualStudioExample\stdafx.h
stdafx.h : include file for standard system include files,
or project specific include files that are used frequently, but
are changed infrequently

TODO: reference additional headers your program requires here
.\VisualStudioExample\VisualStudioExample\targetver.h
The following macros define the minimum required platform.  The minimum required platform
is the earliest version of Windows, Internet Explorer etc. that has the necessary features to run
your application.  The macros work by enabling all features available on platform versions up to and
including the version specified.
Modify the following defines if you have to target a platform prior to the ones specified below.
Refer to MSDN for the latest info on corresponding values for different platforms.
