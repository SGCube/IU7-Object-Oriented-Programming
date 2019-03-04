#ifndef ROTATE_H
#define ROTATE_H

#include "polyh.h"

typedef struct
{
    double ax;
    double ay;
    double az;
    vertex *center;
} rotate;

void rotate_vertex(vertex *p, rotate t_rotate);

void rotate_model(model figure, rotate t_rotate);

#endif // ROTATE_H
