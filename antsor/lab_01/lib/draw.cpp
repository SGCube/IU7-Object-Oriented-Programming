#ifndef DRAW_CPP
#define DRAW_CPP

#include "draw.h"

#define X_COEFF 0.5

double getCanvasX(double y, double x)
{
    return y - x * X_COEFF;
}

double getCanvasY(double z, double x)
{
    return -z + x * X_COEFF;
}

ErrorType getVertexCoord(const VertexType vertex, double* vertexToDraw)
{
	if (!vertexToDraw)
		return ERROR_ALLOCATION;
	vertexToDraw[0] = getCanvasX(vertex.y, vertex.x);
	vertexToDraw[1] = getCanvasY(vertex.z, vertex.x);
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

ErrorType verticesDrawCoord(const EdgeType* edges, const VertexType* vertices,
							const size_t edgesSize, double* pointsToDraw)
{
	ErrorType error = OK;
	for (size_t i = 0, j = 0; error == OK && i < edgesSize; i++, j += 4)
	{
		int startNo = edges[i].startVertexNo;
		int endNo = edges[i].endVertexNo;
		
        error = getVertexCoord(vertices[startNo], pointsToDraw + j);
		error = getVertexCoord(vertices[endNo], pointsToDraw + j + 2);
	}
    return error;
}

ErrorType modelDraw(const EdgeType* edges, const VertexType* vertices,
					const size_t edgesSize, DrawParamType& param)
{
	ErrorType error = checkVerticesExist(vertices);
	if (error == OK)
		error = checkEdgesExist(edges);
	if (error != OK)
		return error;
	
	error = pointsToDrawAlloc(param.pointsToDraw, param.size,
							  edgesSize * 4);
	if (error == OK)
		error = verticesDrawCoord(edges, vertices, edgesSize,
								  *(param.pointsToDraw));
    return error;
}

#endif // DRAW_CPP
