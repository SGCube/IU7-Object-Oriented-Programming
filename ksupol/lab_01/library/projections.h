#ifndef PROJECTIONP_H
#define PROJECTIONP_H

#define SIZE_SCREEN 300
#define OFFSET 0

#include "node.h"

int projectionP();

error_type projectPX(nodeType* nodes, const unsigned int size);

error_type projectPY(nodeType* nodes, const unsigned int size);

error_type projectPZ(nodeType* nodes, const unsigned int size);

double projectCAxis();

double projectC(const double coord, const double axis, const double distance);

error_type projectCX(nodeType* nodes, const unsigned int size, const double d);

error_type projectCY(nodeType* nodes, const unsigned int size, const double d);

error_type projectCZ(nodeType* nodes, const unsigned int size, const double d);

#endif // PROJECTIONP_H

