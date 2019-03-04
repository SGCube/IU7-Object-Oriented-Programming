#ifndef POLYH_H
#define POLYH_H

typedef struct
{
    double x;
    double y;
    double z;
} vertex;

typedef struct
{
    vertex *p1;
    vertex *p2;
} edge;

typedef struct
{
    vertex *arr;
    int amount;
} vertex_array;

typedef struct
{
    edge *arr;
    int amount;
} edge_array;

typedef struct
{
    vertex_array vertexes;
    edge_array edges;
} model;

#endif // POINT_H
