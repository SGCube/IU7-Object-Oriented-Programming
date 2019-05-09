#ifndef MODELDATAWORK_H
#define MODELDATAWORK_H

#include "error.h"
#include "model.h"
#include "actionparam.h"

ErrorType modelLoadData(ModelType& model, const FileWorkParamType param);

ErrorType modelSaveData(const ModelType& model, const FileWorkParamType param);

ErrorType modelDrawData(const VertexArrayType& verticesArray,
						const EdgeArrayType& edgesArray);

ErrorType modelMoveData(const VertexArrayType& verticesArray,
						const MoveParamType param);

ErrorType modelScaleData(const VertexArrayType& verticesArray,
						 const ScaleParamType param);

ErrorType modelRotateData(const VertexArrayType& verticesArray,
						  const RotateParamType param);

#endif // MODELDATAWORK_H
