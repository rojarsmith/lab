#include "toolbox.h"
#include "ui_toolbox.h"
#include "qt_mouse_hover/qhoverbutton.h"

ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBox)
{
    ui->setupUi(this);
}

ToolBox::~ToolBox()
{
    delete ui;
}
