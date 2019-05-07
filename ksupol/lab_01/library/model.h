#ifndef MODEL_H
#define MODEL_H

#include "errors.h"
#include "edge_array.h"
#include "node_array.h"

// структура модели
struct modelType
{
    edgeArrType edgeArr;
    nodeArrType nodeArr;
};

// инициализация модели
modelType modelInit();

// освобождение памяти из-под модели
error_type modelFree(modelType& model);

// создание новой модели
error_type modelChange(modelType& model, modelType& tmpModel);

#endif // MODEL_H

