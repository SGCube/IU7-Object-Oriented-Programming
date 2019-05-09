#ifndef MODELDATAWORK_CPP
#define MODELDATAWORK_CPP

#include "modeldatawork.h"
#include "modelwork.h"
#include "filework.h"

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

#endif // MODELDATAWORK_CPP
