#ifndef MODELDATAWORK_CPP
#define MODELDATAWORK_CPP

#include "modeldatawork.h"
#include "verticeswork.h"
#include "filework.h"
#include "draw.h"

ErrorType modelLoadData(ModelType& model, const FileWorkParamType param)
{
	ErrorType error = checkFileNameIsEmpty(param.fileName);
    if (error != OK)
        return error;

    FileWorkType file;
	error = initializeFileType(file);
    if (error != OK)
        return error;

    error = openFileForRead(file, param.fileName);
	if (error != OK)
        return error;

	error = loadModel(model, file);
    fclose(file);

    return error;
}

ErrorType modelSaveData(const ModelType& model, const FileWorkParamType param)
{
	ErrorType error = checkFileNameIsEmpty(param.fileName);
    if (error != OK)
        return error;

    FileWorkType file;
	error = initializeFileType(file);
    if (error != OK)
        return error;

    error = openFileForWrite(file, param.fileName);
	if (error != OK)
        return error;

	error = saveModel(model, file);
    fclose(file.f);

    return error;
}

ErrorType modelDrawData(const VertexArrayType& verticesArray,
						const EdgeArrayType& edgesArray,
						DrawParamType& param)
{
	return modelDraw(edgesArray.edges, verticesArray.vertices, edgesArray.size,
					 param.drawParameters);
}

ErrorType modelMoveData(VertexArrayType& verticesArray,
						const MoveParamType param)
{
	return moveVertices(verticesArray.vertices, verticesArray.size, param);
}

ErrorType modelScaleData(VertexArrayType& verticesArray,
						 const ScaleParamType param)
{
	return scaleVertices(verticesArray.vertices, verticesArray.size, param);
}

ErrorType modelRotateData(VertexArrayType& verticesArray,
						  const RotateParamType param)
{
	switch (param.axis)
	{
		case X:
			return rotateX(verticesArray.vertices, verticesArray.size, param);
		case Y:
			return rotateY(verticesArray.vertices, verticesArray.size, param);
		case Z:
			return rotateZ(verticesArray.vertices, verticesArray.size, param);
		default:
			return ERROR_AXIS;
	}
}

ErrorType modelProjParallelData(VertexArrayType& verticesArray,
								const ProjParallelParamType param)
{
	return projectParallel(verticesArray.vertices, verticesArray.size,
						   param.axis);
}

ErrorType modelProjCentralData(VertexArrayType& verticesArray,
							   const ProjCentralParamType param)
{
	switch (param.axis)
	{
		case X:
			return projectCentralX(verticesArray.vertices, verticesArray.size,
								   param.distance);
		case Y:
			return projectCentralY(verticesArray.vertices, verticesArray.size,
								   param.distance);
		case Z:
			return projectCentralZ(verticesArray.vertices, verticesArray.size,
								   param.distance);
		default:
			return ERROR_AXIS;
	}
}

#endif // MODELDATAWORK_CPP
