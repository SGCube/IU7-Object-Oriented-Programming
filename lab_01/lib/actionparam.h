#ifndef MODELPARAM_H
#define MODELPARAM_H

#include "vertexarray.h"

// type of axises
enum AxisType
{
    X,
	Y,
	Z
};

// type of parameters for file work
struct FileWorkParamType
{
	const char* fileName;
};

// type of parameters for model move
struct MoveParamType
{
    double dx, dy, dz;
};

// type of parameters for scale
struct ScaleParamType
{
    double kx, ky, kz;
    double xc, yc, zc;
};

// type of parameters for rotate
struct RotateParamType
{
    int angle;
    double xc, yc, zc;
    AxisType axis;
};

// type of parameters for parallel projection
struct ProjParallelParamType
{
    AxisType axis;
};

// type of parameters for central projection
struct ProjCentralParamType
{
    AxisType axis;
	double distance;
};

struct DrawParamType
{
	double** xToDraw;
	double** yToDraw;
	size_t* size;
};

// type of parameters
struct ParameterType
{
	FileWorkParamType fileWorkParameters;
    MoveParamType moveParameters;
	ScaleParamType scaleParameters;
	RotateParamType rotateParameters;
	ProjParallelParamType projParallelParameters;
	ProjCentralParamType projCentralParameters;
	DrawParamType drawParameters;
};

#endif // MODELPARAM_H
