#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Пока нет операции
    operation = ' ';

    newNumber = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::xbutton_clicked()
{
    QPushButton *b = (QPushButton *)
            QObject::sender();

    if(newNumber){
      arg = ui->display->text().toInt();
      ui->display->setText("");
    }

    ui->display->setText(
      ui->display->text() + b->text()
    );

    newNumber = false;
}

void MainWindow::on_plusButton_clicked()
{
    operation = '+';
    newNumber = true;
}

void MainWindow::on_calcButton_clicked()
{
    // Получаем второй аргумент
    int arg2 = ui->display->text().toInt();

    // Вычисляем результат
    int res = arg + arg2;

    // Показываем целое число в интерфейсе
    ui->display->setText(QString::number(res));

    operation = '=';

    newNumber = true;
}
