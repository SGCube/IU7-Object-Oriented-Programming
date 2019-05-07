#ifndef NODE_H
#define NODE_H

#include "errors.h"
#include "file_work.h"

#include <stdio.h>

struct nodeType
{
    double x;
    double y;
    double z;
};

enum nodeFieldType
{
    fieldX,
    fieldY,
    fieldZ
};

bool nodesIsExist(const nodeType *nodes);

// проверка на существование
error_type checkNodesExist(const nodeType* nodes);

// выделение памяти для массива точек
error_type nodesAllocation(nodeType*& nodes, const unsigned int size);

// освобождение памяти из-под массива точек
error_type nodesFree(nodeType*& nodes);

// загрузка точек
error_type nodeLoad(double& nodeX, double& nodeY, double& nodeZ, fileWorkType file);

// запись точек
error_type nodeSave(FILE* f, const double nodeX, const double nodeY, const double nodeZ);

// чтение точек
error_type nodesLoad(nodeType *nodes, fileWorkType file, const unsigned int size);

// сохранение точек
error_type nodesSave(const nodeType* nodes, fileWorkType file, const unsigned int size);

#endif // NODE_H

