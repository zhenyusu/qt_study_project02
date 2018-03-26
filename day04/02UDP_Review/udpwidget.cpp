#include "udpwidget.h"
#include "ui_udpwidget.h"
#include <QHostAddress>
udpwidget::udpwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::udpwidget)
{
    ui->setupUi(this);
    this->setWindowTitle("发送端");
    //分配空间，指定父对象
    udpSocket = new QUdpSocket(this);
    //发送消息
    connect(ui->pushButtonSend,&QPushButton::clicked,this,&udpwidget::sendMeg);
}

void udpwidget::sendMeg(){
    //获取对方的ip地址和端口号
    QHostAddress ip = (QHostAddress)(ui->lineEditIP->text());
    quint16 port = (ui->lineEditPort->text()).toInt();
    //获取编辑区内容
    QString meg = ui->textEditRead->toPlainText();
    //像接收端发送消息
    udpSocket->writeDatagram(meg.toUtf8(),ip,port);
}

udpwidget::~udpwidget()
{
    delete ui;
}
