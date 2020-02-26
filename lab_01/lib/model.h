#ifndef MODEL_H
#define MODEL_H

#include "error.h"
#include "filework.h"
#include "vertexarray.h"
#include "edgearray.h"
#include "actionparam.h"

// type of model
struct ModelType
{
	VertexArrayType vertices;
	EdgeArrayType edges;
};

ModelType initializeModel();

ErrorType freeModel(ModelType& model);

ErrorType loadModel(ModelType& model, const FileWorkType& file);

ErrorType saveModel(const ModelType& model, const FileWorkType& file);

#endif // MODEL_H
