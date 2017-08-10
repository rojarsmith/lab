#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    graphicsView(new QGraphicsView),
    graphicsScene(new QGraphicsScene)

{
    //ui->setupUi(this);
    graphicsView->setScene(graphicsScene);
    setCentralWidget(graphicsView);

    createActions();
}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));

    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    QAction *newLetterAct = new QAction(newIcon, tr("&New Letter"), this);
    newLetterAct->setShortcuts(QKeySequence::New);
    newLetterAct->setStatusTip(tr("Create a new form letter"));
    fileMenu->addAction(newLetterAct);
    fileToolBar->addAction(newLetterAct);
}
