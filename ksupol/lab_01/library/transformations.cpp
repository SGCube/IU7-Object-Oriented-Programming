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

double turnFirstCoord(const tmpTurnDataType data)
{
    return data.c1 + (data.pr1 - data.c1) * cos(data.angle) +
            (data.pr2 - data.c2) * sin(data.angle);
}

double turnSecondCoord(const tmpTurnDataType data)
{
    return data.c2 - (data.pr1 - data.c1) * sin(data.angle) +
            (data.pr2 - data.c2) * cos(data.angle);
}

error_type turnX(nodeType* nodes, const turnDataType turnData, const unsigned int amount)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    tmpTurnDataType tmpData;
    tmpData.angle = degToRad(turnData.angle);
    tmpData.c1 = turnData.cy;
    tmpData.c2 = turnData.cz;

    for (unsigned int i = 0; i < amount; i++)
    {
        tmpData.pr1 = nodes[i].y;
        tmpData.pr2 = nodes[i].z;

        nodes[i].y = turnFirstCoord(tmpData);
        nodes[i].z = turnSecondCoord(tmpData);
    }

    return OK;
}

error_type turnY(nodeType* nodes, const turnDataType turnData, const unsigned int amount)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    tmpTurnDataType tmpData;
    tmpData.angle = degToRad(turnData.angle);
    tmpData.c1 = turnData.cz;
    tmpData.c2 = turnData.cx;

    for (unsigned int i = 0; i < amount; i++)
    {
        tmpData.pr1 = nodes[i].z;
        tmpData.pr2 = nodes[i].x;

        nodes[i].z = turnFirstCoord(tmpData);
        nodes[i].x = turnSecondCoord(tmpData);
    }

    return OK;
}

error_type turnZ(nodeType* nodes, const turnDataType turnData, const unsigned int amount)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    tmpTurnDataType tmpData;
    tmpData.angle = degToRad(turnData.angle);
    tmpData.c1 = turnData.cx;
    tmpData.c2 = turnData.cy;

    for (unsigned int i = 0; i < amount; i++)
    {
        tmpData.pr1 = nodes[i].x;
        tmpData.pr2 = nodes[i].y;

        nodes[i].x = turnFirstCoord(tmpData);
        nodes[i].y = turnSecondCoord(tmpData);
    }

    return OK;
}

#endif // TRANSFORMATIONS_CPP

