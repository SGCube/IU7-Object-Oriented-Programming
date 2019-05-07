#ifndef ACTION_CPP
#define ACTION_CPP

#include "action.h"

error_type find_action(action_type action, struct actionDataType data)
{
    static modelType model = modelInit();

    error_type error = OK;

    if (action == load)
        error = modelLoadData(model, data);
    else if (action == save)
        error = modelSaveData(model, data);
    else if (action == ffree)
        error = modelFree(model);
    else if (action == draw)
        error = modelDrawData(model);
    else if (action == sshift)
        error = modelShiftData(model, data);
    else if (action == sscale)
        error = modelScaleData(model, data);
    else if (action == turn)
        error = modelTurnData(model, data);
    else if (action == project_p)
        error = modelProjectPData(model, data);
    else if (action == project_c)
        error = modelProjectCData(model, data);
    else
        error = ErrorAction;
    return error;
}

#endif // ACTION_CPP
