#ifndef ELEMENTSETBUTTON_H
#define ELEMENTSETBUTTON_H

#include "elementabstraction.h"
#include <QGraphicsRectItem>
#include <QObject>

class ElementSetButton : public ElementAbstraction, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit ElementSetButton(QGraphicsItem *parent = Q_NULLPTR);
    explicit ElementSetButton(QObject *parent = Q_NULLPTR);

signals:

public slots:
};

#endif // ELEMENTSETBUTTON_H
