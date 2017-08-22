#include "toolbox.h"
#include "ui_toolbox.h"
#include "qt_mouse_hover/qhoverbutton.h"

ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBox)
{
    ui->setupUi(this);

    //ui->pushButton_3
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(handleButton()));
}

ToolBox::~ToolBox()
{
    delete ui;
}

void ToolBox::handleButton()
{
    if(!ui->pushButton_4->isHidden()){
        ui->pushButton_4->hide();
    }else{
        ui->pushButton_4->setVisible(true);
    }

    //ui->verticalLayout_3->addWidget(new QWidget());
}
