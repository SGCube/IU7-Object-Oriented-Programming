#ifndef MODELPROJECT_H
#define MODELPROJECT_H

#include "errors.h"
#include "model_data_work.h"
#include "point.h"
#include "projections.h"

// изменение координат пересечений для параллельного проецирования
error_type modelProjectP(pointType *points, struct projectPDataType
                                projectPData, const unsigned int size);

// изменение координат пересечений для центрального проецирования
error_type modelProjectC(pointType* points, struct projectCDataType
                                projectCData, const unsigned int size);

#endif // MODELPROJECT_H

