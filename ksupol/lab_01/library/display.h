#ifndef DISPLAY_H
#define DISPLAY_H

#include "../gui/widget.h"
#include "errors.h"
#include "edge_array.h"
#include "point_array.h"
#include "display_work.h"

error_type getCoordForDrawLine(pointType* points, int src, int purp);

error_type drawDisplay(type_edge* edges, pointType* points,
                                            size_t size);

#endif // DISPLAY_H

