#ifndef MODEL_FILE_WORK_CPP
#define MODEL_FILE_WORK_CPP

#include "model_file_work.h"

error_type modelLoad(modelType& model, fileWorkType file)
{
    modelType tmpModel = modelInit();

    error_type error = edgesArrLoad(tmpModel.edgeArr, file);
    if (error)
        return error;

    error = pointsArrLoad(tmpModel.pointArr, file);
    if (error)
    {
        edgeArrFree(tmpModel.edgeArr);
        return error;
    }
    error = modelChange(model, tmpModel);
    if (error)
    {
        edgeArrFree(tmpModel.edgeArr);
        pointArrFree(tmpModel.pointArr);
        return error;
    }

    return error;
}

error_type modelSave(modelType model, fileWorkType file)
{
    error_type error = edgesArrSave(file, model.edgeArr);
    if (error)
        return error;

    return pointsArrSave(file, model.pointArr);
}

#endif // MODEL_FILE_WORK_CPP

