#ifndef PROJECTION_CPP
#define PROJECTION_CPP

#include "projection.h"

double coordProjectParallel()
{
    return 0;
}

ErrorType projectParallelModel(VertexType* vertices, const size_t size,
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

double coordProjectCentralAxis()
{
    return 0;
}

double coordProjectCentral(const double coord, const double axis,
						   const double distance)
{
    return coord * distance / (axis + distance);
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

#endif // PROJECTION_CPP

