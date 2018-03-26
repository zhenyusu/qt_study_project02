#include "receivewidget.h"
#include "ui_receivewidget.h"
#include <QHostAddress>
#include <QDebug>
receiveWidget::receiveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::receiveWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("接收端口");
    udpSocket = new QUdpSocket(this);
    //接收数据，套接字需要绑定；发送数据，套接字不需要绑定。
    udpSocket->bind(QHostAddress::LocalHost,9999);
    //一旦接收到数据，槽函数readyRead()就自动触发
    connect(udpSocket,&QUdpSocket::readyRead,this,&receiveWidget::dealMeg);
}

void receiveWidget::dealMeg()
{
    char buf[1024] = {};//消息内容
    QHostAddress senderAdd ;//发送端ip地址
    quint16 senderPort ;//发送端端口号
    int len = udpSocket->readDatagram(buf,sizeof(buf),&senderAdd,&senderPort);
    if(len > 0){
        QString str = QString("[%1:%2]%3").arg(senderAdd.toString()).arg(senderPort).arg(buf);
//        qDebug()<<str;
        ui->textEditRead->setText(str);
    }
}
receiveWidget::~receiveWidget()
{
    delete ui;
}
