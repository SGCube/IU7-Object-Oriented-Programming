#ifndef MODELDATAWORK_CPP
#define MODELDATAWORK_CPP

#include "modeldatawork.h"
#include "modelwork.h"
#include "filework.h"
#include "canvas.h"

ErrorType modelLoadData(ModelType& model, const FileWorkParamType param)
{
	ErrorType error = OK;	
	
    const char* fileName = param.fileName;
    error = checkFileNameIsEmpty(fileName);
    if (error != OK)
        return error;

    FileWorkType file;
	error = initializeFileType(file);
    if (error != OK)
        return error;

    error = openFileForRead(file, fileName);
	if (error != OK)
        return error;

	error = loadModel(model, file);
    fclose(file.f);

    return error;
}

ErrorType modelSaveData(const ModelType& model, const FileWorkParamType param)
{
	ErrorType error = OK;	
	
    const char* fileName = param.fileName;
    error = checkFileNameIsEmpty(fileName);
    if (error != OK)
        return error;

    FileWorkType file;
	error = initializeFileType(file);
    if (error != OK)
        return error;

    error = openFileForWrite(file, fileName);
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

ErrorType modelMoveData(const VertexArrayType& verticesArray,
						const MoveParamType param)
{
	return moveModel(verticesArray.vertices, verticesArray.size, param);
}

ErrorType modelScaleData(const VertexArrayType& verticesArray,
						 const ScaleParamType param)
{
	return scaleModel(verticesArray.vertices, verticesArray.size, param);
}

ErrorType modelRotateData(const VertexArrayType& verticesArray,
						  const RotateParamType param)
{
	return rotateModel(verticesArray.vertices, verticesArray.size, param);
}

#endif // MODELDATAWORK_CPP
