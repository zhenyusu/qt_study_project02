#include "serverwidget.h"
#include <QApplication>
#include <clientwidget.h>
#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerWidget w;
    w.show();
    ClientWidget client;
    client.show();

    return a.exec();
}
