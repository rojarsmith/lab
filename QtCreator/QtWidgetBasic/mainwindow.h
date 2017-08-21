#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QGraphicsView;
class QGraphicsScene;
QT_END_NAMESPACE

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

    QGraphicsView *graphicsView;
    QGraphicsScene *graphicsScene;
    //QListWidget *customerList;
    //QListWidget *paragraphsList;
    QMenu *viewMenu;
};

#endif // MAINWINDOW_H
