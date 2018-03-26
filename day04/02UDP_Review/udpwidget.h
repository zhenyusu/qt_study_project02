#ifndef UDPWIDGET_H
#define UDPWIDGET_H

#include <QWidget>
#include <QUdpSocket>//UDP套接字

namespace Ui {
class udpwidget;
}

class udpwidget : public QWidget
{
    Q_OBJECT

public:
    explicit udpwidget(QWidget *parent = 0);
    void sendMeg();
    ~udpwidget();

private:
    Ui::udpwidget *ui;
    QUdpSocket *udpSocket;//UDP套接字
};

#endif // UDPWIDGET_H
