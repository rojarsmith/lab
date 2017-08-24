#include "paintframe.h"
#include "paintscene.h"

#include <QTimer>
#include <QGraphicsView>

PaintFrame::PaintFrame(QWidget *parent) :
    QWidget(parent),
    m_QGraphicsView(new QGraphicsView)
    //,ui(new Ui::Paint)
{
//    ui->setupUi(this);
    this->

    scene = new PaintScene();  //初始化圖形場景

//    ui->graphicsView->setScene(scene);  //設置場景圖形

    timer = new QTimer();       //定時器初始化
//    connect(timer, &QTimer::timeout, this, &Paint::slotTimer);
    timer->start(16);          //啟動定時器
}

PaintFrame::~PaintFrame()
{
    //delete ui;
}

void PaintFrame::slotTimer()
{
    /* 重新定義圖形場景的尺寸，根據窗口的大小 */
    timer->stop();
    //scene->setSceneRect(0,0, this->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void PaintFrame::resizeEvent(QResizeEvent *event)
{
    timer->start(16);
    QWidget::resizeEvent(event);
}
