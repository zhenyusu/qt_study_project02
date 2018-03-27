#ifndef MYWIDGET_H
#define MYWIDGET_H
#include "mythread.h"
#include <QWidget>
#include <QTimer>//定时器头文件
namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    void dealTimeout();//定时器槽函数
    void dealDone();//线程槽函数
    void stopThread();//停止线程
    ~MyWidget();


private slots:
    void on_pushButton_clicked();

private:
    Ui::MyWidget *ui;
    QTimer *myTimer;//声明变量
    MyThread *thread;//线程对象
};

#endif // MYWIDGET_H
