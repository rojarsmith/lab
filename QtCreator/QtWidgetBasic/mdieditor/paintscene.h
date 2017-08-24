#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

private:
    QPointF previousPoint;      // The coordinates of the previous point
    void mousePressEvent(QGraphicsSceneMouseEvent * event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // PAINTSCENE_H
