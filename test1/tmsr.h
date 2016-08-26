#ifndef TMSR_H
#define TMSR_H

#include <QWidget>
#include <QPushButton>

class tmsr : public QWidget
{
    Q_OBJECT
public:
    explicit tmsr(QWidget *parent = 0);
    ~tmsr()
    {
        delete _image;
        delete btn;
    }

signals:

public slots:
protected:
    void resizeEvent(QResizeEvent *event);
private:
    QImage *_image;
    QPushButton * btn;
    double ratio_x;
    double ratio_y;
};

#endif // TMSR_H
