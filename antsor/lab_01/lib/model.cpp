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
	ErrorType error = freeVertexArray(vertices);
	if (error != OK)
		return error;
	return freeEdgeArray(edges);
}

// load model data
ErrorType loadModel(ModelType& model, FileWorkType file)
{
	const char* fileName = data.fileName;

    typeError error;
    if ((error = isFileNameEmpty(fileName)))
        return error;

    fileWorkType file;
    if ((error = fileTypeInit(file)))
        return error;

    if ((error = openFileForRead(file, fileName)))
        return error;

    error = modelLoad(model, file);

    if (isOpenFile(file.f))
        fclose(file.f);

    return error;
}

// save model data
ErrorType saveModel(const ModelType model, FileWorkType file)
{
	
}

// modify model data
ErrorType modifyModel(ModelType& model, ModelType& tmpmodel)
{
	
}

#endif // MODEL_H


#endif
