#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Сразу при старте приложения применяется регулярное выражение
    applyRegExp();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::applyRegExp(){
    // Когда текст выражения меняется, его надо заново применить
    // Когда текст меняется, заново применяем регулярное выражение

    // Очищаем окно результатов
    ui->resultText->clear();
    // Создаём новое регулярное выражение на основе строки
    QRegExp rx(ui->regExpEdit->text());
    // Если регулярное выражение некорректно,
    // то сразу выходим
    if(!rx.isValid()){
        qDebug() << "Invalid regexp: " << ui->regExpEdit->text();
        return;
    }
    // Текст для применения регулярного выражения
    QString str = ui->sourceText->toPlainText();
    int pos = 0;
    while ((pos = rx.indexIn(str, pos)) != -1) {
       int len = rx.matchedLength();
       ui->resultText->appendPlainText(
                   rx.cap(1) + " - " + rx.cap(2));
                       //QString("  len = %1").arg(len));

       if(len == 0) return;
       pos += len;
    }
}

