#ifndef CANVAS_CPP
#define CANVAS_CPP

#include "canvas.h"
#include "../gui/window.h"

#define Z_COEFF 0.5

double getCanvasX(const double x, const double z)
{
    return x + z * Z_COEFF;
}

double getCanvasY(const double y, const double z)
{
    return -y - z * Z_COEFF;
}

ErrorType getLineCoord(const VertexType startVertex, const VertexType endVertex)
{
    const double startX = getCanvasX(startVertex.x, startVertex.z);
    const double startY = getCanvasY(startVertex.y, startVertex.z);
    const double endX = getCanvasX(endVertex.x, endVertex.z);
    const double endY = getCanvasY(endVertex.y, endVertex.z);
    return addLine(startX, startY, endX, endY);
}

ErrorType modelDraw(const EdgeType* edges, const VertexType* vertices,
					const size_t edgesSize)
{
	ErrorType error = checkVerticesExist(vertices);
	if (error != OK)
        return error;
	error = checkEdgesExist(edges);
	if (error != OK)
		return error;

    for (size_t i = 0; error == OK && i < edgesSize; i++)
	{
		int startVertexNo = edges[i].startVertexNo;
		int endVertexNo = edges[i].endVertexNo;
        error = getLineCoord(vertices[startVertexNo], vertices[endVertexNo]);
	}
    return error;
}

#endif // CANVAS_CPP
