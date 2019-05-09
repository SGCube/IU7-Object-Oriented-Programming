#ifndef MODELWORK_H
#define MODELWORK_H

#include "error.h"
#include "model.h"
#include "actionparam.h"

ErrorType loadModel(const ModelType& model, const FileWorkType& file);

ErrorType saveModel(const ModelType& model, const FileWorkType& file);

ErrorType moveModel(VertexType* vertices, const unsigned int size,
					const MoveParamType& param);

ErrorType scaleModel(VertexType* vertices, const unsigned int size,
					 const ScaleParamType& param);

ErrorType rotateModel(VertexType* vertices, const unsigned int size,
					  const RotateParamType& param);

#endif // MODELWORK_H
