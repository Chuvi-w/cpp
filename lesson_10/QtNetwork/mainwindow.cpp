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
