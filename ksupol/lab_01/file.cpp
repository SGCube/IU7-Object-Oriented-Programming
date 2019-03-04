#include "file.h"
#include <QString>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <qDebug>

using namespace std;

int file_work(char *name)
{
    ifstream F;
    F.open(name);
    F.close();
    return 0;
}
