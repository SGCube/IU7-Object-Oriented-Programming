#ifndef NODE_ARR_CPP
#define NODE_ARR_CPP

#include "node_array.h"

error_type nodeArrInit(nodeArrType& nodeArr)
{
    nodeArr.nodes = NULL;
    nodeArr.size = 0;

    return OK;
}

error_type nodeArrFree(nodeArrType& nodeArr)
{
    error_type error;

    if ((error = nodesFree(nodeArr.nodes)))
        return error;
    if ((error = nodeArrInit(nodeArr)))
        return error;
    return OK;
}

error_type nodesArrLoad(nodeArrType& nodeArr, fileWorkType file)
{
    error_type error;

    if ((error = isCorrectFile(file.f)))
        return error;

    if ((error = getSize(nodeArr.size, file.f)))
        return error;

    if ((error = nodesAllocation(nodeArr.nodes, nodeArr.size)))
        return error;

    return nodesLoad(nodeArr.nodes, file, nodeArr.size);
}

error_type nodesArrSave(fileWorkType file, const nodeArrType nodeArr)
{
    error_type error;

    if ((error = checkFileForOpen(file.f)))
        return error;

    if ((error = checkNodesExist(nodeArr.nodes)))
        return error;

    if ((error = setSize(file.f, nodeArr.size)))
        return error;

    return nodesSave(nodeArr.nodes, file, nodeArr.size);
}

#endif // NODE_ARR_CPP

