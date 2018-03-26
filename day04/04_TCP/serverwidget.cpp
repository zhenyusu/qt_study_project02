#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QDebug>
#include <QByteArray>
#pragma execution_character_set("utf-8")
ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    tcpServer = NULL;
    tcpSocket = NULL;
    //监听套接字,指定父对象，自动回收空间
    tcpServer = new QTcpServer(this);//指针需要分配空间

    //监听，绑定
    tcpServer->listen(QHostAddress::Any,8888);
    this->setWindowTitle("服务器：8888");
    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
            {
                //取出建立好连接的套接字(通信套接字)
                tcpSocket = tcpServer->nextPendingConnection();
                //获取对方的ip和端口
                QString ip = tcpSocket->peerAddress().toString();
                qint16 port = tcpSocket->peerPort();
                QString temp = QString("[%1,%2]:成功连接").arg(ip).arg(port);
                ui->textEditRead->setText(temp);
                //读取从客户端发送的内容
                connect(tcpSocket,&QTcpSocket::readyRead,
                        [=](){
                              //从通信套接字中读取内容
                              QByteArray array = tcpSocket->readAll();
                              ui->textEditRead->append(array);

                          }
                        );
            }
            );


}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_buttonSend_clicked()
{
    if(tcpSocket == NULL){
        return;
    }

    //获取编辑区内容
    QString str = ui->textEditWrite->toPlainText();
    qDebug()<< str;
    //给对方发送数据，使用套接字tcpSocket
    tcpSocket->write(str.toUtf8().data());


}

void ServerWidget::on_pushButton_2_clicked()
{
    if(tcpSocket == NULL){
        return;
    }

    //主动和客户端口断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = NULL;
}
