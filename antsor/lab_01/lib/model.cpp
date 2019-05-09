#ifndef MODEL_CPP
#define MODEL_CPP

#include "model.h"

// initialize model
ModelType initializeModel()
{
	ModelType model;
	initializeVertexArray(model.vertices);
	initializeEdgeArray(model.edges);
	return model;
}

// free memory of model
ErrorType freeModel(ModelType& model)
{
	ErrorType error = freeVertexArray(model.vertices);
	if (error != OK)
		return error;
	return freeEdgeArray(model.edges);
}

#endif // MODEL_H
