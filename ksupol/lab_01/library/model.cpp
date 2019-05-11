#ifndef MODEL_CPP
#define MODEL_CPP

#include "model.h"

modelType modelInit()
{
    modelType model;
    edgeArrInit(model.edgeArr);
    pointArrInit(model.pointArr);

    return model;
}

error_type modelFree(modelType& model)
{
    if (edgeArrFree(model.edgeArr))
        return ErrorFree;
    if (pointArrFree(model.pointArr))
        return ErrorFree;
    return OK;
}

error_type modelChange(modelType& model, modelType& tmpModel)
{
    error_type error = modelFree(model);
    if (error)
        return error;
    model = tmpModel;
    return OK;
}

#endif // MODEL_CPP

