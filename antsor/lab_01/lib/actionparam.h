#ifndef MODELPARAM_H
#define MODELPARAM_H

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
	char* fileName;
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

// type of parameters
union ParameterType
{
	FileWorkParamType* fileWorkParameters;
    MoveParamType* moveParameters;
	ScaleParamType* scaleParameters;
	RotateParamType* rotateParameters;
};

#endif // MODELPARAM_H
