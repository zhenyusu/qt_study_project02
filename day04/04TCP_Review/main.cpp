#include "serverwidget.h"
#include "clientwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpWidget w;
    ClientWidget client;
    w.show();
    client.show();

    return a.exec();
}
