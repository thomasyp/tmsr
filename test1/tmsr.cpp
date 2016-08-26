#include "tmsr.h"
#include <QApplication>
#include <QMessageBox>

tmsr::tmsr(QWidget *parent) : QWidget(parent)
{
    ratio_x = 6./(this->width());
    ratio_y = 2./(this->height());
    setMinimumSize(800,400);
   _image =new QImage();
//   this->setObjectName(QStringLiteral("widget1"));
//   lineEdit = new QLineEdit(this);
//   lineEdit->setObjectName(QStringLiteral("lineEdit"));
//   lineEdit->setGeometry(QRect(30, 20, 113, 20));

   if(!(_image->load("F:\\qtwork\\tmsrwindow\\image\\22.jpg")))
       QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));

    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,QBrush(_image->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
    btn = new QPushButton(QString("关闭"), this);
    btn->setGeometry(this->width()/2, this->height()/2, ratio_x*this->width(), ratio_y*this->height());
    //connect(btn, &QPushButton::clicked, &QApplication::quit);
   //connect(btn, &QPushButton::clicked,this,&MainWindow::destroyWindow);
}

void tmsr::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,QBrush(_image->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
    btn->move(this->width()/2, this->height()/2);
    btn->resize(ratio_x*this->width(), ratio_y*this->height());
}
