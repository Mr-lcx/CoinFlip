#include "coinbutton.h"
#include <QPainter>

CoinButton::CoinButton(QWidget *parent) : QPushButton(parent)
{
    this->setStat(1);
    setStyleSheet("QPushButton{border:None;}");
    mTimer = new QTimer(this);
    connect(mTimer,&QTimer::timeout,[=](){
        if(mStat)
        {

            --mFrameNo;

        }else
        {
            ++mFrameNo;

        }
        if(mFrameNo==1||mFrameNo==8){
            mTimer->stop();
        }
        QString iconName = QString  (":/res/Coin000%1.png").arg(mFrameNo);
        setIcon(QIcon(iconName));
    });

}

void CoinButton::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPixmap pix(":/res/BoardNode.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    QPushButton::paintEvent(ev);
}

int CoinButton::stat() const
{
    return mStat;
}

void CoinButton::setStat(int stat)
{
    mStat = stat;
    if (mStat ==1)
    {
        setIcon(QIcon(":/res/Coin0001.png"));

    }else
    {
        setIcon(QIcon(":/res/Coin0008.png"));
    }
    //设置icon大小为按钮大小
    setIconSize(QSize(50,50));


}

void CoinButton::flip()
{
//    this->setStat(!this->stat());
    this->setStatWithAnimation(!this->stat());

}

void CoinButton::setStatWithAnimation(int stat)
{
    mStat = stat;
    if(mStat)
    {
        //如果刚才设定的状态是1
        //表示要反转到金币
        //所以应该是银币反转到金币的过程开始
        //帧序号从8开始递减到1
        this->mFrameNo =8;


    }else
    {
        //如果刚才设定的状态是0
        //表示要反转到银币
        //所以应该是金币反转到银币的过程开始
        //帧序号从1开始递增到8
        this->mFrameNo = 1;

    }
    this->mTimer->start(30);



}
