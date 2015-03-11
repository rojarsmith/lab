#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
  explicit  MyThread(QObject *parent = 0);
    ~MyThread();
    bool Stop;
signals:
    void NumberChanged(int);
public slots:
    void run();
};

#endif // MYTHREAD_H
