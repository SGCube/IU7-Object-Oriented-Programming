#ifndef VERTEX_CPP
#define VERTEX_CPP

#include "vertex.h"

// load vertex data
ErrorType loadVertex(VertexType& vertex, FileWorkType file)
{
	ErrorType error = getVertexData(vertex.x, file.f);
	if (error == OK)
	{
		error = getVertexData(vertex.y, file.f);
		if (error == OK)
			error = getVertexData(vertex.z, file.f);
	}
	return error;
}

// save vertex data
ErrorType saveVertex(const VertexType& vertex, FileWorkType file)
{
	ErrorType error = setVertexData(vertex.x, file.f);
	if (error == OK)
	{
		error = setVertexData(vertex.y, file.f);
		if (error == OK)
			error = setVertexData(vertex.z, file.f);
	}
	return error;
}

// allocate memory for vertex array
ErrorType allocateVertices(VertexType*& vertices, const size_t size)
{
	if (vertices && freeVertices(vertices))
		return ERROR_FREE;
	vertices = new VertexType[size];
	if (!vertices)
		return ERROR_ALLOCATION;
	return OK;
}

// free memory of vertex array
ErrorType freeVertices(VertexType*& vertices)
{
	if (vertices)
        delete [] vertices;
    return OK;
}

// check if vertices exist
ErrorType checkVerticesExist(const VertexType* vertices)
{
    return vertices ? OK : ERROR_VERTICES_EXIST;
}

// load vertex array data
ErrorType loadVertices(VertexType* vertices, const size_t size,
					   FileWorkType file)
{
	ErrorType error = checkVerticesExist(vertices);
	if (error != OK)
		return error;
	
	for (size_t i = 0; error == OK && i < size; i++)
		error = loadVertex(vertices[i], file);
	return error;
}

// save vertex array data
ErrorType saveVertices(VertexType* vertices, const size_t size,
					   FileWorkType file)
{
	ErrorType error = checkVerticesExist(vertices);
	if (error != OK)
		return error;

	for (size_t i = 0; error == OK && i < size; i++)
		error = saveVertex(vertices[i], file);
	return error;
}

#endif // VERTEX_CPP

