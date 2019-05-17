#ifndef POINT_ARR_H
#define POINT_ARR_H

#include "errors.h"
#include "point.h"
#include "file_work.h"

#include <stdio.h>

#define READ_OK 1
#define WRITE_OK 1

struct pointArrType
{
    pointType* points;
    unsigned int size;
};

error_type pointArrInit(pointArrType &pointArr);

error_type pointArrFree(pointArrType& pointArr);

error_type pointsArrLoad(pointArrType& pointArr, fileWorkType file);

error_type pointsArrSave(fileWorkType file, const pointArrType pointArr);

#endif // POINT_ARR_H

