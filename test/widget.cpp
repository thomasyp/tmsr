#include "widget.h"
#include <QPushButton>
#include "iostream"
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(100, 100, 200, 200);
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            QPushButton * btn = new QPushButton(QString("(%1,%2)").arg(i).arg(j), this);
            btn->setGeometry(i*50, j*50, 45, 45);
        }
    }
}

Widget::~Widget()
{

}

void Widget::resizeEvent(QResizeEvent *re)
{
   QWidget::resizeEvent(re);
}
