#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "polyh.h"
#include "move.h"
#include "scale.h"
#include "rotate.h"

typedef struct
{
    offset t_move;
    scale t_scale;
    rotate t_rotate;
} transform;

void transform(model figure, transform modify);

#endif // TRANSFORM_H
