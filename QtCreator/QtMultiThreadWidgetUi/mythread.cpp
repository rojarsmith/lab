#include "mythread.h"
#include <QMutex>

MyThread::MyThread(QObject *parent):QThread(parent)
{
    Stop =false;
}

MyThread::~MyThread()
{
    Stop = true;
    quit();
    wait();
}

void MyThread::run(){
    for(int i =0;i<10000;i++){
       QMutex mutex;
       mutex.lock();
       if(this->Stop)
       {
           mutex.unlock();
           break;
       }
       mutex.unlock();

       emit NumberChanged(i);

       msleep(100);
    }
}
