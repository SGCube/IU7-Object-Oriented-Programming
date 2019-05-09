#ifndef MODELDATAWORK_H
#define MODELDATAWORK_H

#include "error.h"
#include "model.h"
#include "actionparam.h"

ErrorType modelLoadData(const ModelType& model, const FileWorkParamType param);

ErrorType modelSaveData(const ModelType& model, const FileWorkParamType param);

#endif // MODELDATAWORK_H
