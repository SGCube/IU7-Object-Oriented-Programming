#ifndef EDGEARRAY_CPP
#define EDGEARRAY_CPP

#include "edgearray.h"

// initialize edge array
ErrorType initializeEdgeArray(EdgeArrayType& edgeArray)
{
	edgeArray.vertices = nullptr;
	edgeArray.size = 0;
	return OK;
}

// free edge array
ErrorType freeEdgeArray(EdgeArrayType& edgeArray)
{
	ErrorType error = freeEdges(edgeArray.edges);
	if (error != OK)
		return error;
	return initializeEdgeArray(edgeArray);
}

// load edge array
ErrorType loadEdgeArray(EdgeArrayType& edgeArray, FileWorkType file)
{
	ErrorType error = getArraySize(edgeArray.size, file.f);
	if (error != OK)
		return error;
	
	error = allocateEdges(edgeArray.edges, edgeArray.size);
	if (error != OK)
		return error;
	
	return loadEdges(edgeArray.edges, edgeArray.size, file);
}

// save edge array
ErrorType saveEdgeArray(const EdgeArrayType edgeArray, FileWorkType file)
{
	ErrorType error = checkEdgesExist(edgeArray.edges);
	if (error != OK)
		return error;
	
	error = setArraySize(edgeArray.size, file.f);
	if (error != OK)
		return error;
	
	return saveEdges(edgeArray.edges, edgeArray.size, file);
}

#endif // EDGEARRAY_CPP

