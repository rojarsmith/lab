#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>

class PaintScene : public QGraphicsScene
{
public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();
};

#endif // PAINTSCENE_H
