#include "mouselabel.h"

#include <QMouseEvent>
#include <QDebug>

MouseLabel::MouseLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
}

void MouseLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        qDebug() << "Left";
    }
    else if(event->button() == Qt::RightButton){
        qDebug() << "Right";
    }
    else if(event->button() == Qt::MidButton){
        qDebug() << "Middle";
    }
    int pos_x = event->x();
    int pos_y = event->y();
    QString str = QString("<center><h1>Mouse Press:(%1, %2)</h1></center>").arg(pos_x).arg(pos_y);
    this->setText(str);
    this->adjustSize();
}

void MouseLabel::mouseReleaseEvent(QMouseEvent *event)
{
    QString str = QString("<center><h1>Mouse Release:(%1, %2)</h1></center>").arg(event->x()).arg(event->y());
    this->setText(str);
    this->adjustSize();
}

void MouseLabel::mouseMoveEvent(QMouseEvent *event)
{
    QString str = QString("<center><h1>Mouse Move:(%1, %2)</h1></center>").arg(event->x()).arg(event->y());
    this->setText(str);
    this->adjustSize();
}

void MouseLabel::enterEvent(QEvent *event)
{
    QString str = QString("<center><h1>Mouse Enter</h1></center>");
    this->setText(str);
    this->adjustSize();
}

void MouseLabel::leaveEvent(QEvent *event)
{
    QString str = QString("<center><h1>Mouse Leave</h1></center>");
    this->setText(str);
    this->adjustSize();
}
