#ifndef DISPLAY_WORK_CPP
#define DISPLAY_WORK_CPP

#include "display_work.h"

double getX(double x, double z)
{
    return x + z * Z_COEFF;
}

double getY(double y, double z)
{
    return -y - z * Z_COEFF;
}

#endif // DISPLAYWORK_CPP

