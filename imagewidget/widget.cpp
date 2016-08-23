#include "widget.h"
#include <QMessageBox>
#include <iostream>
#include <QApplication>

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ratio_x = 45./(this->width());
    ratio_y = 20./(this->height());
    setMinimumSize(800,400);
   _image =new QImage();
   if(!(_image->load("F:\\qtwork\\imagewidget\\image\\22.jpg")))
       QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));
    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,QBrush(_image->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
    btn = new QPushButton(QString("关闭"), this);
    btn->setGeometry(this->width()/2, this->height()/2, ratio_x*this->width(), ratio_y*this->height());
    connect(btn, &QPushButton::clicked, &QApplication::quit);
}

Widget::~Widget()
{

}

void Widget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,QBrush(_image->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
    btn->move(this->width()/2, this->height()/2);
    btn->resize(ratio_x*this->width(), ratio_y*this->height());
}
