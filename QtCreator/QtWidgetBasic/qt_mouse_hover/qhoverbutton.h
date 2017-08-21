#ifndef QHOVERBUTTON_H
#define QHOVERBUTTON_H

#include <QtWidgets>

class QHoverButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QHoverButton(QWidget *parent = 0);

protected:
//    //void hoverEnter(QHoverEvent *event);
    virtual bool event(QEvent *event);
};

#endif // QHOVERBUTTON_H
