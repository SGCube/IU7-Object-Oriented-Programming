#ifndef DRAW_CPP
#define DRAW_CPP

#include "draw.h"

#define Z_COEFF 0.5

double getCanvasX(double x, double z)
{
    return x + z * Z_COEFF;
}

double getCanvasY(double y, double z)
{
    return -y - z * Z_COEFF;
}

ErrorType getVertexCoord(const VertexType vertex, double vertexToDraw[2])
{
	if (!vertexToDraw)
		return ERROR_ALLOCATION;
	vertexToDraw[0] = getCanvasX(vertex.x, vertex.z);
	vertexToDraw[1] = getCanvasY(vertex.y, vertex.z);
    return OK;
}

ErrorType pointsToDrawAlloc(double** &pointsToDraw, size_t& pointsAmount,
							size_t newSize)
{
	pointsToDraw = new double*[newSize];
	if (!pointsToDraw)
		return ERROR_ALLOCATION;
	pointsAmount = newSize;
	return OK;
}

ErrorType modelDraw(const EdgeType* edges, const VertexType* vertices,
					const size_t edgesSize, DrawParamType& param)
{
	ErrorType error = checkVerticesExist(vertices);
	if (error == OK)
		error = checkEdgesExist(edges);
	if (error != OK)
		return error;
	
	error = pointsToDrawAlloc(param.pointsToDraw, param.pointsAmount,
							  edgesSize * 2);
	if (error != OK)
		return error;

    for (size_t i = 0, j = 0; error == OK && i < edgesSize; i++, j += 2)
	{
		int startNo = edges[i].startVertexNo;
		int endNo = edges[i].endVertexNo;
		
		param.pointsToDraw[j] = new double[2];
		param.pointsToDraw[j + 1] = new double[2];
		
        error = getVertexCoord(vertices[startNo], param.pointsToDraw[j]);
		error = getVertexCoord(vertices[endNo], param.pointsToDraw[j + 1]);
	}
    return error;
}

#endif // DRAW_CPP
