#ifndef MODEL_DATA_WORK_CPP
#define MODEL_DATA_WORK_CPP

#include "model_data_work.h"

error_type modelLoadData(modelType& model, const actionDataType data)
{
    const char *fileName = data.fileName;
    fileWorkType file = fileTypeInit();

    error_type error;
    if ((error = isFileNameEmpty(fileName)))
        return error;

    if ((error = openFileForRead(file, fileName)))
        return error;

    error = modelLoad(model, file);

    if (isOpenFile(file.f))
        fclose(file.f);

    return error;
}

error_type modelSaveData(const modelType model, const actionDataType data)
{
    const char* fileName = data.fileName;
    fileWorkType file = fileTypeInit();

    error_type error;
    if ((error = isFileNameEmpty(fileName)))
        return error;


    if ((error = openFileForWrite(file, fileName)))
        return error;

    error = modelSave(model, file);

    if (isOpenFile(file.f))
        fclose(file.f);

    return error;
}

error_type modelShiftData(const modelType &model, const actionDataType data)
{
    return modelShiftParam(model.nodeArr, data.param);
}

error_type modelScaleData(const modelType &model, const actionDataType data)
{
    return modelScaleParam(model.nodeArr, data.param);
}

error_type modelTurnData(const modelType &model, const actionDataType data)
{
    return modelTurnParam(model.nodeArr, data.param);
}

error_type modelProjectPData(const modelType &model, const actionDataType data)
{
    return modelProjectPParam(model.nodeArr, data.param);
}

error_type modelProjectCData(const modelType &model, const actionDataType data)
{
    return modelProjectCParam(model.nodeArr, data.param);
}

error_type modelDrawData(const modelType model)
{
    return modelDrawParam(model.edgeArr, model.nodeArr);
}

#endif // MODEL_DATA_WORK_CPP

