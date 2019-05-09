#ifndef VERTEXTRANSFORM_CPP
#define VERTEXTRANSFORM_CPP

#include <math.h>

#include "error.h"
#include "vertex.h"
#include "actionparam.h"

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

ErrorType rotateX(VertexType* vertices, const unsigned int size,
				  const RotateParamType param)
{
	ErrorType error = checkVerticesExist(vertices);
    if (error != OK)
        return error;

	double radians = degreesToRadians(param.angle);
	double angleCos = cos(radians), angleSin = sin(radians);

	for (unsigned int i = 0; i < size; i++)
	{
		double tmpY = vertices[i].y;
		double tmpZ = vertices[i].z;

		vertices[i].y = param.yc + (tmpY - param.yc) * angleCos +
				(tmpZ - param.zc) * angleSin;
		vertices[i].z = param.zc - (tmpY - param.yc) * angleSin +
				(tmpZ - param.zc) * angleCos;
	}
	return OK;
}

ErrorType rotateY(VertexType* vertices, const unsigned int size,
				  const RotateParamType param)
{
	ErrorType error = checkVerticesExist(vertices);
    if (error != OK)
        return error;

	double radians = degreesToRadians(param.angle);
	double angleCos = cos(radians), angleSin = sin(radians);

	for (unsigned int i = 0; i < size; i++)
	{
		double tmpZ = vertices[i].z;
		double tmpX = vertices[i].x;

		vertices[i].z = param.zc + (tmpZ - param.zc) * angleCos +
				(tmpX - param.xc) * angleSin;
		vertices[i].x = param.xc - (tmpZ - param.zc) * angleSin +
				(tmpX - param.xc) * angleCos;
	}
	return OK;
}

ErrorType rotateZ(VertexType* vertices, const unsigned int size,
				  const RotateParamType param)
{
	ErrorType error = checkVerticesExist(vertices);
    if (error != OK)
        return error;

	double radians = degreesToRadians(param.angle);
	double angleCos = cos(radians), angleSin = sin(radians);

	for (unsigned int i = 0; i < size; i++)
	{
		double tmpX = vertices[i].x;
		double tmpY = vertices[i].y;

		vertices[i].x = param.xc + (tmpX - param.xc) * angleCos +
				(tmpY - param.yc) * angleSin;
		vertices[i].y = param.yc - (tmpX - param.xc) * angleSin +
				(tmpY - param.yc) * angleCos;
	}
	return OK;
}

#endif // VERTEXTRANSFORM_CPP
