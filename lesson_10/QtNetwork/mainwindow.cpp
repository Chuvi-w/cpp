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

void MainWindow::UdpChat(QString nick, int port)
{
    nickname = nick;
    socket = new QUdpSocket(this);
    _port = port;
    socket->bind(QHostAddress::Any, port);

    connect(socket, SIGNAL(readyRead()), SLOT(read()));
}

void MainWindow::on_enterChatButton_clicked()
{
    UdpChat(ui->nicknameEdit->text(), ui->portNumEdit->text().toInt());
}


void MainWindow::send(QString str, qint8 type) {
  QByteArray data;
  QDataStream out(&data, QIODevice::WriteOnly);
  out << qint64(0);
  out << qint8(type);
  out << str;
  out.device()->seek(qint64(0));
  out << qint64(data.size() - sizeof(qint64));
  socket->writeDatagram(data, QHostAddress::Broadcast, _port);
}

void MainWindow::read() {
  QByteArray datagram;
  datagram.resize(socket->pendingDatagramSize());
  QHostAddress *address = new QHostAddress();
  socket->readDatagram(datagram.data(), datagram.size(), address);

  QDataStream in(&datagram, QIODevice::ReadOnly);

  qint64 size = -1;
  if(in.device()->size() > sizeof(qint64)) {
    in >> size;
  } else return;
  if (in.device()->size() - sizeof(qint64) < size) return;

  qint8 type = 0;
  in >> type;

  if (type == USUAL_MESSAGE) {
    QString str;
    in >> str;
    ui->plainTextEdit->appendPlainText(str);
    // код по перенаправке сообщения в классы выше //
  } else if (type == PERSON_ONLINE) {
    // Добавление пользователя с считанным QHostAddress //
  } else if (type == WHO_IS_ONLINE) {
    send(nickname, qint8(PERSON_ONLINE));
  }
}

void MainWindow::on_sendButton_clicked()
{
    send(ui->messageEdit->text(), USUAL_MESSAGE);
}
