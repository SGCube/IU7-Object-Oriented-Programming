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

    error = edgesFree(edgeArr.edges);
    if (error)
        return error;

    return (error = edgeArrInit(edgeArr)) ? error : OK;
}

error_type edgesArrLoad(edgeArrType& edgeArr, fileWorkType file)
{
    error_type error;

    error = isCorrectFile(file.f);
    if (error)
        return error;

    error = getSize(edgeArr.size, file.f);
    if (error)
        return error;

    error = edgesAllocation(edgeArr.edges, edgeArr.size);
    if (error)
        return error;

    error = edgesLoad(edgeArr.edges, file, edgeArr.size);
    if (error)
       edgesFree(edgeArr.edges);

    return error;
}

error_type edgesArrSave(fileWorkType file, const edgeArrType edgeArr)
{
    error_type error;

    error = checkFileForOpen(file.f);
    if (error)
        return error;

    error = checkEdgesExist(edgeArr.edges);
    if (error)
        return error;

    error = setSize(file.f, edgeArr.size);
    if (error)
        return error;

    return edgesSave(edgeArr.edges, file, edgeArr.size);
}

#endif // EDGEARR_CPP

