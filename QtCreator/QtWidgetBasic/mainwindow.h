#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QMenu;
class QGraphicsView;
class QGraphicsScene;

class MdiEditor;
class ToolBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createActions();

    ToolBox *m_wgtToolBox;
    MdiEditor *m_wgtMdiEditor;

    QGraphicsView *graphicsView;
    QGraphicsScene *graphicsScene;
    //QListWidget *customerList;
    //QListWidget *paragraphsList;
    QMenu *viewMenu;
};

#endif // MAINWINDOW_H
