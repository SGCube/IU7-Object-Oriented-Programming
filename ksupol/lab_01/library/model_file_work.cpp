#ifndef MODEL_FILE_WORK_CPP
#define MODEL_FILE_WORK_CPP

#include "model_file_work.h"

error_type modelLoad(modelType& model, fileWorkType file)
{
    modelType tmpModel = modelInit();

    error_type error;

    if ((error = nodesArrLoad(tmpModel.nodeArr, file)))
    {
        edgeArrFree(tmpModel.edgeArr);
        return error;
    }

    if ((error = modelChange(model, tmpModel)))
    {
        edgeArrFree(tmpModel.edgeArr);
        nodeArrFree(tmpModel.nodeArr);
        return error;
    }

    return error;
}

error_type modelSave(const modelType model, fileWorkType file)
{
    error_type error;

    if ((error = edgesArrSave(file, model.edgeArr)))
        return error;

    return nodesArrSave(file, model.nodeArr);
}

#endif // MODEL_FILE_WORK_CPP

