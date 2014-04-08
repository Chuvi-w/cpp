#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

void MainWindow::on_regExpEdit_textChanged(const QString &arg1)
{
    // Когда текст выражения меняется, его надо заново применить
    applyRegExp();
}

void MainWindow::on_srcText_textChanged()
{
    // Когда текст меняется, заново применяем регулярное выражение
    applyRegExp();
}

void MainWindow::applyRegExp(){
    // Очищаем окно результатов
    ui->resText->clear();
    // Создаём новое регулярное выражение на основе строки
    QRegExp rx(ui->regExpEdit->text());
    // Если регулярное выражение некорректно,
    // то сразу выходим
    if(!rx.isValid())
        return;
    // Текст для применения регулярного выражения
    QString str = ui->srcText->toPlainText();
    int pos = 0;
    while ((pos = rx.indexIn(str, pos)) != -1) {
       int len = rx.matchedLength();
       ui->resText->appendPlainText(rx.cap(1) + " - " + rx.cap(2) +
                                    QString("len = %1").arg(len));

       if(len == 0) return;
       pos += len;
    }
}

