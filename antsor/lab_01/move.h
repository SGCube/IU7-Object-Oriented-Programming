#ifndef MOVE_H
#define MOVE_H

#include "polyh.h"

typedef struct
{
    double dx;
    double dy;
    double dz;
} offset;

void move_vertex(vertex *p, offset t_move);

void move_model(model figure, offset t_move);

#endif // MOVE_H
