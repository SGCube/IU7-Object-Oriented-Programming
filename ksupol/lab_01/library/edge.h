#ifndef EDGE_H
#define EDGE_H

#include "errors.h"
#include "file_work.h"

#include <stdio.h>

struct type_edge
{
    unsigned int src;
    unsigned int purp;
};

// проверка на существование массива ребер
bool edgesIsExist(type_edge *edges);

// проверка на существование массива ребер
error_type checkEdgesExist(type_edge* edges);

// выделение памяти для массива ребер
error_type edgesAllocation(type_edge*& edges, unsigned int size);

// освобождение памяти из-под массива ребра
error_type edgesFree(type_edge *&edges);

// чтение вершин из файла
error_type edgeLoad(unsigned int &edgeSrc, unsigned int &edgePurp, FILE* f);

// сохранение ребер в файл
error_type edgeSave(fileWorkType file, unsigned int edgeSrc, unsigned int edgePurp);

// чтение ребер из файла
error_type edgesLoad(type_edge* edges, fileWorkType file, size_t size);

// сохранение ребер в фай
error_type edgesSave(type_edge* edges, fileWorkType file, size_t size);

#endif // EDGE_H

