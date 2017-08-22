#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>

namespace Ui {
class ToolBox;
}

class ToolBox : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBox(QWidget *parent = 0);
    ~ToolBox();
private slots:
   void handleButton();
private:
    Ui::ToolBox *ui;
};

#endif // TOOLBOX_H
