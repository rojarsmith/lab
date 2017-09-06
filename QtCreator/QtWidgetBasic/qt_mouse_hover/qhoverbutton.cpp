#include "qhoverbutton.h"

QHoverButton::QHoverButton(QWidget *parent)
    : QPushButton(parent),
      isUnderline(false)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);

    connect(this,SIGNAL(pressed()), this, SLOT(clickedButton()));
}

bool QHoverButton::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::HoverEnter:
        hoverEnter(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverLeave:
        hoverLeave(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverMove:
        hoverMove(static_cast<QHoverEvent*>(event));
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(event);
}

void QHoverButton::hoverEnter(QHoverEvent *)
{
    QFont font = this->font();
    font.setBold(true);
    this->setFont(font);
    //repaint();
}

void QHoverButton::hoverLeave(QHoverEvent *)
{
    QFont font = this->font();
    font.setBold(false);
    this->setFont(font);
    //repaint();
}

void QHoverButton::hoverMove(QHoverEvent *)
{
    QFont font = this->font();
    if(isUnderline){
        font.setBold(false);
        font.setUnderline(false);
        isUnderline = false;
    }else{
        font.setBold(true);
        font.setUnderline(true);
        isUnderline = true;
    }
    this->setFont(font);
    //repaint();
}

void QHoverButton::clickedButton()
{
    emit emitData1(999);
}
