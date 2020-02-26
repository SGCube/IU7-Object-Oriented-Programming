#ifndef MODELACTION_CPP
#define MODELACTION_CPP

#include "model.h"
#include "modelaction.h"
#include "modeldatawork.h"
#include "verticeswork.h"

ErrorType modelLoadAction(ModelType& model, const ParameterType& param)
{
	return modelLoadData(model, param.fileWorkParameters);
}

ErrorType modelSaveAction(const ModelType& model, const ParameterType& param)
{
	return modelSaveData(model, param.fileWorkParameters);
}

ErrorType modelFreeAction(ModelType &model)
{
	return freeModel(model);
}

ErrorType modelDrawAction(const ModelType &model, ParameterType& param)
{
	return modelDrawData(model.vertices, model.edges, param.drawParameters);
}

ErrorType modelMoveAction(ModelType& model, const ParameterType& param)
{
	return modelMoveData(model.vertices, param.moveParameters);
}

ErrorType modelScaleAction(ModelType& model, const ParameterType& param)
{
	return modelScaleData(model.vertices, param.scaleParameters);
}

ErrorType modelRotateAction(ModelType& model, const ParameterType& param)
{
	return modelRotateData(model.vertices, param.rotateParameters);
}

ErrorType modelProjParallelAction(ModelType& model, const ParameterType& param)
{
	return modelProjParallelData(model.vertices, param.projParallelParameters);
}

ErrorType modelProjCentralAction(ModelType& model, const ParameterType& param)
{
	return modelProjCentralData(model.vertices, param.projCentralParameters);
}

#endif // MODELACTION_CPP
