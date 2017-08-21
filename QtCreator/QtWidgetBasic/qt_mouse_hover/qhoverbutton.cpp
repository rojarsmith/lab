#include "qhoverbutton.h"

QHoverButton::QHoverButton(QWidget *parent)
    : QPushButton(parent)
{
//setMouseTracking(true);
}

bool QHoverButton::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::HoverEnter:

        break;
    default:
        break;
    }
    return QWidget::event(event);
}
