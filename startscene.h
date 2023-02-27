#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QMainWindow>
#include "mymainwindow.h"
#include "levelselectscene.h"
class StartScene : public MyMainWindow
{
    Q_OBJECT
public:
    explicit StartScene(QWidget *parent = nullptr);
protected:



signals:

public slots:

public:
    LevelSelectScene levelselect;
};

#endif // STARTSCENE_H
