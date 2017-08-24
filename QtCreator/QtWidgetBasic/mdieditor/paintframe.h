#ifndef PAINTFRAME_H
#define PAINTFRAME_H

#include <QWidget>

class QTimer;
class QGridLayout;
class QGraphicsView;
class PaintScene;

class PaintFrame : public QWidget
{
    Q_OBJECT
public:
    PaintFrame(QWidget *parent = 0);
    ~PaintFrame();
private:
    QTimer *timer; // Define the timer for the preparation of the actual size of the graphic scenes
    PaintScene *scene;  // We declare a custom graphic scene
    QGridLayout *m_gridLayout;
    QGraphicsView *m_graphicsView;
private:
    /* Override event resize the window to recalculate the size of the graphic scenes
     * */
    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();
};

#endif // PAINTFRAME_H
