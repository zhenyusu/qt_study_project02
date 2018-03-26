#include "udpwidget.h"
#include "receivewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    udpwidget w;
    receiveWidget r;
    w.show();
    r.show();

    return a.exec();
}
