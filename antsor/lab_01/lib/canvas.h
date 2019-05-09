#ifndef CANVAS_H
#define CANVAS_H

#include "error.h"
#include "vertexarray.h"
#include "edgearray.h"

ErrorType getLineCoord(const VertexType startVertex, const VertexType endVertex);

ErrorType drawCanvas(const EdgeType* edges, const VertexType* vertices,
					 const unsigned int edgesSize);

#endif // CANVAS_H
