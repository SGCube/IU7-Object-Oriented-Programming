#ifndef MODELDATAWORK_H
#define MODELDATAWORK_H

#include "error.h"
#include "model.h"
#include "actionparam.h"

ErrorType modelLoadData(const ModelType& model, const FileWorkParamType param);

ErrorType modelSaveData(const ModelType& model, const FileWorkParamType param);

ErrorType modelDrawData(const VertexArrayType& vertices, const EdgeArrayType& edges);

ErrorType modelMoveData(const VertexArrayType& vertices, const MoveParamType param);

ErrorType modelScaleData(const VertexArrayType& vertices, const ScaleParamType param);

ErrorType modelRotateData(const VertexArrayType& vertices, const RotateParamType param);

#endif // MODELDATAWORK_H
