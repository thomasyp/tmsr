#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget widget;
    widget.setGeometry(100, 100, 400, 400);
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            QPushButton * btn = new QPushButton(QString("(%1,%2)").arg(i).arg(j), &widget);
            btn->setGeometry(i*50, j*50, 45, 45);
        }
    }
    wig
    widget.show();

    return a.exec();
}
