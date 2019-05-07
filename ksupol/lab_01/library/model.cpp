#ifndef MODEL_CPP
#define MODEL_CPP

#include "model.h"

modelType modelInit()
{
    modelType model;
    edgeArrInit(model.edgeArr);
    nodeArrInit(model.nodeArr);

    return model;
}

error_type modelFree(modelType& model)
{
    if (edgeArrFree(model.edgeArr))
        return ErrorFree;
    if (nodeArrFree(model.nodeArr))
        return ErrorFree;
    return OK;
}

error_type modelChange(modelType& model, modelType& tmpModel)
{
    error_type error;
    if ((error = modelFree(model)))
        return error;
    model = tmpModel;
    return OK;
}

#endif // MODEL_CPP

