#ifndef VERTEXARRAY_CPP
#define VERTEXARRAY_CPP

#include "vertexarray.h"

ErrorType initializeVertexArray(VertexArrayType& vertexArray)
{
	vertexArray.vertices = nullptr;
	vertexArray.size = 0;
	return OK;
}

ErrorType freeVertexArray(VertexArrayType& vertexArray)
{
	ErrorType error = freeVertices(vertexArray.vertices);
	if (error != OK)
		return error;
	return initializeVertexArray(vertexArray);
}

ErrorType loadVertexArray(VertexArrayType& vertexArray, FileWorkType file)
{
	ErrorType error = getArraySize(vertexArray.size, file.f);
	if (error != OK)
		return error;
	
	error = allocateVertices(vertexArray.vertices, vertexArray.size);
	if (error != OK)
		return error;
	
	return loadVertices(vertexArray.vertices, vertexArray.size, file);
}

ErrorType saveVertexArray(const VertexArrayType& vertexArray,
						  FileWorkType file)
{
	ErrorType error = checkVerticesExist(vertexArray.vertices);
	if (error != OK)
		return error;
	
	error = setArraySize(vertexArray.size, file.f);
	if (error != OK)
		return error;
	
	return saveVertices(vertexArray.vertices, vertexArray.size, file);
}

#endif // VERTEXARRAY_CPP

