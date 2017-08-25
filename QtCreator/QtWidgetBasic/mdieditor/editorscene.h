#ifndef EDITORSCENE_H
#define EDITORSCENE_H

#include <QGraphicsScene>

enum ActionType {
    noAction = 0,//No action.
    selectItem
};

class EditorScene : public QGraphicsScene
{    
    Q_OBJECT
public:    
    explicit EditorScene(QObject *parent = 0);
    ~EditorScene();

        ActionType m_ActionType;
private:
    QPointF     previousPoint;
    QGraphicsRectItem *m_dragRect;
    QPointF downPt, movePt;
    void mousePressEvent(QGraphicsSceneMouseEvent * event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
};

#endif // EDITORSCENE_H
