#ifndef POINT_ARR_CPP
#define POINT_ARR_CPP

#include "point_array.h"

error_type pointArrInit(pointArrType& pointArr)
{
    pointArr.points = NULL;
    pointArr.size = 0;

    return OK;
}

error_type pointArrFree(pointArrType& pointArr)
{
    error_type error = pointsFree(pointArr.points);
    if (error)
        return error;
    error = pointArrInit(pointArr);
    if (error)
        return error;
    return OK;
}

error_type pointsArrLoad(pointArrType& pointArr, fileWorkType file)
{
    error_type error = isCorrectFile(file.f);
    if (error)
        return error;
    error = getSize(pointArr.size, file.f);
    if (error)
        return error;
    error = pointsAllocation(pointArr.points, pointArr.size);
    if (error)
    {
        error = pointArrFree(pointArr);
        return error;
    }

    return pointsLoad(pointArr.points, file, pointArr.size);
}

error_type pointsArrSave(fileWorkType file, const pointArrType pointArr)
{
    error_type error = checkFileForOpen(file.f);
    if (error)
        return error;
    error = checkPointsExist(pointArr.points);
    if (error)
        return error;
    error = setSize(file.f, pointArr.size);
    if (error)
        return error;

    return pointsSave(pointArr.points, file, pointArr.size);
}

#endif // POINT_ARR_CPP

