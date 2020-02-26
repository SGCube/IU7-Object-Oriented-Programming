#ifndef MODELWORK_CPP
#define MODELWORK_CPP

#include "verticeswork.h"
#include "vertextransform.h"

#include <math.h>

double degreesToRadians(const int angle)
{
	return angle * M_PI / 180;
}

ErrorType moveVertices(VertexType* vertices, const size_t size,
					   const MoveParamType& param)
{
	ErrorType error = checkVerticesExist(vertices);
    if (error != OK)
        return error;

    for (size_t i = 0; i < size; i++)
    {
        vertices[i].x = moveCoord(vertices[i].x, param.dx);
        vertices[i].y = moveCoord(vertices[i].y, param.dy);
        vertices[i].z = moveCoord(vertices[i].z, param.dz);
    }
    return OK;
}

ErrorType scaleVertices(VertexType* vertices, const size_t size,
						const ScaleParamType& param)
{
	ErrorType error = checkVerticesExist(vertices);
    if (error != OK)
        return error;

    for (size_t i = 0; i < size; i++)
    {
        vertices[i].x = scaleCoord(vertices[i].x, param.kx, param.xc);
        vertices[i].y = scaleCoord(vertices[i].y, param.ky, param.yc);
        vertices[i].z = scaleCoord(vertices[i].z, param.kz, param.zc);
    }
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
		rotateCoord(vertex, center, -radians);
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

ErrorType projectParallel(VertexType* vertices, const size_t size,
						  AxisType axis)
{
    ErrorType error = checkVerticesExist(vertices);
	if (error != OK)
        return error;

    for (size_t i = 0; i < size; i++)
	{
		switch (axis)
		{
			case X:
				vertices[i].x = coordProjectParallel();
				break;
			case Y:
				vertices[i].y = coordProjectParallel();
				break;
			case Z:
				vertices[i].z = coordProjectParallel();
				break;
			default:
				return ERROR_AXIS;
				break;
		}
	}

    return OK;
}

ErrorType projectCentralX(VertexType* vertices, const size_t size,
						  const double distance)
{
	ErrorType error = checkVerticesExist(vertices);
	if (error != OK)
        return error;

    for (size_t i = 0; i < size; i++)
    {
        vertices[i].x = coordProjectCentral(vertices[i].x, vertices[i].z,
											distance);
        vertices[i].y = coordProjectCentral(vertices[i].y, vertices[i].z,
											distance);
        vertices[i].z = coordProjectCentralAxis();
    }

    return OK;
}

ErrorType projectCentralY(VertexType* vertices, const size_t size,
						  const double distance)
{
	ErrorType error = checkVerticesExist(vertices);
	if (error != OK)
        return error;

    for (size_t i = 0; i < size; i++)
    {
        vertices[i].y = coordProjectCentral(vertices[i].y, vertices[i].x,
											distance);
        vertices[i].z = coordProjectCentral(vertices[i].z, vertices[i].x,
											distance);
        vertices[i].x = coordProjectCentralAxis();
    }

    return OK;
}

ErrorType projectCentralZ(VertexType* vertices, const size_t size,
						  const double distance)
{
	ErrorType error = checkVerticesExist(vertices);
	if (error != OK)
        return error;

    for (size_t i = 0; i < size; i++)
    {
        vertices[i].z = coordProjectCentral(vertices[i].z, vertices[i].y,
											distance);
        vertices[i].x = coordProjectCentral(vertices[i].x, vertices[i].y,
											distance);
        vertices[i].y = coordProjectCentralAxis();
    }

    return OK;
}

#endif // VERTEXWORK_CPP
