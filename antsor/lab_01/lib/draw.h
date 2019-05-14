#ifndef CANVAS_H
#define CANVAS_H

#include "error.h"
#include "vertexarray.h"
#include "edgearray.h"
#include "actionparam.h"

double getCanvasX(const double y, const double x);

double getCanvasY(const double z, const double x);

ErrorType getVertexCoord(const VertexType vertex, double* vertexToDraw);

ErrorType pointsToDrawAlloc(double*** pointsToDraw, size_t* size, size_t newSize);

ErrorType verticesDrawCoord(const EdgeType* edges, const VertexType* vertices,
							const size_t edgesSize, double* pointsToDraw);

ErrorType modelDraw(const EdgeType* edges, const VertexType* vertices,
					const size_t edgesSize, DrawParamType& param);

#endif // CANVAS_H
