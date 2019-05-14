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

ErrorType getVertexCoord(const VertexType vertex, double* vertexToDraw)
{
	if (!vertexToDraw)
		return ERROR_ALLOCATION;
	vertexToDraw[0] = getCanvasX(vertex.x, vertex.y);
	vertexToDraw[1] = getCanvasY(vertex.z, vertex.y);
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
