#ifndef CANVASCOORD_H
#define CANVASCOORD_H

#define Z_COEEF 0.5

#include "canvascoord.h"

double getCanvasX(double x, double z)
{
    return x + z * Z_COEFF;
}

double getCanvasY(double y, double z)
{
    return -y - z * Z_COEFF;
}

#endif // CANVASCOORD_H
