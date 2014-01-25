#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ListModel = new QStandardItemModel();
    ui->listView->setModel(ListModel);
    ui->listView_2->setModel(ListModel);
    ui->tableView->setModel(ListModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    // Добавляем запись в listView (текст берём из интерфейса)
    QStandardItem* Items = new QStandardItem(ui->lineEdit->text());
    ListModel->appendRow(Items);
}

void MainWindow::on_removeButton_clicked()
{
    // Удалить выделенную запись
    foreach(const QModelIndex &index, ui->listView->selectionModel()->selectedIndexes())
        ListModel->removeRow(index.row());
}
