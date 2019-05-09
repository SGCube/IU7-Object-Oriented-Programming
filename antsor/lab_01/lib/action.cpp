#ifndef ACTION_CPP
#define ACTION_CPP

#include "action.h"
#include "actionparam.h"

#include "model.h"
#include "modelaction.h"

ErrorType actionFunc(const ActionType action, const ParameterType param)
{
	ErrorType error = OK;
	static ModelType model = initializeModel();

    switch (action)
    {
        case ACTION_LOAD:
            error = modelLoadAction(model, param);
            break;
		case ACTION_SAVE:
			error = modelSaveAction(model, param);
			break;
		case ACTION_FREE:
			error = modelFreeAction(model);
			break;
		case ACTION_DRAW:
			error = modelDrawAction(model);
		case ACTION_MOVE:
			error = modelMoveAction(model, param);
			break;
		case ACTION_SCALE:
			error = modelScaleAction(model, param);
			break;
		case ACTION_ROTATE:
			error = modelRotateAction(model, param);
			break;
        default:
            error = ERROR_ACTION;
    }
    return error;
}

#endif // ACTION_CPP
