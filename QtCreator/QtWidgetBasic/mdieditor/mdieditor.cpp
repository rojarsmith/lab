#include "mdieditor.h"
#include "ui_mdieditor.h"

MdiEditor::MdiEditor(QWidget *parent) :
    QWidget(parent),
    m_GraphicsScene1(new QGraphicsScene),
    ui(new Ui::MdiEditor)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(m_GraphicsScene1);
}

MdiEditor::~MdiEditor()
{
    delete ui;
}
