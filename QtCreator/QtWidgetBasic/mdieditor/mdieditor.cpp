#include "mdieditor.h"
#include "ui_mdieditor.h"

MdiEditor::MdiEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MdiEditor)
{
    ui->setupUi(this);
}

MdiEditor::~MdiEditor()
{
    delete ui;
}
