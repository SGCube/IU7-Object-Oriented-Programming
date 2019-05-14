#ifndef CANVAS_H
#define CANVAS_H

#include "error.h"
#include "vertexarray.h"
#include "edgearray.h"
#include "actionparam.h"

double getCanvasX(const double x, const double z);

double getCanvasY(const double y, const double z);

ErrorType getVertexCoord(const VertexType vertex, double vertexToDraw[2]);

ErrorType modelDraw(const EdgeType* edges, const VertexType* vertices,
					const size_t edgesSize, DrawParamType& param);

ErrorType pointsToDrawAlloc(double** &pointsToDraw, size_t& pointsAmount,
							size_t newSize);

#endif // CANVAS_H
