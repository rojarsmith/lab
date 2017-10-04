#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "diagramscene.h"
#include "objectfactory.h"
#include "elementabstraction.h"
#include "elementsetbutton.h"

#include <QDebug>
#include <QGraphicsSimpleTextItem>
#include <QHash>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mode_(NONE),
    scene_(0),
    factory_(0),
    element_(0)
{
    ui->setupUi(this);    

    element_ = new QHash<QString, ElementAbstraction *>();

    scene_ = new DiagramScene(this, itemMenu_);
    scene_->setSceneRect(QRectF(0, 0, 500, 500));

    //scene_->setBackgroundBrush(QBrush(QColor(Qt::GlobalColor::black)));
    ui->graphicsView->setScene(scene_);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(Qt::black)));

    /* QGraphicsSimpleTextItem */
    QGraphicsSimpleTextItem *item1 = new QGraphicsSimpleTextItem();
    item1->setText(QString(tr("測試")));

    QFont font = item1->font();
    font.setPixelSize(20);
    font.setItalic(true);
    font.setUnderline(true);
    item1->setFont(font);

    item1->setBrush(QBrush(QColor(0, 160, 230)));
    item1->setPos(QPointF(100, 200));

    scene_->addItem(item1);

    /* QGraphicsRectItem reflaction */
    ObjectFactory::registerClass<ElementSetButton>();
    ElementSetButton *object1 = (ElementSetButton*)ObjectFactory::createObject("ElementSetButton", scene_);
    QPen pen3 = object1->pen();
    pen3.setWidth(5);
    pen3.setColor(Qt::white);
    ((QGraphicsRectItem*)object1)->setPen(pen3);
    ((QGraphicsRectItem*)object1)->setBrush(QBrush(QColor(0, 160, 230)));
    object1->setRect(QRect(50, 250, 100, 100));
    object1->setPos(50, 0);
    object1->setObjectName("ElementSetButton_1");
    element_->insert(object1->objectName(), object1);
    scene_->addItem((ElementSetButton*)element_->value("ElementSetButton_1"));


    QObject *object2 = (ElementSetButton*)ObjectFactory::createObject("ElementSetButton");
    int pc = object2->metaObject()->propertyCount();

    /* QGraphicsRectItem */
    QGraphicsRectItem  *item2 = new QGraphicsRectItem();

    QPen pen1 = item2->pen();
    pen1.setWidth(5);
    pen1.setColor(Qt::white);
    item2->setPen(pen1);
    item2->setBrush(QBrush(QColor(0, 160, 230)));

    item2->setRect(QRect(50, 50, 100, 100));
    item2->setPos(50, 0);
    scene_->addItem(item2);    

    /* QGraphicsEllipseItem */
    QGraphicsEllipseItem *item3 = new QGraphicsEllipseItem();

    QPen pen2 = item3->pen();
    pen2.setWidth(5);
    pen2.setColor(Qt::white);

    item3->setPen(pen2);
    item3->setBrush(QBrush(QColor(0, 160, 230)));

    item3->setRect(QRectF(250, 50, 200, 100));
    item3->setStartAngle(16 * 90);
    item3->setSpanAngle(16 * 270);
    scene_->addItem(item3);




}

MainWindow::~MainWindow()
{
    delete ui;
}
