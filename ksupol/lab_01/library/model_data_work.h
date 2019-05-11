#ifndef MODELDATAWORK_H
#define MODELDATAWORK_H

#include "errors.h"
#include "model.h"
#include "model_file_work.h"
#include "file_work.h"

#include <fstream>

// тип осей
enum typeAxis
{
    X, Y, Z
};

// данные для переноса
struct shiftDataType
{
    double dx, dy, dz;
};

// данные для масштабрования
struct scaleDataType
{
    double kx, ky, kz;
    double cx, cy, cz;
};

// данные для поворота
struct turnDataType
{
    int angle;
    double cx, cy, cz;
    typeAxis axis;
};

// данные для параллельного проецирования
struct projectPDataType
{
    typeAxis axis;
};

// данные для центрального проецирования
struct projectCDataType
{
    typeAxis axis;
    double distance;
};

union paramType
{
    shiftDataType shiftData;
    scaleDataType scaleData;
    turnDataType turnData;
    projectPDataType projectPData;
    projectCDataType projectCData;
};

struct actionDataType
{
    char* fileName;
    paramType param;
};

// загрузка модели
error_type modelLoadData(modelType& model, const actionDataType data);

// сохранение модели
error_type modelSaveData(modelType model, const actionDataType data);

// перенос модели
error_type modelShiftData(modelType &model, const actionDataType data);

// масштабирование модели
error_type modelScaleData(modelType &model, const actionDataType data);

// поворот модели
error_type modelTurnData(modelType &model, const actionDataType data);

// параллельное проектирование модели
error_type modelProjectPData(modelType &model, const actionDataType data);

// центральное проектирование модели
error_type modelProjectCData(modelType &model, const actionDataType data);

// рисование модели на экран
error_type modelDrawData(modelType model);

#include "model_param_work.h"

#endif // MODELDATAWORK_H

