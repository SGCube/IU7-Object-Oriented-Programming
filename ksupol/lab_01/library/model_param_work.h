#ifndef MODELPARAMWORK_H
#define MODELPARAMWORK_H

#include "model_transform.h"
#include "model_project.h"
#include "display.h"
#include "point_array.h"
#include "edge_array.h"

// нахождение параметров для переноса
error_type modelShiftParam(pointArrType &pointArr, union paramType param);

// нахождение параметров для масштабирования
error_type modelScaleParam(pointArrType &pointArr, union paramType param);

// нахождение параметров для поворота
error_type modelTurnParam(pointArrType &pointArr, union paramType param);

// нахождение параметров для параллельного проецирования
error_type modelProjectPParam(pointArrType &pointArr, union paramType param);

// нахождение параметров для центрального проецирования
error_type modelProjectCParam(pointArrType &pointArr, union paramType param);

// нахождение параметров для рисования
error_type modelDrawParam(edgeArrType edgeArr, pointArrType pointArr);

#endif // MODELPARAMWORK_H

