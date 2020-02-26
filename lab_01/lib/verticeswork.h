#ifndef MODELWORK_H
#define MODELWORK_H

#include "error.h"
#include "vertex.h"
#include "actionparam.h"

double degreesToRadians(const int angle);

ErrorType moveVertices(VertexType* vertices, const size_t size,
					   const MoveParamType& param);

ErrorType scaleVertices(VertexType* vertices, const size_t size,
						const ScaleParamType& param);

ErrorType rotateX(VertexType* vertices, const size_t size,
				  const RotateParamType param);

ErrorType rotateY(VertexType* vertices, const size_t size,
				  const RotateParamType param);

ErrorType rotateZ(VertexType* vertices, const size_t size,
				  const RotateParamType param);

ErrorType projectParallel(VertexType* vertices, const size_t size,
						  AxisType axis);

ErrorType projectCentralX(VertexType* vertices, const size_t size,
						  const double distance);

ErrorType projectCentralY(VertexType* vertices, const size_t size,
						  const double distance);

ErrorType projectCentralZ(VertexType* vertices, const size_t size,
						  const double distance);

#endif // MODELWORK_H
