#include "timewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimeWidget w;
    w.show();

    return a.exec();
}
