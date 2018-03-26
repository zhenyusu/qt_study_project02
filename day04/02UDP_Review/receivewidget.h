#ifndef RECEIVEWIDGET_H
#define RECEIVEWIDGET_H

#include <QWidget>
#include <QUdpSocket>
namespace Ui {
class receiveWidget;
}

class receiveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit receiveWidget(QWidget *parent = 0);
    void dealMeg();//处理数据的槽函数
    ~receiveWidget();


private:
    Ui::receiveWidget *ui;
    QUdpSocket *udpSocket;//通信套接字
};

#endif // RECEIVEWIDGET_H
