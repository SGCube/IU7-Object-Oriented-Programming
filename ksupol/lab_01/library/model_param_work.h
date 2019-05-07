#ifndef MODELPARAMWORK_H
#define MODELPARAMWORK_H

#include "model_transform.h"
#include "model_project.h"
#include "display.h"
#include "node_array.h"
#include "edge_array.h"

// нахождение параметров для переноса
error_type modelShiftParam(const nodeArrType &nodeArr, const union paramType param);

// нахождение параметров для масштабирования
error_type modelScaleParam(const nodeArrType &nodeArr, const union paramType param);

// нахождение параметров для поворота
error_type modelTurnParam(const nodeArrType &nodeArr, const union paramType param);

// нахождение параметров для параллельного проецирования
error_type modelProjectPParam(const nodeArrType &nodeArr, const union paramType param);

// нахождение параметров для центрального проецирования
error_type modelProjectCParam(const nodeArrType &nodeArr, const union paramType param);

// нахождение параметров для рисования
error_type modelDrawParam(const edgeArrType edgeArr, const nodeArrType nodeArr);

#endif // MODELPARAMWORK_H

