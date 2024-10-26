#include "Cirrus.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cirrus w;
    w.show();
    return a.exec();
}
