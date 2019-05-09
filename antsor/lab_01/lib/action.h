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
	ACTION_ROTATE
};

// execute action
ErrorType actionFunc(const ActionType action, const ParameterType param);

#endif // ACTION_H
