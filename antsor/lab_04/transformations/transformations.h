#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include <vector>

class BaseTransformations
{
public:
    BaseTransformations(double x, double y, double z) : x(x), y(y), z(z) {}
    virtual ~BaseTransformations() = default;

    virtual bool isMoving() = 0;
    virtual bool isScaling() = 0;
    virtual bool isRotation() = 0;

    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

protected:
    double x, y, z;
};

namespace transformtions
{
class Moving : public BaseTransformations
{
public:
    Moving(double shX, double shY, double shZ) :
		BaseTransformations(shX, shY, shZ) {}
    ~Moving() = default;

    bool isMoving() { return true ;}
    bool isScaling() { return false; }
    bool isRotation() { return false; }
};

class Scaling : public BaseTransformations
{
public:
    Scaling(double scX, double scY, double scZ) :
        BaseTransformations(scX, scY, scZ) {}
    ~Scaling() = default;

    bool isMoving() { return false; }
    bool isScaling() { return true; }
    bool isRotation() { return false; }
};

class Rotation : public BaseTransformations
{
public:
    Rotation(double rtX, double rtY, double rtZ) :
        BaseTransformations(rtX, rtY, rtZ) {}
    ~Rotation() = default;

    bool isMoving() { return false; }
    bool isScaling() { return false; }
    bool isRotation() { return true; }
};
}

#endif // TRANSFORMATIONS_H
