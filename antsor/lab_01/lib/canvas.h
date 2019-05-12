#ifndef CANVAS_H
#define CANVAS_H

#include "error.h"
#include "vertexarray.h"
#include "edgearray.h"

double getCanvasX(const double x, const double z);

double getCanvasY(const double y, const double z);

ErrorType getLineCoord(const VertexType startVertex, const VertexType endVertex);

ErrorType modelDraw(const EdgeType* edges, const VertexType* vertices,
					 const size_t edgesSize);

#endif // CANVAS_H
