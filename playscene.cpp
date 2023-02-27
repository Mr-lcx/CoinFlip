#include "playscene.h"
#include "mypushbutton.h"
#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include <QPropertyAnimation>
#include <QSound>
#include <levelselectscene.h>
#include "dataconfig.h"

PlayScene::PlayScene(int level,QWidget *parent) : MyMainWindow(parent)
{

    //设置返回按扭
    MyPushButton *btnback =new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png",this);
    btnback->resize(72,32);
    connect(btnback,&MyPushButton::clicked,this,&PlayScene::backBtnClicked);
    btnback->move(this->width()-btnback->width(),this->height()-btnback->height());

    //设置等级显示
    QLabel *label = new QLabel(this);
    QString str = QString("Level: %1").arg(level);
    label->setText(str);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    label->setGeometry(QRect(30,this->height()-50,150,50));
    //设置胜利状态
    mHasWin=false;

    //构建游戏金币按钮
    //行数、列数
    const int rowCount = 4;
    const int columnCount = 4;
    //行高、列宽
    const int rowHeight = 50;
    const int columnWidth = 50;
    //x、y偏移量
    const int xOffset = 57;
    const int yOffset = 200;
    //每个按钮宽、高
    const int coinWidth = 50;
    const int coinHeight = 50;


    //取出第几关的二位数组数据
    dataConfig data;
    QVector <QVector <int > > dataArray = data.mData[level];

    for(int row=0;row<rowCount;row++)
        for(int col=0;col<columnCount;col++)
        {
            int x = col*columnWidth +xOffset;
            int y = row*rowHeight +yOffset;
          mCoins[row][col] = new CoinButton(this);
          mCoins[row][col]->setGeometry(x,y,coinWidth,coinHeight);
          mCoins[row][col]->setStat(dataArray[row][col]);


          connect(mCoins[row][col],&CoinButton::clicked,[=](){
              this->flipCoin(row,col);
          });
        }




}

void PlayScene::flipCoin(int row, int col)
{
    if(mHasWin)
        return;
    //翻动row行col列的按钮
    this->mCoins[row][col]->flip();
    //翻金币的音效
    QSound::play(":/res/ConFlipSound.wav");

    //延时翻动上下左右4个硬币
    QTimer::singleShot(300,[=](){
        //翻上面
        if(row-1>0)
        {
            this->mCoins[row-1][col]->flip();
        }
        //翻下面
        if(row+1<4)
        {
            this->mCoins[row+1][col]->flip();
        }
        //翻左边
        if(col-1>0){
            this->mCoins[row][col-1]->flip();
        }
        //翻右边
        if(col+1<4){
            this->mCoins[row][col+1]->flip();
        }
        for(int row=0;row<4;row++){
            for(int col=0;col<4;col++){
               qDebug()<<(mCoins[row][col]->stat());

            }
        }
        //    //判断是否胜利
            this->judgeWin();
    });

qDebug()<<"####################################";
    for(int row=0;row<4;row++){
        for(int col=0;col<4;col++){
           qDebug()<<(mCoins[row][col]->stat());

        }
    }


//判断放外面会有问题，只能放里面,因为QTimer::singleShot是一个非阻塞的函数，放到外面判断的数据是还没有被翻转的数据
//    //判断是否胜利
//    this->judgeWin();
}

void PlayScene::judgeWin()
{
    for(int row=0;row<4;row++){
        for(int col=0;col<4;col++){
            if(mCoins[row][col]->stat()==0)
            {
                return;
            }

        }
    }
    mHasWin = true;
//    QMessageBox::information(this,"恭喜","你已经成功了！");


    //开始时，图片在窗口上方隐藏
    QLabel *winLabel = new QLabel(this);
    QPixmap pix;
    pix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->resize(pix.width(),pix.height());
    winLabel->setPixmap(pix);
    winLabel->move((this->width()-winLabel->width())*0.5,-winLabel->height());
    winLabel->show();

    //播放胜利音效
    QSound::play(":/res/LevelWinSound.wav");
    //播放动画
    QPropertyAnimation *animation = new QPropertyAnimation(winLabel,"geometry");
    animation->setStartValue(winLabel->geometry());
    animation->setDuration(1000);
    animation->setEndValue(QRect(winLabel->x(),winLabel->y()+150,winLabel->width(),winLabel->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start(QPropertyAnimation::DeleteWhenStopped);


}

void PlayScene::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPixmap pix(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap(0,0,pix.width()*0.5,pix.height()*0.5,pix);


}
