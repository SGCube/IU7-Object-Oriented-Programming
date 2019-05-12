#ifndef VERTEXTRANSFORM_CPP
#define VERTEXTRANSFORM_CPP

#include <math.h>

#include "error.h"
#include "vertex.h"
#include "actionparam.h"
#include "vertextransform.h"

double degreesToRadians(const int angle)
{
	return angle * M_PI / 180;
}

double move(const double coord, const double offset)
{
	return coord + offset;
}

double scale(const double coord, const double coeff, const double center)
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

ErrorType rotateX(VertexType* vertices, const size_t size,
				  const RotateParamType param)
{
	ErrorType error = checkVerticesExist(vertices);
    if (error != OK)
	{
        return error;
	}

	double radians = degreesToRadians(param.angle);
	VertexType center = { param.yc, param.zc, 0 };

	for (size_t i = 0; i < size; i++)
	{
		VertexType vertex = { vertices[i].y, vertices[i].z, 0 };
		rotateCoord(vertex, center, radians);
		vertices[i].y = vertex.x;
		vertices[i].z = vertex.y;
	}
	
	return OK;
}

ErrorType rotateY(VertexType* vertices, const size_t size,
				  const RotateParamType param)
{
	ErrorType error = checkVerticesExist(vertices);
    if (error != OK)
	{
        return error;
	}

	double radians = degreesToRadians(param.angle);
	VertexType center = { param.zc, param.xc, 0 };

	for (size_t i = 0; i < size; i++)
	{
		VertexType vertex = { vertices[i].z, vertices[i].x, 0 };
		rotateCoord(vertex, center, radians);
		vertices[i].z = vertex.x;
		vertices[i].x = vertex.y;
	}
	
	return OK;
}

ErrorType rotateZ(VertexType* vertices, const size_t size,
				  const RotateParamType param)
{
	ErrorType error = checkVerticesExist(vertices);
    if (error != OK)
	{
        return error;
	}

	double radians = degreesToRadians(param.angle);
	VertexType center = { param.xc, param.yc, 0 };

	for (size_t i = 0; i < size; i++)
	{
		VertexType vertex = { vertices[i].x, vertices[i].y, 0 };
		rotateCoord(vertex, center, radians);
		vertices[i].x = vertex.x;
		vertices[i].y = vertex.y;
	}
	
	return OK;
}

#endif // VERTEXTRANSFORM_CPP
