#ifndef MODEL_TRANSFORM_CPP
#define MODEL_TRANSFORM_CPP

#include "model_transform.h"

error_type modelShift(pointType *points, const shiftDataType shiftData,
                                                size_t size)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        points[i].x = shift(points[i].x, shiftData.dx);
        points[i].y = shift(points[i].y, shiftData.dy);
        points[i].z = shift(points[i].z, shiftData.dz);
    }

    return OK;
}

error_type modelScale(pointType* points, const scaleDataType scaleData,
                                                size_t size)
{
    error_type error = checkPointsExist(points);
    if (error)
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        points[i].x = scale(points[i].x, scaleData.kx, scaleData.cx);
        points[i].y = scale(points[i].y, scaleData.ky, scaleData.cy);
        points[i].z = scale(points[i].z, scaleData.kz, scaleData.cz);
    }

    return OK;
}

error_type modelTurn(pointType* points, const turnDataType turnData,
                                            size_t size)
{
    error_type error;

    if (turnData.axis == X)
        error = turnX(points, turnData, size);
    else if (turnData.axis == Y)
        error = turnY(points, turnData, size);
    else if (turnData.axis == Z)
        error = turnZ(points, turnData, size);
    else
        error = ErrorField;
    return error;
}

#endif // MODEL_TRANSFORM_CPP

