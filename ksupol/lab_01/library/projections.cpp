#ifndef PROJECTION_CPP
#define PROJECTION_CPP

#include "projections.h"

int projectionP()
{
    return 0;
}

error_type projectPX(pointType* points, const unsigned int size)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    for (unsigned int i = 0; i < size; i++)
        points[i].x = projectionP();

    return OK;
}

error_type projectPY(pointType* points, const unsigned int size)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    for (unsigned int i = 0; i < size; i++)
        points[i].y = projectionP();

    return OK;
}

error_type projectPZ(pointType* points, const unsigned int size)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    for (unsigned int i = 0; i < size; i++)
        points[i].z = projectionP();

    return OK;
}

double projectCAxis()
{
    return 0;
}

double projectC(const double coord, const double axis, const double distance)
{
    return coord / (axis / distance + 1);
}

error_type projectCX(pointType* points, const unsigned int size, const double d)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        points[i].x = projectC(points[i].x, points[i].z, d);
        points[i].y = projectC(points[i].y, points[i].z, d);
        points[i].z = projectCAxis();
    }

    return OK;
}

error_type projectCY(pointType* points, const unsigned int size, const double d)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        points[i].y = projectC(points[i].y, points[i].x, d);
        points[i].z = projectC(points[i].z, points[i].x, d);
        points[i].x = projectCAxis();
    }

    return OK;
}

error_type projectCZ(pointType* points, const unsigned int size, const double d)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        points[i].z = projectC(points[i].z, points[i].y, d);
        points[i].x = projectC(points[i].x, points[i].y, d);
        points[i].y = projectCAxis();
    }

    return OK;
}

#endif // PARALLPROJECTION_CPP

