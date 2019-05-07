#ifndef MODEL_PROJECT_CPP
#define MODEL_PROJECT_CPP

#include "model_project.h"

error_type modelProjectP(nodeType* nodes, const projectPDataType projectPData,
                                                        const unsigned int size)
{
    error_type error;

    if (projectPData.axis == X)
        error = projectPX(nodes, size);
    else if (projectPData.axis == Y)
        error = projectPY(nodes, size);
    else if (projectPData.axis == Z)
        error = projectPZ(nodes, size);
    else
        error = ErrorField;

    return error;
}

error_type modelProjectC(nodeType* nodes, const projectCDataType projectCData,
                                                        const unsigned int size)
{
    error_type error;

    if (projectCData.axis == X)
        error = projectCX(nodes, size, projectCData.distance);
    else if (projectCData.axis == Y)
        error = projectCY(nodes, size, projectCData.distance);
    else if (projectCData.axis == Z)
        error = projectCZ(nodes, size, projectCData.distance);
    else
        error = ErrorField;
    return error;
}

#endif // MODEL_PROJECT_CPP

