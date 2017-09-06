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

    ui->pushButton_7->addButton(ui->pushButton_8);
    ui->pushButton_7->addButton(ui->pushButton_9);

    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(handleElementClicked()));
    //    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(handleElementClicked()));
    //    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(handleElementClicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(handleButton()));

    bool success = connect(ui->pushButton, SIGNAL(emitData1(int)), this, SLOT(onElementClicked1(int)));
    Q_ASSERT(success);
}

ToolBox::~ToolBox()
{
    delete ui;
}

void ToolBox::handleButton()
{
    QObject *button = QObject::sender();
    if(button == ui->pushButton_3){
        if(!ui->pushButton_3->isGroupHidden()){
            ui->pushButton_3->hideGroup(true);
        }else{
            ui->pushButton_3->hideGroup(false);
        }
    }

    if(button == ui->pushButton_7){
        if(!ui->pushButton_7->isGroupHidden()){
            ui->pushButton_7->hideGroup(true);
        }else{
            ui->pushButton_7->hideGroup(false);
        }
    }
}

void ToolBox::handleElementClicked()
{
    QObject *button = QObject::sender();
    if(button == ui->pushButton_4)
    {
        if(ui->pushButton_4->isChecked()){
            ui->pushButton_5->buttonUnClicked();
            ui->pushButton_6->buttonUnClicked();
            ui->pushButton_8->buttonUnClicked();
            ui->pushButton_9->buttonUnClicked();
        }
    }
}

void ToolBox::onElementClicked1(int i)
{
    int a = i;
}
