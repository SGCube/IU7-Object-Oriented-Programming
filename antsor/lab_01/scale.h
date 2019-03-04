#ifndef SCALE_H
#define SCALE_H

#include "polyh.h"

typedef struct
{
    double kx;
    double ky;
    double kz;
    vertex *center;
} scale;

void scale_vertex(vertex *p, scale t_scale);

void scale_model(model figure, scale t_scale);

#endif // SCALE_H
