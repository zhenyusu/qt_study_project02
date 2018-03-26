#include "udpwidget.h"
#include "ui_udpwidget.h"
#include <QHostAddress>
UdpWidget::UdpWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UdpWidget)
{
    ui->setupUi(this);
    //分配空间，指定父对象，自动回收
    udpSocket = new QUdpSocket(this);
    //绑定
   // udpSocket->bind(8888);组播绑定不能这么绑定
    udpSocket->bind(QHostAddress::AnyIPv4,8888);
    //加入某个组播
    //组播地址是D类地址
    udpSocket->joinMulticastGroup(QHostAddress("224.0.0.2"));
    udpSocket->leaveMulticastGroup(QHostAddress("224.0.0.2"));//退出组播
    setWindowTitle("服务器端口为8888");
    //当对方成功发送数据过来，就自动触发readyRead()方法
    connect(udpSocket,&QUdpSocket::readyRead,this,&UdpWidget::dealMsg);

}

UdpWidget::~UdpWidget()
{
    delete ui;
}

void UdpWidget::dealMsg(){
    //读取对方发送的内容
    char buf[1024] = {0};
    QHostAddress cliAddr;//对方地址
    quint16 port;//对方端口
    qint64 len = udpSocket->readDatagram(buf,sizeof(buf),&cliAddr,&port);
    if(len > 0){
        //格式化
        QString str = QString("[%1:%2]%3").arg(cliAddr.toString()).arg(port).arg(buf);
    }
}

//发送按钮
void UdpWidget::on_pushButtonSend_clicked()
{
    //先获取对方的IP和端口
    QString ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();

    //获取编辑区内容
    QString str = ui->textEdit->toPlainText();
    //给指定的IP发送数据
    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);

}
