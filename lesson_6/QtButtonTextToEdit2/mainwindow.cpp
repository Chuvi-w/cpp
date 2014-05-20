#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button1_clicked()
{
    // TODO: дописать
    QString s = ui->button1->text();
    // Получим строчку из lineEdit
    QString line = ui->lineEdit->text();
    // Соединим две строки
    QString res = line + s;
    // Отправим результат в интерфейс
    ui->lineEdit->setText(res);
}
