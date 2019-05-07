#ifndef PARALLPROJECTION_CPP
#define PARALLPROJECTION_CPP

#include "projections.h"

int projectionP()
{
    return 0;
}

error_type projectPX(nodeType* nodes, const unsigned int size)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
        nodes[i].x = projectionP();

    return OK;
}

error_type projectPY(nodeType* nodes, const unsigned int size)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
        nodes[i].y = projectionP();

    return OK;
}

error_type projectPZ(nodeType* nodes, const unsigned int size)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
        nodes[i].z = projectionP();

    return OK;
}

double projectCAxis()
{
    return 0;
}

double projectC(const double coord, const double axis, const double distance)
{
    return coord / (axis / distance + 1);
}

error_type projectCX(nodeType* nodes, const unsigned int size, const double d)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].x = projectC(nodes[i].x, nodes[i].z, d);
        nodes[i].y = projectC(nodes[i].y, nodes[i].z, d);
        nodes[i].z = projectCAxis();
    }

    return OK;
}

error_type projectCY(nodeType* nodes, const unsigned int size, const double d)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].y = projectC(nodes[i].y, nodes[i].x, d);
        nodes[i].z = projectC(nodes[i].z, nodes[i].x, d);
        nodes[i].x = projectCAxis();
    }

    return OK;
}

error_type projectCZ(nodeType* nodes, const unsigned int size, const double d)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].z = projectC(nodes[i].z, nodes[i].y, d);
        nodes[i].x = projectC(nodes[i].x, nodes[i].y, d);
        nodes[i].y = projectCAxis();
    }

    return OK;
}

#endif // PARALLPROJECTION_CPP

