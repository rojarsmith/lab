#include "toolbox.h"
#include "ui_toolbox.h"
#include "qt_mouse_hover/qhoverbutton.h"

ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBox)
{
    ui->setupUi(this);

    ui->pushButton_3->addButton(ui->pushButton_4);
    ui->pushButton_3->addButton(ui->pushButton_5);
    ui->pushButton_3->addButton(ui->pushButton_6);
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(handleButton()));
}

ToolBox::~ToolBox()
{
    delete ui;
}

void ToolBox::handleButton()
{
    if(!ui->pushButton_3->isGroupHidden()){
        ui->pushButton_3->hideGroup(true);
    }else{
        ui->pushButton_3->hideGroup(false);
    }
}
