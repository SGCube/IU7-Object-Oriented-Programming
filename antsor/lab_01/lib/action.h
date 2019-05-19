#ifndef ACTION_H
#define ACTION_H

#include "error.h"
#include "actionparam.h"

// types of actions
enum ActionType
{
    ACTION_LOAD,
	ACTION_SAVE,
	ACTION_FREE,
	ACTION_DRAW,
	ACTION_MOVE,
	ACTION_SCALE,
	ACTION_ROTATE,
	ACTION_PROJECT_PARALLEL,
	ACTION_PROJECT_CENTRAL
};

// execute action
ErrorType actionFunc(ActionType action, ParameterType param);

#endif // ACTION_H
