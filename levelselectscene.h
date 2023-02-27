#ifndef LEVELSELECTSCENE_H
#define LEVELSELECTSCENE_H

#include <QMainWindow>
#include "mymainwindow.h"
#include <QPaintEvent>
class LevelSelectScene : public MyMainWindow
{
    Q_OBJECT
public:
    explicit LevelSelectScene(QWidget *parent = nullptr);

signals:
   void backBtnClicked();
protected:
    void paintEvent(QPaintEvent *event);

public slots:
};

#endif // LEVELSELECTSCENE_H
