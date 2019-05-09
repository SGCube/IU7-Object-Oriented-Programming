#ifndef VERTEX_CPP
#define VERTEX_CPP

#include "vertex.h"

// load vertex data
ErrorType loadVertex(double& vertexX, double& vertexY, double& vertexZ,
					 FileWorkType file)
{
	ErrorType error = OK;
	
	error = getVertexData(vertexX, file.f);
	if (error != OK)
		return error;
	error = getVertexData(vertexY, file.f);
	if (error != OK)
		return error;
	error = getVertexData(vertexZ, file.f);
	if (error != OK)
		return error;
	
	return OK;
}

// save vertex data
ErrorType saveVertex(const double vertexX, const double vertexY,
					 const double vertexZ, FileWorkType file)
{
	ErrorType error = OK;
	
	error = setVertexData(vertexX, file.f);
	if (error != OK)
		return error;
	error = setVertexData(vertexY, file.f);
	if (error != OK)
		return error;
	error = setVertexData(vertexZ, file.f);
	if (error != OK)
		return error;
	
	return OK;
}

// allocate memory for vertex array
ErrorType allocateVertices(VertexType*& vertices, const unsigned int size)
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
ErrorType loadVertices(VertexType* vertices, const unsigned int size,
					   FileWorkType file)
{
	ErrorType error = OK;
	error = checkVerticesExist(vertices);
	if (error != OK)
		return error;
	
	for (unsigned int i = 0; error == OK && i < size; i++)
		error = loadVertex(vertices[i].x, vertices[i].y, vertices[i].z, file);
	return error;
}

// save vertex array data
ErrorType saveVertices(VertexType* vertices, const unsigned int size,
					   FileWorkType file)
{
	ErrorType error = OK;
	error = checkVerticesExist(vertices);
	if (error != OK)
		return error;

	for (unsigned int i = 0; error == OK && i < size; i++)
		error = saveVertex(vertices[i].x, vertices[i].y, vertices[i].z, file);
	return error;
}

#endif // VERTEX_CPP

