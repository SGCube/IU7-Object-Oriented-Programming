#ifndef MODELTRANSFORM_H
#define MODELTRANSFORM_H

#include "errors.h"
#include "model_data_work.h"
#include "node.h"
#include "transformations.h"

// изменение координат точек для переноса
error_type modelShift(nodeType *nodes, const struct shiftDataType shiftData, \
                     const unsigned int size);

// изменение координат точек для масштабирования
error_type modelScale(nodeType *nodes, const struct scaleDataType scaleData, \
                     const unsigned int size);

// изменение координат точек для поворота
error_type modelTurn(nodeType *nodes, const struct turnDataType turnData, \
                     const unsigned int size);

#endif // MODELTRANSFORM_H

