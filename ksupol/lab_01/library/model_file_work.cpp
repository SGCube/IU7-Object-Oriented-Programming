#ifndef MODEL_FILE_WORK_CPP
#define MODEL_FILE_WORK_CPP

#include "model_file_work.h"

error_type modelLoad(modelType& model, fileWorkType file)
{
    modelType tmpModel = modelInit();

    error_type error;

    error = edgesArrLoad(tmpModel.edgeArr, file);
    if (error)
        return error;

    error = nodesArrLoad(tmpModel.nodeArr, file);
    if (error)
    {
        edgeArrFree(tmpModel.edgeArr);
        return error;
    }
    error = modelChange(model, tmpModel);
    if (error)
    {
        edgeArrFree(tmpModel.edgeArr);
        nodeArrFree(tmpModel.nodeArr);
    }

    return error;
}

error_type modelSave(const modelType model, fileWorkType file)
{
    error_type error;

    error = edgesArrSave(file, model.edgeArr);
    if (error)
        return error;

    return nodesArrSave(file, model.nodeArr);
}

#endif // MODEL_FILE_WORK_CPP

