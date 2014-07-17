#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRegExp>
#include <qnamespace.h>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Сразу при старте приложения применяется регулярное выражение
    applyRegExp();

    // Каталог "Мои документы"
    qDebug() << QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
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
    QString regExp = ui->regExpEdit->text();
    QRegExp rx(regExp);
    rx.setMinimal(!ui->maxLenSearchBox->isChecked());
    // Если регулярное выражение некорректно,
    // то сразу выходим и выводим сообщение об ошибке в консоль
    if(!rx.isValid()){
        qDebug() << "Invalid regexp: " << regExp;
        return;
    }
    // Текст для применения регулярного выражения
    QString str = ui->sourceText->toPlainText();
    int pos = 0;
    // http://qt-project.org/doc/qt-5/qregexp.html#indexIn
    while ((pos = rx.indexIn(str, pos)) != -1) {
       // Длина найденного куска
       int len = rx.matchedLength();
       // Собираем группы в скобках в одну строку
       QString s;
       // rx.captureCount() - количество найденных групп символов
       for(int i = 1; i <= rx.captureCount(); i++){
           // rx.cap(i) - i-ая группа
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

void MainWindow::myNewSlot(){
    qDebug() << "myNewSlot()";
}

void MainWindow::on_sourceText_textChanged()
{

}
