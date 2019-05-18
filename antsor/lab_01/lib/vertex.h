#ifndef VERTEX_H
#define VERTEX_H

#include "error.h"
#include "filework.h"

#include <stdio.h>

// vertex model type
struct VertexType
{
    double x;
    double y;
    double z;
};

// vertex fields type
enum VertexFieldType
{
    FIELD_X,
    FIELD_Y,
    FIELD_Z
};

// load vertex data
ErrorType loadVertex(VertexType& vertex, FileWorkType file);

// save vertex data
ErrorType saveVertex(const VertexType& vertex, FileWorkType file);

// allocate memory for vertex array
ErrorType allocateVertices(VertexType*& vertices, const size_t size);

// free memory of vertex array
ErrorType freeVertices(VertexType*& vertices);

// check if vertices exist
ErrorType checkVerticesExist(const VertexType* vertices);

// load vertex array data
ErrorType loadVertices(VertexType* vertices, const size_t size,
					   FileWorkType file);

// save vertex array data
ErrorType saveVertices(VertexType* vertices, const size_t size,
					   FileWorkType file);

#endif // VERTEX_H

