#ifndef VERTEXTRANSFORM_CPP
#define VERTEXTRANSFORM_CPP

#include <math.h>

#include "error.h"
#include "vertex.h"
#include "vertextransform.h"

double moveCoord(const double coord, const double offset)
{
	return coord + offset;
}

double scaleCoord(const double coord, const double coeff, const double center)
{
	return center + coeff * (coord - center);
}

ErrorType rotateCoord(VertexType &vertex, const VertexType center,
					  const double angle)
{
	double coord1 = vertex.x;
	double coord2 = vertex.y;
	vertex.x = center.x + (coord1 - center.x) * cos(angle) +
			(coord2 - center.y) * sin(angle);
	vertex.y = center.y - (coord1 - center.x) * sin(angle) +
			(coord2 - center.y) * cos(angle);
	return OK;
}

double coordProjectParallel()
{
    return 0;
}

double coordProjectCentralAxis()
{
    return 0;
}

double coordProjectCentral(double coord, double axis, double distance)
{
    return coord * distance / (axis + distance);
}

#endif // VERTEXTRANSFORM_CPP
