#ifndef PROJECTION_H
#define PROJECTION_H

#define SIZE_SCREEN 300
#define OFFSET 0

#include "vertex.h"
#include "actionparam.h"

// set coordinates to zero belonging one of axis for parallel projection
double coordProjectParallel();

// parallel projection
ErrorType projectParallelModel(VertexType* vertices, const size_t size,
							   AxisType axis);

// set coordinates to zero belonging one of axis for central projection
double coordProjectCentralAxis();

// set coordinates by distance for central projection
double coordProjectCentral(const double coord, const double axis,
						   const double distance);

// central projection with viewer at axis X
ErrorType projectCentralX(VertexType* vertices, const size_t size,
					const double distance);

// central projection with viewer at axis Y
ErrorType projectCentralY(VertexType* vertices, const size_t size,
					const double distance);

// central projection with viewer at axis Z
ErrorType projectCentralZ(VertexType* vertices, const size_t size,
					const double distance);

#endif // PROJECTION_H
