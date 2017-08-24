#ifndef EDITORSCENE_H
#define EDITORSCENE_H

#include <QGraphicsScene>

class EditorScene : public QGraphicsScene
{    
    Q_OBJECT
public:
    explicit EditorScene(QObject *parent = 0);
    ~EditorScene();
private:
    QPointF     previousPoint;
    //void mousePressEvent(QGraphicsSceneMouseEvent * event) Q_DECL_OVERRIDE;
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // EDITORSCENE_H
