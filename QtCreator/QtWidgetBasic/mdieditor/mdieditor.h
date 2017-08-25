#ifndef MDIEDITOR_H
#define MDIEDITOR_H

#include <QWidget>

namespace Ui {
class MdiEditor;
}

class QGraphicsScene;
class EditorScene;

class MdiEditor : public QWidget
{
    Q_OBJECT

public:
    explicit MdiEditor(QWidget *parent = 0);
    ~MdiEditor();

private:
    Ui::MdiEditor *ui;

    QGraphicsScene *m_GraphicsScene1;
    EditorScene *m_EditorScene;
};

#endif // MDIEDITOR_H
