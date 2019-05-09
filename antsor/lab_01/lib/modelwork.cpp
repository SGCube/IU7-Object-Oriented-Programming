#ifndef MODELWORK_CPP
#define MODELWORK_CPP

#include "modelwork.h"

ErrorType loadModel(const ModelType& model, const FileWorkType& param)
{
	ErrorType error = OK;
	ModelType tmpModel = initializeModel();
	
	error = loadEdgeArray(tmpModel.edges, param);
    if ((error = edgesArrLoad(tmpModel.edgeArr, file)))
        return error;

    if ((error = nodesArrLoad(tmpModel.nodeArr, file)))
    {
        edgeArrFree(tmpModel.edgeArr);
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

ErrorType saveModel(const ModelType& model, const FileWorkType& param)
{
	
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
