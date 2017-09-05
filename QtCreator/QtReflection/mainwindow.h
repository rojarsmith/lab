#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHash>
#include <QMainWindow>

class DiagramScene;
class ElementAbstraction;
class ObjectFactory;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum ElementMode { NONE, BOX, ELLIPSE, TEXT };

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    ElementMode mode_;
    QMenu *itemMenu_;
    DiagramScene *scene_;
    ObjectFactory *factory_;
    QHash<QString, ElementAbstraction *> *element_;
};

#endif // MAINWINDOW_H
