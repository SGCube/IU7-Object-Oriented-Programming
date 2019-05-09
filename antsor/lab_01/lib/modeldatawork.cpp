#ifndef MODELDATAWORK_CPP
#define MODELDATAWORK_CPP

#include "modeldatawork.h"
#include "modelwork.h"
#include "filework.h"
#include "canvas.h"

ErrorType modelLoadData(const ModelType& model, const FileWorkParamType param)
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

ErrorType modelDrawData(const VertexArrayType& vertices, const EdgeArrayType& edges)
{
	return modelDraw(edges, vertices, edges.size);
}

ErrorType modelMoveData(const VertexArrayType& vertices, const MoveParamType param)
{
	return moveModel(vertices.vertices, vertices.size, param);
}

ErrorType modelScaleData(const VertexArrayType& vertices, const ScaleParamType param)
{
	return scaleModel(vertices.vertices, vertices.size, param);
}

ErrorType modelRotateData(const VertexArrayType& vertices, const RotateParamType param)
{
	return rotateModel(vertices.vertices, vertices.size, param);
}

#endif // MODELDATAWORK_CPP
