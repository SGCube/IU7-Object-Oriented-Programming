#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "errors.h"
#include "point.h"
#include "model_data_work.h"

#include <math.h>

struct tmpTurnDataType
{
    double pr1, pr2;
    double c1, c2;
    double angle;
};

// изменение координат для переноса
double shift(const double coord, const double offset);

// изменение координат для масштабирования
double scale(const double coord, const double coeff, const double center);

// перевод из градусов в радианы
double degToRad(const int angle);

// поворот первой координаты
double turnFirstCoord(tmpTurnDataType data);

// поворот второй координаты
double turnSecondCoord(tmpTurnDataType data);

// повернуть модель по оси X
error_type turnX(pointType* points, const turnDataType turnData, const unsigned int amount);

// повернуть модель по оси Y
error_type turnY(pointType* points, const turnDataType turnData, const unsigned int amount);

// повернуть модель по оси Z
error_type turnZ(pointType* points, const turnDataType turnData, const unsigned int amount);

void turnPoint(double *a, double *b, pointType center, double angle);

#endif // TRANSFORMATIONS_H

