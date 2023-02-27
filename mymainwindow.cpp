#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    //设置标题
    this->setWindowTitle("硬币翻转");
    //设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置窗口大小
    this->setFixedSize(320,588);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPixmap pm(":/res/MenuSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pm);
}

void MyMainWindow::on_actionquit_triggered()
{
    this->close();
}
