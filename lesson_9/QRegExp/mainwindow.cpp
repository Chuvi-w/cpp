#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRegExp>
#include <qnamespace.h>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

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
    rx.setMinimal(!ui->maxLenSearchBox->isChecked());
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
       QString s;
       // rx.captureCount() - количество найденных групп символов
       for(int i = 1; i <= rx.captureCount(); i++){
           s.append(rx.cap(i) + "  ");
       }

       ui->resultText->appendPlainText(">> " + s);
                   //rx.cap(1) + " - " + rx.cap(2));
                       //QString("  len = %1").arg(len));

       // Защита от зацикливания программы
       if(len == 0) return;

       pos += len;
    }
}


void MainWindow::saveText(){
    QString filename = QFileDialog::getSaveFileName(
       this, "Сохранить текст", "", // C:\\Users\\Денис\\Desktop
       "Текст (*.txt)"); // "Как картинку (*.jpg);;Игра XO (*.game)"
    qDebug() << "Имя файла для сохранения: " << filename;

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::critical(this,
           "Не получается записать файл",
           filename);
        return;
    }
    QString data = ui->sourceText->toPlainText();
    file.write(data.toUtf8());
    file.close();
}

void MainWindow::loadText(){
    QString filename = QFileDialog::getOpenFileName(
       this, "Загрузить текст",
           QDir::homePath() + "\\Desktop",
       "Текст (*.txt)");
    // TODO: Как получить Мои Документы

    qDebug() << "Имя файла для загрузки: " << filename;
    if(filename == ""){
        return;
    }

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this,
           "Не получается открыть файл",
           filename);
        return;
    }
    QByteArray array = file.readAll();
    QString data(array);
    // Второй вариант: QString data = QString::fromUtf8(array);
    ui->sourceText->setPlainText(data);
    file.close();
}

void MainWindow::on_regExpEdit_editingFinished()
{

}
