#ifndef VERTEXARRAY_CPP
#define VERTEXARRAY_CPP

#include "vertexarray.h"

VertexArrayType initializeVertexArray()
{
	VertexArrayType vertexArray;
	vertexArray.vertices = nullptr;
	vertexArray.size = 0;
	return vertexArray;
}

ErrorType freeVertexArray(VertexArrayType& vertexArray)
{
	ErrorType error = freeVertices(vertexArray.vertices);
	if (error == OK)
		vertexArray = initializeVertexArray();
	return error;
}

ErrorType loadVertexArray(VertexArrayType& vertexArray, FileWorkType file)
{
	ErrorType error = getArraySize(vertexArray.size, file.f);
	if (error == OK)
	{
		error = allocateVertices(vertexArray.vertices, vertexArray.size);
		if (error == OK)
		{
			error = loadVertices(vertexArray.vertices, vertexArray.size, file);
			if (error != OK)
				freeVertices(vertexArray.vertices);
		}
	}
	return error;
}

ErrorType saveVertexArray(const VertexArrayType& vertexArray,
						  FileWorkType file)
{
	ErrorType error = checkVerticesExist(vertexArray.vertices);
	if (error == OK)
	{
		error = setArraySize(vertexArray.size, file.f);
		if (error == OK)
			error = saveVertices(vertexArray.vertices, vertexArray.size, file);
	}
	return error;
}

#endif // VERTEXARRAY_CPP

