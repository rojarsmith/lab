#ifndef QHOVERBUTTON_H
#define QHOVERBUTTON_H

#include <QtWidgets>

class QHoverButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QHoverButton(QWidget *parent = 0);

protected:
    bool isUnderline;
    virtual void hoverEnter(QHoverEvent *event);
    virtual void hoverLeave(QHoverEvent *event);
    virtual void hoverMove(QHoverEvent *event);
    virtual bool event(QEvent *event) Q_DECL_OVERRIDE;
};

#endif // QHOVERBUTTON_H
