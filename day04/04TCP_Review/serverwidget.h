#ifndef TCPWIDGET_H
#define TCPWIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QTcpServer>//监听套接字
#include <QTcpSocket>//通信套接字
namespace Ui {
class TcpWidget;
}

class TcpWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TcpWidget(QWidget *parent = 0);
    ~TcpWidget();
    //发送槽函数
    void sendMeg();
    void close();
private:
    Ui::TcpWidget *ui;
    QTcpServer *tcpServer;//监听套接字
    QTcpSocket *tcpSocket;//通信套接字
};

#endif // TCPWIDGET_H
