#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <Qpainter>

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
public:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_actionquit_triggered();

private:
    Ui::MyMainWindow *ui;
};

#endif // MYMAINWINDOW_H
