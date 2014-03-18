#include "testwidget.h"
#include <QApplication>
#include "mosquittopp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testWidget w;
    w.show();

    return a.exec();
}
