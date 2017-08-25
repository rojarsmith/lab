#include "mdieditor.h"
#include "ui_mdieditor.h"
#include "editorscene.h"

MdiEditor::MdiEditor(QWidget *parent) :
    QWidget(parent),
    m_GraphicsScene1(new QGraphicsScene),
    m_EditorScene(new EditorScene),
    ui(new Ui::MdiEditor)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(m_GraphicsScene1);

    ui->graphicsView_2->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    m_EditorScene->setSceneRect(0, 0, 400, 200);
    ui->graphicsView_2->setScene(m_EditorScene);
    ui->graphicsView_2->centerOn(0, 0);
}

MdiEditor::~MdiEditor()
{
    delete ui;
}
