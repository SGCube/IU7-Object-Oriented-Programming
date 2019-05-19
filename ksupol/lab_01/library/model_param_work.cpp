#ifndef MODEL_PARAM_WORK_CPP
#define MODEL_PARAM_WORK_CPP

#include "model_param_work.h"

error_type modelShiftParam(pointArrType &pointArr, const paramType param)
{
    return modelShift(pointArr.points, param.shiftData, pointArr.size);
}

error_type modelScaleParam(pointArrType &pointArr, const paramType param)
{
    return modelScale(pointArr.points, param.scaleData, pointArr.size);
}

error_type modelTurnParam(pointArrType &pointArr, const paramType param)
{
    return modelTurn(pointArr.points, param.turnData, pointArr.size);
}

error_type modelProjectPParam(pointArrType &pointArr, const paramType param)
{
    return modelProjectP(pointArr.points, param.projectPData, pointArr.size);
}

error_type modelProjectCParam(pointArrType &pointArr, const paramType param)
{
    return modelProjectC(pointArr.points, param.projectCData, pointArr.size);
}

error_type modelDrawParam(edgeArrType edgeArr, const pointArrType pointArr)
{
    return drawDisplay(edgeArr.edges, pointArr.points, edgeArr.size);
}

#endif // MODEL_PARAM_WORK_CPP

