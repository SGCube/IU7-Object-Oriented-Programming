#ifndef MODEL_CPP
#define MODEL_CPP

#include "model.h"

// initialize model
ModelType initializeModel()
{
	ModelType model;
	model.vertices = initializeVertexArray();
	model.edges = initializeEdgeArray();
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

ErrorType loadModel(ModelType& model, const FileWorkType& file)
{
	ModelType tmpModel = initializeModel();
	ErrorType error = loadEdgeArray(tmpModel.edges, file);
    if (error == OK)
	{
		error = loadVertexArray(tmpModel.vertices, file);
		if (error != OK)
			freeEdgeArray(tmpModel.edges);
	}

	if (error == OK)
	{
		error = freeModel(model);
		if(error == OK)
			model = tmpModel;
		else
			freeModel(tmpModel);
	}

	return error;
}

ErrorType saveModel(const ModelType& model, const FileWorkType& file)
{
	ErrorType error = saveEdgeArray(model.edges, file);
    if (error != OK)
	{
        return error;
	}
	return saveVertexArray(model.vertices, file);
}


#endif // MODEL_H
