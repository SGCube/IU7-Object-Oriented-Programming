#ifndef MODELWORK_CPP
#define MODELWORK_CPP

#include "modelwork.h"
#include "vertextransform.h"

ErrorType loadModel(ModelType& model, const FileWorkType& file)
{
	ModelType tmpModel = initializeModel();
	ErrorType error = loadEdgeArray(tmpModel.edges, file);
    if (error != OK)
	{
        return error;
	}

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
		return error;
	}
	model = tmpModel;
    return OK;
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

ErrorType moveModel(VertexType* vertices, const size_t size,
					const MoveParamType& param)
{
	ErrorType error = checkVerticesExist(vertices);
    if (error != OK)
        return error;

    for (size_t i = 0; i < size; i++)
    {
        vertices[i].x = move(vertices[i].x, param.dx);
        vertices[i].y = move(vertices[i].y, param.dy);
        vertices[i].z = move(vertices[i].z, param.dz);
    }
    return OK;
}

ErrorType scaleModel(VertexType* vertices, const size_t size,
					 const ScaleParamType& param)
{
	ErrorType error = checkVerticesExist(vertices);
    if (error != OK)
        return error;

    for (size_t i = 0; i < size; i++)
    {
        vertices[i].x = scale(vertices[i].x, param.kx, param.xc);
        vertices[i].y = scale(vertices[i].y, param.ky, param.yc);
        vertices[i].z = scale(vertices[i].z, param.kz, param.zc);
    }
    return OK;
}

ErrorType rotateModel(VertexType* vertices, const size_t size,
					  const RotateParamType& param)
{
	ErrorType error = checkVerticesExist(vertices);
	if (error != OK)
	{
        return error;
	}

	switch (param.axis)
    {
        case X:
            error = rotateX(vertices, size, param);
            break;
        case Y:
            error = rotateY(vertices, size, param);
            break;
        case Z:
            error = rotateZ(vertices, size, param);
            break;
        default:
            error = ERROR_AXIS;
    }
    return error;
}

#endif // MODELWORK_CPP
