#include "PL.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PL w;
    w.show();
    return a.exec();
}
