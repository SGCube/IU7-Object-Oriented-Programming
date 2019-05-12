#ifndef EDGEARRAY_H
#define EDGEARRAY_H

#include "error.h"
#include "edge.h"
#include "filework.h"

// type of edge array
struct EdgeArrayType
{
    EdgeType* edges;
    size_t size;
};

// initialize edge array
ErrorType initializeEdgeArray(EdgeArrayType& edgeArray);

// free edge array
ErrorType freeEdgeArray(EdgeArrayType& edgeArray);

// load edge array
ErrorType loadEdgeArray(EdgeArrayType& edgeArray, FileWorkType file);

// save edge array
ErrorType saveEdgeArray(const EdgeArrayType edgeArray, FileWorkType file);

#endif // EDGEARRAY_H

