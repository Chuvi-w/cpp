#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT

    // Имя потока
    QString name;

public:
    explicit MyThread(QObject *parent = 0,
                      QString name = "Thread");

signals:

public slots:

    void run();
};

#endif // MYTHREAD_H
