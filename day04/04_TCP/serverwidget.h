#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>
//加载头文件
#include <QTcpServer>//监听套接字
#include <QTcpSocket>//通信套接字
namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();

private slots:
    void on_buttonSend_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ServerWidget *ui;
    QTcpServer *tcpServer;//监听套接字
    QTcpSocket *tcpSocket;//通信套接字
};

#endif // SERVERWIDGET_H
