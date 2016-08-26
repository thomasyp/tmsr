#include "mainwindow.h"
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(400, 300);
    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));

    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    widget1 = new tmsr(centralWidget);
    widget1->setObjectName(QStringLiteral("widget1"));
    //lineEdit = new QLineEdit(widget1);
    //lineEdit->setObjectName(QStringLiteral("lineEdit"));
    //lineEdit->setGeometry(QRect(30, 20, 113, 20));

    verticalLayout->addWidget(widget1);
    widget_2 = new QWidget(centralWidget);
    widget_2->setObjectName(QStringLiteral("widget_2"));
    widget_2->setMinimumSize(800,400);
    lineEdit_2 = new QLineEdit(widget_2);
    lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
    lineEdit_2->setGeometry(QRect(30, 40, 113, 20));

    verticalLayout->addWidget(widget_2);
    gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);
    this->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(this);
    menuBar->setObjectName(QStringLiteral("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 400, 23));
    this->setMenuBar(menuBar);
    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
    this->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(this);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    this->setStatusBar(statusBar);



}

MainWindow::~MainWindow()
{

}
