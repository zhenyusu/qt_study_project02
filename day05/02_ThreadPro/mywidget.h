#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>
namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();

    void dealSignal();
    void dealClose();

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButton_2_clicked();

signals:
    void startThread();//启动子线程的信号
private:
    Ui::myWidget *ui;
    MyThread *myT;
    QThread *thread;
};

#endif // MYWIDGET_H
