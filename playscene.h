#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mymainwindow.h"
#include <QPainter>
#include "coinbutton.h"


class PlayScene : public MyMainWindow
{
    Q_OBJECT
public:
    PlayScene(int level,QWidget *parent = nullptr);
    void flipCoin(int row ,int col);
    void judgeWin();

signals:
    backBtnClicked();
private:
    void paintEvent(QPaintEvent *ev);
    //胜利的状态
    bool mHasWin;
    //硬币按钮数组
    CoinButton *mCoins[4][4];

public slots:
};

#endif // PLAYSCENE_H
