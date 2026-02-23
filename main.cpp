#include "proceedwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Proceedwindow w;
    w.show();
    return a.exec();
}
