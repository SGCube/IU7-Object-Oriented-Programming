#ifndef EDGE_H
#define EDGE_H

#include "error.h"
#include "filework.h"

#include <stdio.h>

// type of edge
struct EdgeType
{
    unsigned int startVertexNo;
    unsigned int endVertexNo;
};

// load edge data
ErrorType loadEdge(unsigned int& edgeStart, unsigned int& edgeEnd,
				   FileWorkType file);

// save edge data
ErrorType saveEdge(unsigned int edgeStart, unsigned int edgeEnd,
				   FileWorkType file);

// allocate memory for edge array
ErrorType allocateEdges(EdgeType*& edges, const unsigned int size);

// free memory of edge array
ErrorType freeEdges(EdgeType*& edges);

// check if edges exist
ErrorType checkEdgesExist(const EdgeType* edges);

// load edge array data
ErrorType loadEdges(EdgeType* edges, const unsigned int size,
					FileWorkType file);

// save edge array data
ErrorType saveEdges(EdgeType* edges, const unsigned int size,
					FileWorkType file);

#endif // EDGE_H

