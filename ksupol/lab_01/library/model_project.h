#ifndef MODELPROJECT_H
#define MODELPROJECT_H

#include "errors.h"
#include "model_data_work.h"
#include "node.h"
#include "projections.h"

// изменение координат пересечений для параллельного проецирования
error_type modelProjectP(nodeType *nodes, const struct projectPDataType \
                        projectPData, const unsigned int size);

// изменение координат пересечений для центрального проецирования
error_type modelProjectC(nodeType* nodes, const struct projectCDataType \
                        projectCData, const unsigned int size);

#endif // MODELPROJECT_H

