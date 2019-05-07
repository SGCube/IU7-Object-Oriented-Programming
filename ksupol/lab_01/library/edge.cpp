#ifndef EDGE_CPP
#define EDGE_CPP

#include "edge.h"

bool edgesIsExist(const type_edge* edges)
{
    return edges ? true : false;
}

error_type checkEdgesExist(const type_edge* edges)
{
    return edgesIsExist(edges) ? OK : ErrorEdgesExist;
}

error_type edgesAllocation(type_edge*& edges, const unsigned int size)
{
    if (edges != NULL && edgesFree(edges))
        return ErrorFree;

    edges = new type_edge[size];

    return edgesIsExist(edges) ? OK : ErrorAllocation;
}

error_type edgesFree(type_edge*& edges)
{
    if (edgesIsExist(edges))
        delete [] edges;

    return OK;
}

error_type edgeLoad(unsigned int& edgeSrc, unsigned int& edgePurp, fileWorkType file)
{
    error_type error;

    if ((error = getEdgeData(edgeSrc, file.f)))
        return error;

    return getEdgeData(edgePurp, file.f);
}

error_type edgeSave(fileWorkType file, const unsigned int edgeSrc, const unsigned int edgePurp)
{
    error_type error;

    if ((error = setEdgeData(file.f, edgeSrc)))
        return error;

    return setEdgeData(file.f, edgePurp);
}

error_type edgesLoad(type_edge* edges, fileWorkType file, const unsigned int size)
{
    error_type error;

    if ((error = checkEdgesExist(edges)))
        return error;

    for (unsigned int i = 0; i < size && error == OK; i++)
        error = edgeLoad(edges[i].src, edges[i].purp, file);

    return error;
}

error_type edgesSave(const type_edge* edges, fileWorkType file, const unsigned int size)
{
    error_type error;

    if ((error = checkEdgesExist(edges)))
        return error;

    for (unsigned int i = 0; i < size && error == OK; i++)
        error = edgeSave(file, edges[i].src, edges[i].purp);

    return error;
}

#endif // EDGE_CPP

