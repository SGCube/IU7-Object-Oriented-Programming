#ifndef EDGEARRAY_CPP
#define EDGEARRAY_CPP

#include "edgearray.h"

// initialize edge array
EdgeArrayType initializeEdgeArray()
{
	EdgeArrayType edgeArray;
	edgeArray.edges = nullptr;
	edgeArray.size = 0;
	return edgeArray;
}

// free edge array
ErrorType freeEdgeArray(EdgeArrayType& edgeArray)
{
	ErrorType error = freeEdges(edgeArray.edges);
	if (error == OK)
		edgeArray = initializeEdgeArray();
	return error;
}

// load edge array
ErrorType loadEdgeArray(EdgeArrayType& edgeArray, FileWorkType file)
{
	ErrorType error = getArraySize(edgeArray.size, file.f);
	if (error == OK)
	{
		error = allocateEdges(edgeArray.edges, edgeArray.size);
		if (error == OK)
		{
			error = loadEdges(edgeArray.edges, edgeArray.size, file);
			if (error != OK)
				freeEdges(edgeArray.edges);
		}
	}
	return error;
}

// save edge array
ErrorType saveEdgeArray(const EdgeArrayType edgeArray, FileWorkType file)
{
	ErrorType error = checkEdgesExist(edgeArray.edges);
	if (error == OK)
	{
		error = setArraySize(edgeArray.size, file.f);
		if (error == OK)
			error = saveEdges(edgeArray.edges, edgeArray.size, file);
	}
	return error;
}

#endif // EDGEARRAY_CPP

