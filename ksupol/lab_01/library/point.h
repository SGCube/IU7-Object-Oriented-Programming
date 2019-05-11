#ifndef POINT_H
#define POINT_H

#include "errors.h"
#include "file_work.h"

#include <stdio.h>

struct pointType
{
    double x;
    double y;
    double z;
};

enum pointFieldType
{
    fieldX,
    fieldY,
    fieldZ
};

bool pointsIsExist(const pointType *points);

// проверка на существование
error_type checkPointsExist(const pointType* points);

// выделение памяти для массива точек
error_type pointsAllocation(pointType*& points, const unsigned int size);

// освобождение памяти из-под массива точек
error_type pointsFree(pointType*& points);

// загрузка точек
error_type pointLoad(double &pointX, double& pointY, double& pointZ, fileWorkType file);

// запись точек
error_type pointSave(FILE *f, const double pointX, const double pointY, const double pointZ);

// чтение точек
error_type pointsLoad(pointType *points, fileWorkType file, const unsigned int size);

// сохранение точек
error_type pointsSave(const pointType* points, fileWorkType file, const unsigned int size);

#endif // POINT_H

