#include "mymainwindow.h"
#include <QApplication>
#include "startscene.h"
#include "levelselectscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MyMainWindow w;
//    w.show();
    //开始场景
    StartScene sc;
    sc.show();
    //关卡选择场景
//    LevelSelectScene level;
//    level.show();




    return a.exec();
}








