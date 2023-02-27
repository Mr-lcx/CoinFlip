#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    enum MyPushButtonStat{
        Normal,
        Pressed
    };
    explicit MyPushButton(QString normalImg,QString pressdImg,QWidget *parent = nullptr);
    void moveUp();
    void moveDown();
protected:
    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QString mNormalImg;
    QString mPressImg;
    MyPushButtonStat mStat;
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
