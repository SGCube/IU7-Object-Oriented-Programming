#ifndef CANVAS_CPP
#define CANVAS_CPP

#include "canvas.h"
#include "canvascoord.h"
#include "../gui/window.h"

ErrorType getLineCoord(const VertexType startVertex, const VertexType endVertex)
{
    const double startX = getCanvasX(startVertex.x, startVertex.z);
    const double startY = getCanvasY(startVertex.y, startVertex.z);
    const double endX = getCanvasX(endVertex.x, endVertex.z);
    const double endY = getCanvasY(endVertex.y, endVertex.z);
    return addLine(startX, startY, endX, endY);
}

ErrorType modelDraw(const EdgeType* edges, const VertexType* vertices,
					const unsigned int edgesSize)
{
	ErrorType error = checkVerticesExist(vertices);
	if (error != OK)
        return error;
	error = checkEdgesExist(edges);
	if (error != OK)
		return error;

    for (unsigned int i = 0; error == OK && i < edgesSize; i++)
	{
		int startVertexNo = edges[i].startVertexNo;
		int endVertexNo = edges[i].endVertexNo;
        error = getLineCoord(vertices[startVertexNo], vertices[endVertexNo]);
	}
    return error;
}

#endif // CANVAS_CPP
