#ifndef EDGEARR_CPP
#define EDGEARR_CPP

#include "edge_array.h"

error_type edgeArrInit(edgeArrType& edgeArr)
{
    edgeArr.edges = NULL;
    edgeArr.size = 0;

    return OK;
}

error_type edgeArrFree(edgeArrType& edgeArr)
{
    error_type error;

    if ((error = edgesFree(edgeArr.edges)))
        return error;

    return (error = edgeArrInit(edgeArr)) ? error : OK;
}

error_type edgesArrLoad(edgeArrType& edgeArr, fileWorkType file)
{
    error_type error;

    if ((error = isCorrectFile(file.f)))
        return error;

    if ((error = getSize(edgeArr.size, file.f)))
        return error;

    if ((error = edgesAllocation(edgeArr.edges, edgeArr.size)))
        return error;

    if ((error = edgesLoad(edgeArr.edges, file, edgeArr.size)))
       edgesFree(edgeArr.edges);

    return error;
}

error_type edgesArrSave(fileWorkType file, const edgeArrType edgeArr)
{
    error_type error;

    if ((error = checkFileForOpen(file.f)))
        return error;

    if ((error = checkEdgesExist(edgeArr.edges)))
        return error;

    if ((error = setSize(file.f, edgeArr.size)))
        return error;

    return edgesSave(edgeArr.edges, file, edgeArr.size);
}

#endif // EDGEARR_CPP

