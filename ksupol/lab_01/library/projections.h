#ifndef PROJECTIONP_H
#define PROJECTIONP_H

#define SIZE_SCREEN 300
#define OFFSET 0

#include "point.h"

int projectionP();

error_type projectPX(pointType* points, const unsigned int size);

error_type projectPY(pointType* points, const unsigned int size);

error_type projectPZ(pointType* points, const unsigned int size);

double projectCAxis();

double projectC(const double coord, const double axis, const double distance);

error_type projectCX(pointType* points, const unsigned int size, const double d);

error_type projectCY(pointType* points, const unsigned int size, const double d);

error_type projectCZ(pointType* points, const unsigned int size, const double d);

#endif // PROJECTIONP_H

