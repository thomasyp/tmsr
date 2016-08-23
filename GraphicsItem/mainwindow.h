#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenuBar>
#include <QGraphicsEllipseItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget * parent = 0);
    ~MainWindow();

    void initScene();
    void createActions();
    void createMenus();

public slots:
    void slotNew();
    void slotClear();

    void slotAddEllipseItem();
    void slotAddPolygonItem();
    void slotAddTextItem();
    void slotAddRectItem();
    void slotAddAlphaItem();

private:
    QGraphicsScene * scene;
    QAction * newAct;
    QAction * clearAct;
    QAction * exitAct;
    QAction * addEllipseItemAct;
    QAction * addPolygonItemAct;
    QAction * addTextItemAct;
    QAction * addRectItemAct;
    QAction * addAlphaItemAct;
};
#endif // MAINWINDOW_H
