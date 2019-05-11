#ifndef TRANSFORMATIONS_CPP
#define TRANSFORMATIONS_CPP

#include "transformations.h"

double shift(const double coord, const double offset)
{
    return coord + offset;
}

double scale(const double coord, const double coeff, const double center)
{
    return center + coeff * (coord - center);
}

double degToRad(const int angle)
{
    return angle * M_PI / 180;
}

//error_type turnPoint(int )

double turnFirstCoord(tmpTurnDataType data)
{
    return data.c1 + (data.pr1 - data.c1) * cos(data.angle) +
            (data.pr2 - data.c2) * sin(data.angle);
}

double turnSecondCoord(tmpTurnDataType data)
{
    return data.c2 - (data.pr1 - data.c1) * sin(data.angle) +
            (data.pr2 - data.c2) * cos(data.angle);
}

void turnPoint(double *a, double *b, pointType center, double angle)
{
    *a = center.x + (*a - center.x) * cos(angle) +
            (center.y - *b) * sin(angle);
    *b = center.y - (*a  - center.x) * sin(angle) +
            (*b - center.y) * cos(angle);
}

error_type turnX(pointType *points, const turnDataType turnData, const unsigned int amount)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    pointType center = {turnData.cy, turnData.cz, 0};

    for(size_t i = 0; i < amount; i++)
        turnPoint(&points[i].y, &points[i].z, center, degToRad(turnData.angle));

    /*
    tmpTurnDataType tmpData;
    tmpData.angle = degToRad(turnData.angle);
    tmpData.c1 = turnData.cy;
    tmpData.c2 = turnData.cz;

    for (unsigned int i = 0; i < amount; i++)
    {
        tmpData.pr1 = points[i].y;
        tmpData.pr2 = points[i].z;

        points[i].y = turnFirstCoord(tmpData);
        points[i].z = turnSecondCoord(tmpData);
    }
    */

    return OK;
}

error_type turnY(pointType* points, const turnDataType turnData, const unsigned int amount)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    pointType center = {turnData.cx, turnData.cz, 0};

    for(size_t i = 0; i < amount; i++)
        turnPoint(&points[i].y, &points[i].z, center, degToRad(turnData.angle));

    return OK;
}

error_type turnZ(pointType* points, const turnDataType turnData, const unsigned int amount)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    pointType center = {turnData.cx, turnData.cy, 0};

    for(size_t i = 0; i < amount; i++)
        turnPoint(&points[i].y, &points[i].z, center, degToRad(turnData.angle));

    return OK;
}

#endif // TRANSFORMATIONS_CPP

