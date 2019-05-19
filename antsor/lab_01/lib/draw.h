#ifndef CANVAS_H
#define CANVAS_H

#include "error.h"
#include "vertexarray.h"
#include "edgearray.h"
#include "actionparam.h"

double getCanvasX(const double x, const double y);

double getCanvasY(const double z, const double y);

ErrorType getVertexCoord(const VertexType vertex, double* xToDraw,
						 double* yToDraw, int index);

ErrorType pointsToDrawAlloc(double** pointsToDraw, size_t* size, size_t newSize);

ErrorType pointsToDrawFree(double* pointsToDraw);

ErrorType verticesDrawCoord(const EdgeType* edges, const VertexType* vertices,
							size_t size, DrawParamType& param);

ErrorType modelDraw(const EdgeArrayType& edges, const VertexArrayType& vertices,
					DrawParamType& param);

#endif // CANVAS_H
