#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QWidget>
#include <QTimer>//创建定时器对象
namespace Ui {
class TimeWidget;
}

class TimeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimeWidget(QWidget *parent = 0);
    ~TimeWidget();

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

private:
    Ui::TimeWidget *ui;
    QTimer *myTimer;//定时器对象
};

#endif // TIMEWIDGET_H
