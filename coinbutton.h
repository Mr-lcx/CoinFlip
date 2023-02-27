#ifndef COINBUTTON_H
#define COINBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>

class CoinButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CoinButton(QWidget *parent = nullptr);

    int stat() const;
    void setStat(int stat);
    void flip();
     //设置状态，同时播放动画
    void setStatWithAnimation(int stat);

signals:
private:
    void paintEvent(QPaintEvent *ev);
    int mStat;
     //存储当前动画帧序号
    int mFrameNo;
    //定时器切换图片的定时器
    QTimer *mTimer;

public slots:
};

#endif // COINBUTTON_H
