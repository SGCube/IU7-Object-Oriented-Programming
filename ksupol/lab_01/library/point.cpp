#ifndef POINT_CPP
#define POINT_CPP

#include "point.h"

bool pointsIsExist(const pointType* points)
{
    if (points)
        return true;
    return false;
}

error_type checkPointsExist(const pointType* points)
{
    if (pointsIsExist(points))
        return OK;
    return ErrorPointsExist;
}

error_type pointsAllocation(pointType*& points, const unsigned int size)
{
    if (points != NULL && pointsFree(points))
        return ErrorFree;

    points = new pointType[size];
    if (pointsIsExist(points))
        return OK;
    return ErrorAllocation;
}

error_type pointsFree(pointType*& points)
{
    if (pointsIsExist(points))
        delete [] points;

    return OK;
}

error_type pointLoad(double& pointX, double& pointY, double& pointZ, fileWorkType file)
{
    error_type error = getPointData(pointX, file.f);
    if (error)
        return error;

    error = getPointData(pointY, file.f);
    if (error)
        return error;

    return getPointData(pointZ, file.f);
}

error_type pointSave(FILE* f, const double pointX, const double pointY, const double pointZ)
{
    error_type error = setPointData(f, pointX);
    if (error)
        return error;

    error = setPointData(f, pointY);
    if (error)
        return error;

    return setPointData(f, pointZ);
}

error_type pointsLoad(pointType* points, fileWorkType file, const unsigned int size)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    for (unsigned int i = 0; i < size && error == OK; i++)
        error = pointLoad(points[i].x, points[i].y, points[i].z, file);

    return error;
}

error_type pointsSave(const pointType* points, fileWorkType file, const unsigned int size)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    for (unsigned int i = 0; i < size && error == OK; i++)
        error = pointSave(file.f, points[i].x, points[i].y, points[i].z);

    return error;
}

#endif // POINT_CPP

