#ifndef MODELDATAWORK_CPP
#define MODELDATAWORK_CPP

#include "modeldatawork.h"
#include "modelwork.h"
#include "projection.h"
#include "filework.h"
#include "canvas.h"

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
    fclose(file.f);

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
						const EdgeArrayType& edgesArray)
{
	return modelDraw(edgesArray.edges, verticesArray.vertices, edgesArray.size);
}

ErrorType modelMoveData(VertexArrayType& verticesArray,
						const MoveParamType param)
{
	return moveModel(verticesArray.vertices, verticesArray.size, param);
}

ErrorType modelScaleData(VertexArrayType& verticesArray,
						 const ScaleParamType param)
{
	return scaleModel(verticesArray.vertices, verticesArray.size, param);
}

ErrorType modelRotateData(VertexArrayType& verticesArray,
						  const RotateParamType param)
{
	return rotateModel(verticesArray.vertices, verticesArray.size, param);
}

ErrorType modelProjParallelData(VertexArrayType& verticesArray,
								const ProjParallelParamType param)
{
	return projectParallelModel(verticesArray.vertices, verticesArray.size,
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
