#ifndef MODELACTION_H
#define MODELACTION_H

#include "error.h"
#include "model.h"
#include "actionparam.h"

ErrorType modelLoadAction(ModelType& model, const ParameterType& param);

ErrorType modelSaveAction(const ModelType& model, const ParameterType& param);

ErrorType modelFreeAction(ModelType &model);

ErrorType modelDrawAction(const ModelType &model, ParameterType& param);

ErrorType modelMoveAction(ModelType& model, const ParameterType& param);

ErrorType modelScaleAction(ModelType& model, const ParameterType& param);

ErrorType modelRotateAction(ModelType& model, const ParameterType& param);

ErrorType modelProjParallelAction(ModelType& model, const ParameterType& param);

ErrorType modelProjCentralAction(ModelType& model, const ParameterType& param);

#endif // MODELACTION_H
