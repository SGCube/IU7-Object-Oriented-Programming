#include "camera.h"

Camera::Camera() : moveParam(3, 0), scaleParam(3, 1), rotateParam(3, 0) {}

double Camera::getMoveX() const { return moveParam[0]; }
double Camera::getMoveY() const { return moveParam[1]; }
double Camera::getMoveZ() const { return moveParam[2]; }

double Camera::getScaleX() const { return scaleParam[0]; }
double Camera::getScaleY() const { return scaleParam[1]; }
double Camera::getScaleZ() const { return scaleParam[2]; }

double Camera::getRotateX() const { return rotateParam[0]; }
double Camera::getRotateY() const { return rotateParam[1]; }
double Camera::getRotateZ() const { return rotateParam[2]; }

void Camera::move(double x, double y, double z)
{
    moveParam[0] += x;
    moveParam[1] += y;
    moveParam[2] += z;
}

void Camera::scale(double x, double y, double z)
{
    scaleParam[0] *= x;
    scaleParam[1] *= y;
    scaleParam[2] *= z;
}

void Camera::rotate(double x, double y, double z)
{
    rotateParam[0] += x;
    rotateParam[1] += y;
    rotateParam[2] += z;
}
