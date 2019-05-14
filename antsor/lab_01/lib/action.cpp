#ifndef ACTION_CPP
#define ACTION_CPP

#include "action.h"
#include "actionparam.h"

#include "model.h"
#include "modelaction.h"

ErrorType actionFunc(ActionType action, ParameterType param)
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
			error = modelDrawAction(model, param);
			break;
		case ACTION_MOVE:
			error = modelMoveAction(model, param);
			break;
		case ACTION_SCALE:
			error = modelScaleAction(model, param);
			break;
		case ACTION_ROTATE:
			error = modelRotateAction(model, param);
			break;
		case ACTION_PROJECT_PARALLEL:
			error = modelProjParallelAction(model, param);
			break;
		case ACTION_PROJECT_CENTRAL:
			error = modelProjCentralAction(model, param);
			break;
        default:
            error = ERROR_ACTION;
    }
    return error;
}

#endif // ACTION_CPP
