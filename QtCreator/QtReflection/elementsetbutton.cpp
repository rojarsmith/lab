#include "elementsetbutton.h"

ElementSetButton::ElementSetButton(QGraphicsItem *parent)
    : ElementAbstraction(Q_NULLPTR), QGraphicsRectItem(parent)
{

}

ElementSetButton::ElementSetButton(QObject *parent)
    : ElementAbstraction(Q_NULLPTR), QGraphicsRectItem(Q_NULLPTR)
{

}
