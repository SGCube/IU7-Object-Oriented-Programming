#ifndef DISPLAY_CPP
#define DISPLAY_CPP

#include "display.h"
#include "point.h"
#include "edge.h"

error_type getCoordForDrawLine(pointType* points, int src, int purp)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    const double xSrc = getX(points[src].x, points[src].z);
    const double ySrc = getY(points[src].y, points[src].z);
    const double xPurp = getX(points[purp].x, points[purp].z);
    const double yPurp = getY(points[purp].y, points[purp].z);

    error = drawLine(xSrc, ySrc, xPurp, yPurp);

    return error;
}

error_type drawDisplay(type_edge *edges, pointType* points,
                                               size_t size)
{
    error_type error = checkEdgesExist(edges);
    if (error)
        return error;

    int src;
    int purp;

    for (unsigned int i = 0; i < size && error == OK; i++)
    {
        src = edges[i].src;
        purp = edges[i].purp;
        error = getCoordForDrawLine(points, src, purp);
    }

    return error;
}

#endif // DISPLAY_CPP

