#include "startscene.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QTimer>
#include <QSound>


StartScene::StartScene(QWidget *parent) : MyMainWindow(parent)
{

    this->setWindowTitle("开始场景");
    MyPushButton* startbtn = new MyPushButton(":/res/MenuSceneStartButton.png",":/res/MenuSceneStartButton.png",this);
//    startbtn->setFixedSize(114,114);
    startbtn->resize(114,114);
    startbtn->move((this->width()-startbtn->width())/2,this->height()*3/4-startbtn->height()/2);
    connect(&this->levelselect,&LevelSelectScene::backBtnClicked,[=](){
        QSound::play(":/res/BackButtonSound.wav");
        levelselect.hide();
        this->show();
        this->move(levelselect.pos());

    });

    connect(startbtn,&MyPushButton::clicked,[=](){
        //添加点击音效
        QSound::play(":/res/TapButtonSound.wav");
        startbtn->setEnabled(false);
        //播放向下动画
       startbtn->moveDown();
       QTimer::singleShot(150,[=](){

           startbtn->moveUp();


       });

       QTimer::singleShot(300,[=](){

           startbtn->setEnabled(true);
           this->hide();
           levelselect.move(this->pos());
           this->levelselect.show();

       });


    });


}

