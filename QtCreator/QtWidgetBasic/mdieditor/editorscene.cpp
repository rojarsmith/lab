#include "editorscene.h"
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

EditorScene::EditorScene(QObject *parent)
    : QGraphicsScene(parent)
{
    m_dragRect = new QGraphicsRectItem(0);
    this->addItem(m_dragRect);
    m_dragRect->setPos(0, 0);
    m_dragRect->setVisible(false);
    m_dragRect->setBrush(QBrush(QColor(30,144,255,24)));
    m_dragRect->setPen(QPen(Qt::gray, 1, Qt::DashLine, Qt::FlatCap, Qt::MiterJoin));

    addLine(0, 100, 399, 100);
    addLine(200, 0, 200, 199);
}

EditorScene::~EditorScene()
{

}

void EditorScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    downPt = event->scenePos();

    if (!event->isAccepted()){
        //No Element selected, do rectangle selection.
        m_dragRect->setRect(QRectF(downPt, downPt));
        m_dragRect->setVisible(true);
        m_ActionType = selectItem;
    }
}

void EditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    movePt = event->scenePos();
    switch (m_ActionType) {
//    case noAction:
//        QGraphicsScene::mouseMoveEvent(mouseEvent);
//        return;
//        break;
    case selectItem:
        //框選
        if(movePt.x() < -150)
        {
            int aaa = 0;
        }

        m_dragRect->setRect(QRectF(downPt, movePt).normalized());
        break;
    default:
        break;
    }
}

void EditorScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
    switch (m_ActionType) {
    case noAction:

        break;
    case selectItem:
        //框選對象
        m_dragRect->setVisible(false);
        break;
    default:
        break;
    }
}
