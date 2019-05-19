#ifndef MODEL_DATA_WORK_CPP
#define MODEL_DATA_WORK_CPP

#include "model_data_work.h"

error_type modelLoadData(modelType& model, actionDataType data)
{
    const char *fileName = data.fileName;

    error_type error = isFileNameEmpty(fileName);
    if (error)
        return error;

    fileWorkType file = fileTypeInit();

    error = openFileForRead(file, fileName);
    if (error)
        return error;

    error = modelLoad(model, file);

    fclose(file.f);

    return error;
}

error_type modelSaveData(modelType model, const actionDataType data)
{
    const char* fileName = data.fileName;
    fileWorkType file = fileTypeInit();

    error_type error = isFileNameEmpty(fileName);
    if (error)
        return error;

    error = openFileForWrite(file, fileName);
    if (error)
        return error;

    error = modelSave(model, file);

    if (isOpenFile(file.f))
        fclose(file.f);

    return error;
}

error_type modelShiftData(modelType &model, const actionDataType data)
{
    return modelShiftParam(model.pointArr, data.param);
}

error_type modelScaleData(modelType &model, const actionDataType data)
{
    return modelScaleParam(model.pointArr, data.param);
}

error_type modelTurnData(modelType &model, const actionDataType data)
{
    return modelTurnParam(model.pointArr, data.param);
}

error_type modelProjectPData(modelType &model, const actionDataType data)
{
    return modelProjectPParam(model.pointArr, data.param);
}

error_type modelProjectCData(modelType &model, const actionDataType data)
{
    return modelProjectCParam(model.pointArr, data.param);
}

error_type modelDrawData(modelType model)
{
    return modelDrawParam(model.edgeArr, model.pointArr);
}

#endif // MODEL_DATA_WORK_CPP

