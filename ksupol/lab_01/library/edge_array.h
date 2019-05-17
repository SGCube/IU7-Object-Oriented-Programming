#ifndef EDGE_ARRAY_H
#define EDGE_ARRAY_H

#include "errors.h"
#include "edge.h"
#include "file_work.h"

#include <stdio.h>

struct edgeArrType
{
    type_edge *edges;
    unsigned int size;
};

// инициализация массива ребер
error_type edgeArrInit(edgeArrType& edgeArr);

// освобождения массива ребер
error_type edgeArrFree(edgeArrType& edgeArr);

// загрузка массива ребер
error_type edgesArrLoad(edgeArrType& edgeArr, fileWorkType file);

// сохранение массива ребер
error_type edgesArrSave(fileWorkType file, edgeArrType edgeArr);

#endif // EDGE_ARRAY_H

