#ifndef MODEL_TRANSFORM_CPP
#define MODEL_TRANSFORM_CPP

#include "model_transform.h"

error_type modelShift(nodeType *nodes, const shiftDataType shiftData,
                                                const unsigned int size)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].x = shift(nodes[i].x, shiftData.dx);
        nodes[i].y = shift(nodes[i].y, shiftData.dy);
        nodes[i].z = shift(nodes[i].z, shiftData.dz);
    }

    return OK;
}

error_type modelScale(nodeType* nodes, const scaleDataType scaleData,
                                                const unsigned int size)
{
    error_type error;

    if ((error = checkNodesExist(nodes)))
        return error;

    for (unsigned int i = 0; i < size; i++)
    {
        nodes[i].x = scale(nodes[i].x, scaleData.kx, scaleData.cx);
        nodes[i].y = scale(nodes[i].y, scaleData.ky, scaleData.cy);
        nodes[i].z = scale(nodes[i].z, scaleData.kz, scaleData.cz);
    }

    return OK;
}

error_type modelTurn(nodeType* nodes, const turnDataType turnData,
                                            const unsigned int size)
{
    error_type error;

    if (turnData.axis == X)
        error = turnX(nodes, turnData, size);
    else if (turnData.axis == Y)
        error = turnY(nodes, turnData, size);
    else if (turnData.axis == Z)
        error = turnZ(nodes, turnData, size);
    else
        error = ErrorField;
    return error;
}

#endif // MODEL_TRANSFORM_CPP

