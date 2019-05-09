#ifndef MODELWORK_CPP
#define MODELWORK_CPP

#include "modelwork.h"

ErrorType loadModel(const ModelType& model, const FileWorkType& file)
{
	ErrorType error = OK;
	ModelType tmpModel = initializeModel();
	
	error = loadEdgeArray(tmpModel.edges, file);
    if (error != OK)
        return error;

	error = loadVertexArray(tmpModel.vertices, file);
    if (error != OK)
    {
        freeEdgeArray(tmpModel.edges);
        return error;
    }
	
	error = freeModel(model);
	if (error != OK)
	{
		freeVertexArray(tmpModel.vertices);
		freeEdgeArray(tmpModel.edges);
	}
	else
		model = tmpModel;
    return error;
}

ErrorType saveModel(const ModelType& model, const FileWorkType& file)
{
	ErrorType error = saveEdgeArray(tmpModel.edges, file);
    if (error != OK)
        return error;
	return saveVertexArray(tmpModel.vertices, file);
}

ErrorType moveModel(const VertexArrayType& model, const MoveParamType& param)
{
	
}

ErrorType scaleModel(const VertexArrayType& model, const ScaleParamType& param)
{
	
}

ErrorType rotateModel(const VertexArrayType& model, const RotateParamType& param)
{
	
}

#endif // MODELWORK_CPP
