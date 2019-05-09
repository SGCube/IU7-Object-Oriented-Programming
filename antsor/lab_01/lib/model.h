#ifndef MODEL_H
#define MODEL_H

#include "error.h"
#include "filework.h"
#include "vertexarray.h"
#include "edgearray.h"

// type of model
struct ModelType
{
	VertexArrayType vertices;
	EdgeArrayType edges;
};

// initialize model
ModelType initializeModel();

// free memory of model
ErrorType freeModel(ModelType& model);

#endif // MODEL_H
