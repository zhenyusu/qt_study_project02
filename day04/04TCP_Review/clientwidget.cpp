#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>
#include <QByteArray>
#include <QDebug>
ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("客户端");
    tcpSocket = NULL;
    //给指针分配空间，指定父对象自动回收内存空间
    tcpSocket = new QTcpSocket(this);

    //和服务器建立连接
    connect(ui->pushButtonConnect,&QPushButton::clicked,this,&ClientWidget::connectToServer);

    //和服务器成功建立连接，就会自动触发connected()
    connect(tcpSocket,&QTcpSocket::connected,
            [=]()
            {
                ui->textEditRead->setText("成功和服务器建立连接");
             }
            );

    //获取服务器发送的内容
    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
            {
                //获取服务器发送的内容
                QByteArray array = tcpSocket->readAll();
                ui->textEditRead->append(array);
            }
            );

    //发送消息到服务器
    connect(ui->pushButtonSend,&QPushButton::clicked,this,&ClientWidget::sendToServer);

}

//和服务器建立连接
void ClientWidget::connectToServer()
{
    //获取服务端地址和端口
    QHostAddress serverAdd = QHostAddress(ui->lineEditIP->text());
    quint16 port = ui->lineEditPort->text().toInt();
    //和服务器建立连接
    tcpSocket->connectToHost(serverAdd,port);
    qDebug()<<serverAdd;
}

void ClientWidget::sendToServer()
{
    //获取发送内容
   QString meg = ui->textEditWrite->toPlainText();
   tcpSocket->write(meg.toUtf8().data());

}
ClientWidget::~ClientWidget()
{
    delete ui;
}
