#ifndef EDGE_CPP
#define EDGE_CPP

#include "edge.h"

bool edgesIsExist(type_edge* edges)
{
    if (edges)
        return true;
    return false;
}

error_type checkEdgesExist(type_edge* edges)
{
    return edgesIsExist(edges) ? OK : ErrorEdgesExist;
}

error_type edgesAllocation(type_edge*& edges, unsigned int size)
{
    if (edges != NULL && edgesFree(edges))
        return ErrorFree;

    edges = new type_edge[size];

    if (edgesIsExist(edges))
        return OK;
    return ErrorAllocation;
}

error_type edgesFree(type_edge *&edges)
{
    if (edgesIsExist(edges))
        delete [] edges;

    return OK;
}

error_type edgeLoad(unsigned int& edgeSrc, unsigned int& edgePurp, fileWorkType file)
{
    error_type error = getEdgeData(edgeSrc, file.f);
    if (error)
        return error;

    return getEdgeData(edgePurp, file.f);
}

error_type edgeSave(fileWorkType file, const unsigned int edgeSrc, const unsigned int edgePurp)
{
    error_type error = setEdgeData(file.f, edgeSrc);
    if (error)
        return error;

    return setEdgeData(file.f, edgePurp);
}

error_type edgesLoad(type_edge* edges, fileWorkType file, size_t size)
{
    error_type error = checkEdgesExist(edges);
    if (error)
        return error;

    for (unsigned int i = 0; i < size && error == OK; i++)
        error = edgeLoad(edges[i].src, edges[i].purp, file);

    return error;
}

error_type edgesSave(type_edge* edges, fileWorkType file, size_t size)
{
    error_type error = checkEdgesExist(edges);
    if (error)
        return error;

    for (unsigned int i = 0; i < size && error == OK; i++)
        error = edgeSave(file, edges[i].src, edges[i].purp);

    return error;
}

#endif // EDGE_CPP

