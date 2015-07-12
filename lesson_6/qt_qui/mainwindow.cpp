#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow2::MainWindow2(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow2) {
  ui->setupUi(this);
}

MainWindow2::~MainWindow2() {
  delete ui;
}

void MainWindow2::on_sumButton_clicked() {
  QString a(ui->edit1->text());
  QString b(ui->edit2->text());
  // �������� ������������
  QString c = a + b;
  // TODO: ����� �����
  ui->edit3->setText(c);
}

void MainWindow2::moveSumButton(int dy) {
  // TODO: ��� ������� �����?
  QRect rect = ui->sumButton->geometry();
  rect.moveTop(rect.top() + dy);
  ui->sumButton->setGeometry(rect);
}

void MainWindow2::on_pushButton_clicked() {
  moveSumButton(-3);
}

void MainWindow2::on_pushButton_2_clicked() {
  moveSumButton(+3);
}

void MainWindow2::on_checkBox_stateChanged(int arg1) {
  ui->sumButton->setEnabled(
    ui->checkBox->checkState()
  );
}

void MainWindow2::on_checkBox_toggled(bool checked) {

}

// TODO: ������� � QWebView
