#ifndef VERTEXTRANSFORM_H
#define VERTEXTRANSFORM_H

#include "error.h"
#include "vertex.h"
#include "actionparam.h"

double degreesToRadians(const int angle);

double move(const double coord, const double offset);

double scale(const double coord, const double coeff, const double center);

ErrorType rotateX(VertexType* vertices, const unsigned int size,
				  const RotateParamType param);

ErrorType rotateY(VertexType* vertices, const unsigned int size,
				  const RotateParamType param);

ErrorType rotateZ(VertexType* vertices, const unsigned int size,
				  const RotateParamType param);

#endif // VERTEXTRANSFORM_H
