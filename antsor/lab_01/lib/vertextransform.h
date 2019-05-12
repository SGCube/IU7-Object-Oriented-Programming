#ifndef VERTEXTRANSFORM_H
#define VERTEXTRANSFORM_H

#include "error.h"
#include "vertex.h"
#include "actionparam.h"

double degreesToRadians(const int angle);

double move(const double coord, const double offset);

double scale(const double coord, const double coeff, const double center);

ErrorType rotateCoord(VertexType &vertex, const VertexType center,
				   const double angle);

ErrorType rotateX(VertexType* vertices, const size_t size,
				  const RotateParamType param);

ErrorType rotateY(VertexType* vertices, const size_t size,
				  const RotateParamType param);

ErrorType rotateZ(VertexType* vertices, const size_t size,
				  const RotateParamType param);

#endif // VERTEXTRANSFORM_H
