#ifndef EDGE_H
#define EDGE_H

#include "error.h"
#include "filework.h"

#include <stdio.h>

// type of edge
struct EdgeType
{
    size_t startVertexNo;
    size_t endVertexNo;
};

// load edge data
ErrorType loadEdge(size_t& edgeStart, size_t& edgeEnd,
				   FileWorkType file);

// save edge data
ErrorType saveEdge(size_t edgeStart, size_t edgeEnd,
				   FileWorkType file);

// allocate memory for edge array
ErrorType allocateEdges(EdgeType*& edges, const size_t size);

// free memory of edge array
ErrorType freeEdges(EdgeType*& edges);

// check if edges exist
ErrorType checkEdgesExist(const EdgeType* edges);

// load edge array data
ErrorType loadEdges(EdgeType* edges, const size_t size,
					FileWorkType file);

// save edge array data
ErrorType saveEdges(EdgeType* edges, const size_t size,
					FileWorkType file);

#endif // EDGE_H

