#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = NULL;

    on_enterChatButton_clicked();

    // Таймер опроса "кто онлайн"
    QTimer *timer = new QTimer(this);
    // Соединяем сигнал со слотом
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(refreshOnlineList()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Создание UDP-чата
void MainWindow::UdpChat(QString nick, int port)
{
    // Если соединение уже открыто, то закрываем его
    if(socket != NULL){
        socket->close();
        delete socket;
        socket = NULL;
    }
    // Создание чата
    socket = new QUdpSocket(this);
    // QHostAddress("192.168.1.104") - конкретный IP, с которого можно подключиться

    // QHostAddress::Any - принимать сообщения со всех IP адресов
    if(socket->bind(QHostAddress::Any, port)){
        // При получении данных (сигнал readyRead)
        // вызываем метод (слот) read, который
        connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
    } else {
        // Какая-то программа на этом компьютере уже
        // заняла порт port
        qDebug() << "Port " << port << " in use. Change port!";
        return;
    }

    send(nick + " - в чате", USUAL_MESSAGE);
}

// Нажимаем на кнопку "Войти в чат"
void MainWindow::on_enterChatButton_clicked()
{ 
    QString nick = ui->nicknameEdit->text();
    UdpChat(nick,
            ui->portNumEdit->text().toInt());
    // Разрешаем отправлять сообщения только когда уже в чате
    ui->sendButton->setEnabled(true);
}


// Отправка сообщения в сеть
void MainWindow::send(QString str, qint8 type) {
    // Полный пакет данных будет в массиве data
    QByteArray data; // Массив данных для отправки

    // Последовательно выводим в него байты
    QDataStream out(&data, QIODevice::WriteOnly);
    //out << qint64(-100000); // Размер сообщения (сначала ставим 0)
    out << qint8(type); // Тип сообщения
    out << str; // Само сообщение
    // Снова перемещаемся на начало массива
    //out.device()->seek(qint64(0));
    // Записываем в начало сообщения его размер
    //out << qint64(data.size() - sizeof(qint64));

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
    QByteArray data;
    // Устанавливаем массиву размер соответствующий размеру полученного пакета данных
    data.resize(socket->pendingDatagramSize());
    QHostAddress *address = new QHostAddress();
    socket->readDatagram(data.data(), data.size(), address);
    qDebug() << "Message from IP: " << address->toString() << " " << data.size();

    // Разбор полученного пакета
    QDataStream in(&data, QIODevice::ReadOnly);

    // Первые 8 байт - размер
   /* qint64 size = -1;
    if(in.device()->size() > sizeof(qint64)) {
        in >> size;
    } else
        return; */

  //  if (in.device()->size() - sizeof(qint64) < size) return;

    // Получаем тип пакета
    qint8 type = 0;
    in >> type;

    if (type == USUAL_MESSAGE) {
        QString str;
        in >> str;

        if(str.length() == 0)
            return;

        // Записываем входящие сообщения в файл
        QFile file("log.txt");
        file.open(QIODevice::WriteOnly | QIODevice::Text
                  | QIODevice::Append );
        QTextStream log(&file);
        log.setCodec("UTF-8");
        log << str << "\n";
        file.close();

        // Отображаем строчку в интерфейсе
        ui->plainTextEdit->appendPlainText(str);
    } else if (type == PERSON_ONLINE) {
        // Добавление пользователя с считанным QHostAddress
        QString str;
        in >> str;
        ui->onlineList->addItem(str);
    } else if (type == WHO_IS_ONLINE) {
        send(ui->nicknameEdit->text(), qint8(PERSON_ONLINE));
    }
}

// Нажимаем на кнопку "Отправить сообщение"
void MainWindow::on_sendButton_clicked()
{
    // Вся строка сообщения: "ник: сообщение"
    send(ui->nicknameEdit->text() + ": " +
         ui->messageEdit->text(),
         USUAL_MESSAGE);

    ui->messageEdit->clear();
}

void MainWindow::on_messageEdit_returnPressed()
{
    on_sendButton_clicked();
}

// Обновляем список тех кто online
void MainWindow::refreshOnlineList(){
    // TODO: хранить время, когда последний раз этот человек был в сети

    ui->onlineList->clear();
    send("", WHO_IS_ONLINE);
}
