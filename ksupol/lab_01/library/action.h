#ifndef ACTION_H
#define ACTION_H

#include "errors.h"
#include "model_data_work.h"
#include "model.h"

// типы действий
enum action_type {load, save, ffree, draw, sshift, sscale, turn, project_p, project_c};

// находим необходимое действие
error_type find_action(action_type action, actionDataType data);

#endif // ACTION_H
