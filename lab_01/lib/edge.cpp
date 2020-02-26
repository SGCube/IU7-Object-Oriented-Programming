#ifndef EDGE_CPP
#define EDGE_CPP

#include "edge.h"

// load edge data
ErrorType loadEdge(size_t& edgeStart, size_t& edgeEnd,
				   FileWorkType file)
{
	ErrorType error = getEdgeData(edgeStart, file.f);
	if (error == OK)
		error = getEdgeData(edgeEnd, file.f);
	return error;
}

// save edge data
ErrorType saveEdge(size_t edgeStart, size_t edgeEnd,
				   FileWorkType file)
{
	ErrorType error = setEdgeData(edgeStart, file.f);
	if (error == OK)
		error = setEdgeData(edgeEnd, file.f);
	return error;
}

// allocate memory for edge array
ErrorType allocateEdges(EdgeType*& edges, const size_t size)
{
	if (edges && freeEdges(edges))
		return ERROR_FREE;
	edges = new EdgeType[size];
	if (!edges)
		return ERROR_ALLOCATION;
	return OK;
}

// free memory of edge array
ErrorType freeEdges(EdgeType*& edges)
{
	if (edges)
        delete [] edges;
    return OK;
}

// check if edges exist
ErrorType checkEdgesExist(const EdgeType* edges)
{
	return edges ? OK : ERROR_EDGES_EXIST;
}

// load edge array data
ErrorType loadEdges(EdgeType* edges, const size_t size,
					FileWorkType file)
{
	ErrorType error = checkEdgesExist(edges);
	if (error != OK)
		return error;
	
	for (size_t i = 0; error == OK && i < size; i++)
		error = loadEdge(edges[i].startVertexNo, edges[i].endVertexNo, file);
	return error;
}

// save edge array data
ErrorType saveEdges(EdgeType* edges, const size_t size,
					FileWorkType file)
{
	ErrorType error = checkEdgesExist(edges);
	if (error != OK)
		return error;
	
	for (size_t i = 0; error == OK && i < size; i++)
		error = saveEdge(edges[i].startVertexNo, edges[i].endVertexNo, file);
	return error;
}


#endif // EDGE_CPP

