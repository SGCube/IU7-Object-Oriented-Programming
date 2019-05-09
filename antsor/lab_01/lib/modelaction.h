#ifndef MODELACTION_H
#define MODELACTION_H

#include "error.h"
#include "model.h"
#include "actionparam.h"

ErrorType modelLoadAction(const ModelType& model, const ParameterType& param);

ErrorType modelSaveAction(const ModelType& model, const ParameterType& param);

ErrorType modelFreeAction(const ModelType &model);

ErrorType modelDrawAction(const ModelType &model);

ErrorType modelMoveAction(const ModelType& model, const ParameterType& param);

ErrorType modelScaleAction(const ModelType& model, const ParameterType& param);

ErrorType modelRotateAction(const ModelType& model, const ParameterType& param);

#endif // MODELACTION_H
