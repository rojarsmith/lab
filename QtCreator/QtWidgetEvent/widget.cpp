#include "widget.h"
#include "ui_widget.h"

#include <QCloseEvent>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer_id_fast_ = this->startTimer(1000);
    timer_id_slow_ = this->startTimer(5000);

    ui->label_mouse_->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timer_id_fast_)
    {
        static int sec = 0;
        if(sec == 10)
        {
            killTimer(timer_id_fast_);
        }
        ui->label_fast_->setText(QString("<center><h1>Timer out:%1</h1></center>").arg(sec++));
        ui->label_fast_->adjustSize();
    }
    else if(event->timerId() == timer_id_slow_)
    {
        static int sec = 0;
        ui->label_slow_->setText(QString("<center><h1>Timer out:%1</h1></center>").arg(sec++));
        ui->label_slow_->adjustSize();
    }
}

void Widget::closeEvent(QCloseEvent *event)
{
    int r = QMessageBox::question(this, tr("Question"), tr("Close the window."));
    if(r == QMessageBox::Yes){
        event->accept();
    }else{
        event->ignore();
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() >= Qt::Key_A && event->key() <= Qt::Key_Z){
        qDebug() << (char)event->key();
    }else{
        qDebug() << event->key();
    }
}

bool Widget::event(QEvent *event)
{
    switch(event->type()){
    case QEvent::Timer:
        timerEvent(static_cast<QTimerEvent *>(event));
        return true;
        break;
    case QEvent::KeyPress:
        if(static_cast<QKeyEvent *>(event)->key() == Qt::Key_Y){
            return QWidget::event(event);
        }
        return true;
        break;
    default:
        return QWidget::event(event);
        break;
    }
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->label_mouse_)
    {
        QMouseEvent *e = static_cast<QMouseEvent *>(event);
        if(e->type() == QEvent::MouseMove){
            ui->label_mouse_move_->setText(
                        QString(tr("<center><h1>Mouse Move:(%1, %2)"
                                   "</h1></center>")).arg(e->x()).arg(e->y()));
            ui->label_mouse_move_->adjustSize();
            return true;
        }
    }

    return QWidget::eventFilter(watched, event);
}
