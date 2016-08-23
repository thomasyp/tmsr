#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void resizeEvent(QResizeEvent *event);
private:
    QImage *_image;
    QPushButton * btn;
    double ratio_x;
    double ratio_y;
};

#endif // WIDGET_H
