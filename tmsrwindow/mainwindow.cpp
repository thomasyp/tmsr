#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ratio_x = 45./(this->width());
    ratio_y = 25./(this->height());
    setMinimumSize(800,400);
   _image =new QImage();

   if(!(_image->load("F:\\qtwork\\tmsrwindow\\image\\22.jpg")))
       QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));

    setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,QBrush(_image->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
    btn = new QPushButton(QString("关闭"), this);
    btn->setGeometry(this->width()/2, this->height()/2, ratio_x*this->width(), ratio_y*this->height());
    //connect(btn, &QPushButton::clicked, &QApplication::quit);
   connect(btn, &QPushButton::clicked,this,&MainWindow::destroyWindow);

  }

MainWindow::~MainWindow()
{

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,QBrush(_image->scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
    btn->move(this->width()/2, this->height()/2);
    btn->resize(ratio_x*this->width(), ratio_y*this->height());
}

void MainWindow::destroyWindow()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, "quit","quit?",QMessageBox::Yes | QMessageBox::No);


    if (button == QMessageBox::Yes) {
        //this->close();  //接受退出信号，程序退出
        QApplication::quit();
    }
}
