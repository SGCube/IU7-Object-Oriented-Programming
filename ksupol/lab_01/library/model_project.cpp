#ifndef MODEL_PROJECT_CPP
#define MODEL_PROJECT_CPP

#include "model_project.h"

error_type modelProjectP(pointType* points, projectPDataType projectPData,
                                                        const unsigned int size)
{
    error_type error;

    if (projectPData.axis == X)
        error = projectPX(points, size);
    else if (projectPData.axis == Y)
        error = projectPY(points, size);
    else if (projectPData.axis == Z)
        error = projectPZ(points, size);
    else
        error = ErrorField;

    return error;
}

error_type modelProjectC(pointType* points, projectCDataType projectCData,
                                                        const unsigned int size)
{
    error_type error;

    if (projectCData.axis == X)
        error = projectCX(points, size, projectCData.distance);
    else if (projectCData.axis == Y)
        error = projectCY(points, size, projectCData.distance);
    else if (projectCData.axis == Z)
        error = projectCZ(points, size, projectCData.distance);
    else
        error = ErrorField;
    return error;
}

#endif // MODEL_PROJECT_CPP

