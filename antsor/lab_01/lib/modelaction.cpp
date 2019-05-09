#ifndef MODELACTION_CPP
#define MODELACTION_CPP

#include "modelaction.h"
#include "modeldatawork.h"
#include "modelwork.h"

ErrorType modelLoadAction(const ModelType& model, const ParameterType& param)
{
	return modelLoadData(model, param.fileWorkParameters);
}

ErrorType modelSaveAction(const ModelType& model, const ParameterType& param)
{
	return modelSaveData(model, param.fileWorkParameters);
}

ErrorType modelMoveAction(const ModelType& model, const ParameterType& param)
{
	return moveModel(model.vertices, param.moveParameters);
}

ErrorType modelScaleAction(const ModelType& model, const ParameterType& param)
{
	return scaleModel(model.vertices, param.scaleParameters);
}

ErrorType modelRotateAction(const ModelType& model, const ParameterType& param)
{
	return rotateModel(model.vertices, param.rotateParameters);
}

#endif // MODELACTION_CPP
