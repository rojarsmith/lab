#include "paintframe.h"
#include "paintscene.h"

#include <QTimer>
#include <QGraphicsView>
#include <QGridLayout>

PaintFrame::PaintFrame(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(QSize(100, 100));
    m_gridLayout = new QGridLayout(this);
    m_graphicsView = new QGraphicsView(this);

    scene = new PaintScene();  // Init graphics scene
    m_graphicsView->setScene(scene);  // Set graphics scene

    m_gridLayout->addWidget(m_graphicsView, 0, 0, 1, 1);

    timer = new QTimer();       // Init Timer
    connect(timer, &QTimer::timeout, this, &PaintFrame::slotTimer);
    timer->start(16);          // Run Timer
}

PaintFrame::~PaintFrame()
{
    if(scene) delete scene;
}

void PaintFrame::slotTimer()
{
    /* Recalculate the size of the graphic scenes, depending on the size of the window
     * */
    timer->stop();
    scene->setSceneRect(0,0, this->m_graphicsView->width() - 20, this->m_graphicsView->height() - 20);
}

void PaintFrame::resizeEvent(QResizeEvent *event)
{
    timer->start(16);
    QWidget::resizeEvent(event);
}
