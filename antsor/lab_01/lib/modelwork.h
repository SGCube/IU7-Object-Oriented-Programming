#ifndef MODELWORK_H
#define MODELWORK_H

#include "error.h"
#include "model.h"
#include "actionparam.h"

ErrorType loadModel(const ModelType& model, const FileWorkType& param);

ErrorType saveModel(const ModelType& model, const FileWorkType& param);

ErrorType moveModel(const VertexArrayType& model, const MoveParamType& param);

ErrorType scaleModel(const VertexArrayType& model, const ScaleParamType& param);

ErrorType rotateModel(const VertexArrayType& model, const RotateParamType& param);

#endif // MODELWORK_H
