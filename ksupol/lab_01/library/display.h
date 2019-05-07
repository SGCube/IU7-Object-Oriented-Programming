#ifndef DISPLAY_H
#define DISPLAY_H

#include "../gui/widget.h"
#include "errors.h"
#include "edge_array.h"
#include "node_array.h"
#include "display_work.h"

error_type getCoordForDrawLine(const nodeType* nodes, const int src, const int purp);

error_type drawDisplay(const type_edge* edges, const nodeType* nodes, \
                      const unsigned int size);

#endif // DISPLAY_H

