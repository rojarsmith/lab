#ifndef PAINTFRAME_H
#define PAINTFRAME_H

#include <QWidget>

class QTimer;
class QGraphicsView;
class PaintScene;

class PaintFrame : public QWidget
{
    Q_OBJECT
public:
    PaintFrame(QWidget *parent = 0);
    ~PaintFrame();
private:
    QTimer *timer; //定義一個定時器 的 實際尺寸 的 準備 圖形場景
    QGraphicsView *m_QGraphicsView;
    PaintScene *scene;  // 宣告自定義圖形場景

private:
    /* 覆蓋resize事件重新計算圖形場景的大小
     * */
    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();
};

#endif // PAINTFRAME_H
