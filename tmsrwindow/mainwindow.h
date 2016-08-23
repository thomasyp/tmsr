#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void destroyWindow();

protected:
    void resizeEvent(QResizeEvent *event);
private:
    QImage *_image;
    QPushButton * btn;
    double ratio_x;
    double ratio_y;
};

#endif // MAINWINDOW_H
