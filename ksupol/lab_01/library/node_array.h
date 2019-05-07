#ifndef NODEARR_H
#define NODEARR_H

#include "errors.h"
#include "node.h"
#include "file_work.h"

#include <stdio.h>

#define READ_OK 1
#define WRITE_OK 1

struct nodeArrType
{
    nodeType* nodes;
    unsigned int size;
};

error_type nodeArrInit(nodeArrType &nodeArr);

error_type nodeArrFree(nodeArrType& nodeArr);

error_type nodesArrLoad(nodeArrType& nodeArr, fileWorkType file);

error_type nodesArrSave(fileWorkType file, const nodeArrType nodeArr);

#endif // NODEARR_H

