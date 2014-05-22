#ifndef INPUTTHREAD_H
#define INPUTTHREAD_H

#include <QThread>

class InputThread : public QThread
{
    Q_OBJECT
public:
    explicit InputThread(QObject *parent = 0);

signals:

public slots:
 void run();
};

#endif // INPUTTHREAD_H
