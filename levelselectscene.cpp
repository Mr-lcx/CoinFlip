#include "levelselectscene.h"
#include <QPushButton>
#include <QPainter>
#include <QMenuBar>
#include "mypushbutton.h"
#include "playscene.h"
#include <QSound>

LevelSelectScene::LevelSelectScene(QWidget *parent) :MyMainWindow(parent)

{
    this->setWindowTitle("关卡选择");
    //设置返回按扭
    MyPushButton *btnback =new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png",this);
    btnback->resize(72,32);
    connect(btnback,&QPushButton::clicked,this,&LevelSelectScene::backBtnClicked);
    btnback->move(this->width()-btnback->width(),this->height()-btnback->height());
    //构建关卡按扭
    const int colWidth = 70;
    const int rowHeight = 70;

    //设置偏移量
    const int xOffset = 25;
    const int yOffset = 130;
    for(int i=0;i<20;i++){
        MyPushButton *btn = new MyPushButton(":/res/LevelIcon.png",":/res/LevelIcon.png",this);
        btn->resize(57,57);
        btn->setText(QString::number(i+1));
        int row = i/4;
        int col = i%4;
        int x = col*colWidth + xOffset;
        int y = row*rowHeight + yOffset;
        btn->move(x,y);
        connect(btn,&MyPushButton::clicked,[=](){
           QSound::play(":/res/TapButtonSound.wav");
           PlayScene *playscene = new PlayScene(i+1);

           playscene->setAttribute(Qt::WA_DeleteOnClose);
           this->hide();
           playscene->move(this->pos());
           playscene->show();

           connect(playscene,PlayScene::backBtnClicked,[=](){
               QSound::play(":/res/BackButtonSound.wav");
               this->move(playscene->pos());
               this->show();

               playscene->close();

           });

        });


    }


}

void LevelSelectScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.translate(0,menuBar()->height());
    QPixmap pm(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pm);
    pm.load(":/res/Title.png");
    painter.drawPixmap(0,0,pm);


}
