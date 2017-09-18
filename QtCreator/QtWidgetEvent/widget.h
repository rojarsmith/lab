#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    virtual bool event(QEvent *event) override;
    virtual void timerEvent(QTimerEvent *event) override;
    virtual void closeEvent(QCloseEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Ui::Widget *ui;
    int timer_id_fast_;
    int timer_id_slow_;
};

#endif // WIDGET_H
