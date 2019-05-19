#ifndef MODELTRANSFORM_H
#define MODELTRANSFORM_H

#include "errors.h"
#include "model_data_work.h"
#include "point.h"
#include "transformations.h"

// изменение координат точек для переноса
error_type modelShift(pointType *points, const shiftDataType shiftData,
                                                    size_t size);

// изменение координат точек для масштабирования
error_type modelScale(pointType *points, const scaleDataType scaleData,
                                                    size_t size);

// изменение координат точек для поворота
error_type modelTurn(pointType *points, const turnDataType turnData,
                                                size_t size);

#endif // MODELTRANSFORM_H

