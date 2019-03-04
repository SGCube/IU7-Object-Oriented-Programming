#include "windows.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    windows w;
    w.show();

    return a.exec();
}
