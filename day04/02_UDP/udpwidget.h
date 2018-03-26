#ifndef UDPWIDGET_H
#define UDPWIDGET_H

#include <QWidget>
#include <QUdpSocket>//UDP套接字

namespace Ui {
class UdpWidget;
}

class UdpWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UdpWidget(QWidget *parent = 0);
    ~UdpWidget();

    //槽函数
    void dealMsg();//处理对方发送过来的数据

private slots:
    void on_pushButtonSend_clicked();

private:
    Ui::UdpWidget *ui;
    QUdpSocket * udpSocket;
};

#endif // UDPWIDGET_H
