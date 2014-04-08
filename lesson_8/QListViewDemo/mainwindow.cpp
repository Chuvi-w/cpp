#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include <QStandardItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаём модель в динамической памяти
    ListModel = new QStandardItemModel();
    // Первый список строк
    ui->listView->setModel(ListModel);
    // Второй список строк
    ui->listView_2->setModel(ListModel);
    // Таблица
    ui->tableView->setModel(ListModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Когда нажимаем на кнопку "Добавить"
void MainWindow::on_addButton_clicked()
{
    // Добавляем запись в listView (текст берём из интерфейса)
    qDebug() << "Добавляем запись в listView (текст берём из интерфейса)";
    QStandardItem* Items =
       new QStandardItem(ui->lineEdit->text());
    ListModel->appendRow(Items);
}

void MainWindow::on_removeButton_clicked()
{
    // Удалить выделенную запись
    foreach(const QModelIndex &index,
            ui->listView->selectionModel()->selectedIndexes())
        ListModel->removeRow(index.row());
}
