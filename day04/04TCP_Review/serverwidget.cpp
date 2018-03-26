#include "serverwidget.h"
#include "ui_tcpwidget.h"
#include <QHostAddress>
#include <QByteArray>
TcpWidget::TcpWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("服务器：8888");
    //套接字初始化为空
    tcpServer = NULL;
    tcpSocket = NULL;
    //给指针分配空间，指定父类对象，自动回收内存空间。
    tcpServer = new QTcpServer(this);
    //监听绑定
    tcpServer->listen(QHostAddress::Any,8888);
    //如果连接成功，将会触发newConnection()槽函数
    connect(tcpServer,&QTcpServer::newConnection,
            [=](){
        //取出建立好连接的套接字(通信套接字)
        tcpSocket = tcpServer->nextPendingConnection();
        //获取ip,端口号
        QString ip = tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();
        QString temp = QString("[%1,%2]连接成功").arg(ip).arg(port);
        //将客户端ip,端口号显示出来
        ui->textEditRead->setText(temp);
        //数据发送成功，通信套接字自动触发readyRead()函数
        connect(tcpSocket,&QTcpSocket::readyRead,
                [=](){
            //从通信套接字中读取内容
           QByteArray array = tcpSocket->readAll();
           //将内容显示出来
           ui->textEditRead->append(array);
        }
                );
    }
            );
    //发送消息
    connect(ui->pushButtonSend,&QPushButton::clicked,this,&TcpWidget::sendMeg);
    //关闭连接
    connect(ui->pushButtonClose,&QPushButton::clicked,this,&TcpWidget::close);
}

void TcpWidget::sendMeg()
{
    if(tcpSocket == NULL)
    {
        return;
    }
    //从文本框中获取纯文本，就是发送的消息。
    QString meg = ui->textEditWrite->toPlainText();
    tcpSocket->write(meg.toUtf8().data());



}
 void TcpWidget::close()
 {
      if(tcpSocket == NULL)
      {
          return;

      }
      tcpSocket->disconnectFromHost();
      tcpSocket->close();
      tcpSocket == NULL;
 }
TcpWidget::~TcpWidget()
{
    delete ui;
}
