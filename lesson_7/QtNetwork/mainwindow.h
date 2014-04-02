#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

enum MessageType {
    USUAL_MESSAGE,
    PERSON_ONLINE,
    WHO_IS_ONLINE,

};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_enterChatButton_clicked();
    void on_sendButton_clicked();
    void read();

private:
    Ui::MainWindow *ui;

    QString nickname;
    QUdpSocket *socket;

    void UdpChat(QString nick, int port);
    // Отправить сообщение
    void send(QString str, qint8 type);
};

#endif // MAINWINDOW_H
