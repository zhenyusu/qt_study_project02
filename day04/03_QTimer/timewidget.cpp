#include "timewidget.h"
#include "ui_timewidget.h"

TimeWidget::TimeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeWidget)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    connect(myTimer,&QTimer::timeout,
            [=](){
                static int i = 0;
                i++;
                ui->lcdNumber->display(i);
            }
            );
}

TimeWidget::~TimeWidget()
{
    delete ui;
}

void TimeWidget::on_pushButtonStart_clicked()
{
    //启动定时器
    //时间间隔为100ms
    //每隔100ms，定时器myTimer自动触发timeout()
    if(myTimer->isActive() == false){
        myTimer->start(100);//如果定时器没有激活才启动
    }

}

void TimeWidget::on_pushButtonStop_clicked()
{
    if(myTimer->isActive() == true){
        myTimer->stop();
    }

}
