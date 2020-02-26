#ifndef CAMERA_H
#define CAMERA_H

#include <vector>

#include "object.h"

class Camera : public Object
{
public:
	Camera();
    ~Camera() = default;

    double getMoveX() const;
    double getMoveY() const;
    double getMoveZ() const;

    double getScaleX() const;
    double getScaleY() const;
    double getScaleZ() const;

    double getRotateX() const;
    double getRotateY() const;
    double getRotateZ() const;

    void move(double x, double y, double z);
    void scale(double x, double y, double z);
    void rotate(double x, double y, double z);

private:
    std::vector<double> moveParam;
    std::vector<double> scaleParam;
    std::vector<double> rotateParam;
};

#endif // CAMERA_H
