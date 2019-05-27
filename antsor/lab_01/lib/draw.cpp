#ifndef DRAW_CPP
#define DRAW_CPP

#include "draw.h"

#define Y_COEFF 0.5

double getCanvasX(double x, double y)
{
    return x + y * Y_COEFF;
}

double getCanvasY(double z, double y)
{
    return -z - y * Y_COEFF;
}

ErrorType getVertexCoord(const VertexType vertex, double* xToDraw,
						 double* yToDraw, int index)
{
	xToDraw[index] = getCanvasX(vertex.x, vertex.y);
	yToDraw[index] = getCanvasY(vertex.z, vertex.y);
    return OK;
}

ErrorType pointsToDrawAlloc(double** pointsToDraw, size_t* size, size_t newSize)
{
	*pointsToDraw = new double[newSize];
	if (!*pointsToDraw)
		return ERROR_ALLOCATION;
	*size = newSize;
	return OK;
}

ErrorType pointsToDrawFree(double *pointsToDraw)
{
	if (pointsToDraw)
		delete [] pointsToDraw;
	return OK;
}

ErrorType verticesDrawCoord(const EdgeType* edges, const VertexType* vertices,
							size_t size, DrawParamType& param)
{
	ErrorType error = OK;
	for (size_t i = 0, j = 0; error == OK && i < size; i++, j += 2)
	{
		int startNo = edges[i].startVertexNo;
		int endNo = edges[i].endVertexNo;
		
        error = getVertexCoord(vertices[startNo], *(param.xToDraw),
							   *(param.yToDraw), j);
		error = getVertexCoord(vertices[endNo], *(param.xToDraw),
							   *(param.yToDraw), j + 1);
	}
    return error;
}

ErrorType modelDraw(const EdgeArrayType& edges, const VertexArrayType& vertices,
					DrawParamType& param)
{
	ErrorType error = checkVerticesExist(vertices.vertices);
	if (error == OK)
		error = checkEdgesExist(edges.edges);
	if (error != OK)
		return error;
	
	error = pointsToDrawAlloc(param.xToDraw, param.size, edges.size * 2);
	if (error == OK)
	{
		error = pointsToDrawAlloc(param.yToDraw, param.size, edges.size * 2);
		if (error == OK)
			error = verticesDrawCoord(edges.edges, vertices.vertices,
									  edges.size, param);
		else
			pointsToDrawFree(*(param.xToDraw));
	}
		
    return error;
}

#endif // DRAW_CPP
