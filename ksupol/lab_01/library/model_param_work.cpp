#ifndef MODEL_PARAM_WORK_CPP
#define MODEL_PARAM_WORK_CPP

#include "model_param_work.h"

error_type modelShiftParam(const nodeArrType &nodeArr, const paramType param)
{
    return modelShift(nodeArr.nodes, param.shiftData, nodeArr.size);
}

error_type modelScaleParam(const nodeArrType &nodeArr, const paramType param)
{
    return modelScale(nodeArr.nodes, param.scaleData, nodeArr.size);
}

error_type modelTurnParam(const nodeArrType &nodeArr, const paramType param)
{
    return modelTurn(nodeArr.nodes, param.turnData, nodeArr.size);
}

error_type modelProjectPParam(const nodeArrType &nodeArr, const paramType param)
{
    return modelProjectP(nodeArr.nodes, param.projectPData, nodeArr.size);
}

error_type modelProjectCParam(const nodeArrType &nodeArr, const paramType param)
{
    return modelProjectC(nodeArr.nodes, param.projectCData, nodeArr.size);
}

error_type modelDrawParam(const edgeArrType edgeArr, const nodeArrType nodeArr)
{
    return drawDisplay(edgeArr.edges, nodeArr.nodes, edgeArr.size);
}

#endif // MODEL_PARAM_WORK_CPP

