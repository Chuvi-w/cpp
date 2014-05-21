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

// Создание UDP-чата
void MainWindow::UdpChat(QString nick, int port)
{
    // Создание чата
    //nickname = nick; // Запоминаем ник

    socket = new QUdpSocket(this);
    // QHostAddress("192.168.1.104") - конкретный IP, с которого можно подключиться

    if(ui->createServer->isChecked()){
        if(socket->bind(QHostAddress::Any, port)){
            // При получении данных (сигнал readyRead)
            // вызываем метод (слот) read, который
            connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
        } else {
            qDebug() << "Port " << port << " in use. Change port!";
        }
        send(nick + " - создал сервер", USUAL_MESSAGE);
    } else {
        socket->bind(QHostAddress::Any, port);
        // При получении данных (сигнал readyRead)
        // вызываем метод (слот) read, который
        connect(socket, SIGNAL(readyRead()), this, SLOT(read()));

        send(nick + " - вошёл в чат", USUAL_MESSAGE);
    }
}

void MainWindow::on_enterChatButton_clicked()
{
    QString nick = ui->nicknameEdit->text();
    UdpChat(nick,
            ui->portNumEdit->text().toInt());
}


// Отправка сообщения в сеть
void MainWindow::send(QString str, qint8 type) {
    // Полный пакет данных будет в массиве data
    QByteArray data; // Массив данных для отправки

    //QFile file("test.dat");
    //file.open(QIODevice::WriteOnly);
    //QDataStream out2(&file);

    // Последовательно выводим в него байты
    QDataStream out(&data, QIODevice::WriteOnly);
    out << qint64(0); // Размер сообщения (сначала ставим 0)
    out << qint8(type); // Тип сообщения
    out << str; // Само сообщение
    // Снова перемещаемся на начало массива
    out.device()->seek(qint64(0));
    // Записываем в начало сообщения его размер
    out << qint64(data.size() - sizeof(qint64));

    /*long long size = sizeof(long long) + sizeof(type) +
          str.size();
  unsigned char message[size];
  memcpy(message, size);
  message[sizeof(long long)] = type;
  memcpy() */

    // Отправляем полученный массив данных всем в локальный сети
    // на порт указанный в интерфейсе
    socket->writeDatagram(data,
                          QHostAddress::Broadcast,
                          ui->portNumEdit->text().toInt() );
}

// Получение сообщения по UDP
void MainWindow::read() {
    // Массив для полученных данных
    QByteArray datagram;
    // Устанавливаем массиву размер соответствующий размеру полученного пакета данных
    datagram.resize(socket->pendingDatagramSize());
    QHostAddress *address = new QHostAddress();
    socket->readDatagram(datagram.data(), datagram.size(), address);
    qDebug() << address;

    // Разбор полученного пакета
    QDataStream in(&datagram, QIODevice::ReadOnly);

    // Первые 8 байт - размер
    qint64 size = -1;
    if(in.device()->size() > sizeof(qint64)) {
        in >> size;
    } else return;
    if (in.device()->size() - sizeof(qint64) < size) return;

    // Получаем тип пакета
    qint8 type = 0;
    in >> type;

    if (type == USUAL_MESSAGE) {
        QString str;
        in >> str;
        // Отображаем строчку в интерфейсе
        ui->plainTextEdit->appendPlainText(str);
    } else if (type == PERSON_ONLINE) {
        // Добавление пользователя с считанным QHostAddress //
    } else if (type == WHO_IS_ONLINE) {
        send(ui->nicknameEdit->text(), qint8(PERSON_ONLINE));
    }
}

void MainWindow::on_sendButton_clicked()
{
    // Вся строка сообщения: "ник: сообщение"
    send(ui->nicknameEdit->text() + ": " +
         ui->messageEdit->text(),
         USUAL_MESSAGE);
}
