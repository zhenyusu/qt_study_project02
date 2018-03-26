#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>//通信套接字
namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();
    //槽函数,和客户端建立连接
    void connectToServer();
    //发送信息到客户端
    void sendToServer();

private:
    Ui::ClientWidget *ui;
    //通信套接字
    QTcpSocket *tcpSocket;
};

#endif // CLIENTWIDGET_H
