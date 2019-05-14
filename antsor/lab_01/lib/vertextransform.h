#ifndef VERTEXTRANSFORM_H
#define VERTEXTRANSFORM_H

#include "error.h"
#include "vertex.h"

double moveCoord(const double coord, const double offset);

double scaleCoord(const double coord, const double coeff, const double center);

ErrorType rotateCoord(VertexType &vertex, const VertexType center,
					  const double angle);

double coordProjectParallel();

double coordProjectCentralAxis();

double coordProjectCentral(double coord, double axis, double distance);

#endif // VERTEXTRANSFORM_H
