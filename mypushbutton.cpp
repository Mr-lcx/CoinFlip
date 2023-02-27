#include "mypushbutton.h"
#include <QPainter>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString normalImg,QString pressImg,QWidget *parent)
    : QPushButton(parent)
    ,mNormalImg(normalImg)
    ,mPressImg(pressImg)
{
    mStat= Normal;
}

void MyPushButton::moveUp()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animation->setDuration(100);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::moveDown()
{
    //位置大小属性发生变化
    //给定开始位置
    //给定结束位置
    //给定速度，给定动画时长
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setDuration(100);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);

    QPixmap pix;
    if(mStat==Normal){
         pix.load(mNormalImg);
    }
    if(mStat==Pressed){
         pix.load(mPressImg);
    }


    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //绘制文字
    painter.drawText(0,0,this->width(),this->height(),Qt::AlignHCenter|Qt::AlignVCenter,this->text());
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    this->mStat= Pressed;
    update();
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    this->mStat= Normal;
    update();
    QPushButton::mouseReleaseEvent(e);
}

