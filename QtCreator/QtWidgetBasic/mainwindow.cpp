#include "mainwindow.h"
#include "toolbox/toolbox.h"
#include <QtWidgets>
#include <QGraphicsScene>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_wgtToolBox(new ToolBox),
    graphicsView(new QGraphicsView),
    graphicsScene(new QGraphicsScene)
{
    setWindowTitle(tr("Macaca"));
    resize(160*6, 90*6);
    graphicsView->setScene(graphicsScene);
    setCentralWidget(graphicsView);

    QDockWidget *dockProjectManager = new QDockWidget(tr("ProjectManager"), this);
    dockProjectManager->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);
    dockProjectManager->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockProjectManager->setMinimumWidth(150);
    addDockWidget(Qt::LeftDockWidgetArea, dockProjectManager);

    QDockWidget *dockToolBox = new QDockWidget(tr("Toolbox"), this);
    dockToolBox->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);
    dockToolBox->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockToolBox->setMinimumWidth(150);
    dockToolBox->setWidget(m_wgtToolBox);
    addDockWidget(Qt::LeftDockWidgetArea, dockToolBox);

    QDockWidget *dockProperty = new QDockWidget(tr("Property"), this);
    dockProperty->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);
    dockProperty->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockProperty->setMinimumWidth(150);
    addDockWidget(Qt::RightDockWidgetArea, dockProperty);

    QDockWidget *dockPage = new QDockWidget(tr("Page"), this);
    dockPage->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);
    dockPage->setAllowedAreas(Qt::BottomDockWidgetArea);
    dockPage->setMinimumHeight(90);
    addDockWidget(Qt::BottomDockWidgetArea, dockPage);

    QDockWidget *dockConsole = new QDockWidget(tr("Console"), this);
    dockConsole->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);
    dockConsole->setAllowedAreas(Qt::BottomDockWidgetArea);
    dockPage->setMinimumHeight(90);
    addDockWidget(Qt::BottomDockWidgetArea, dockConsole);

    tabifyDockWidget(dockPage, dockConsole);

    statusBar()->showMessage(tr("Test message"));

    createActions();
}

MainWindow::~MainWindow()
{
    if(m_wgtToolBox) delete m_wgtToolBox;
}

void MainWindow::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));

    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    QAction *newLetterAct = new QAction(newIcon, tr("&New Project"), this);
    newLetterAct->setShortcuts(QKeySequence::New);
    newLetterAct->setStatusTip(tr("Create a new project"));
    fileMenu->addAction(newLetterAct);
    fileToolBar->addAction(newLetterAct);
}
