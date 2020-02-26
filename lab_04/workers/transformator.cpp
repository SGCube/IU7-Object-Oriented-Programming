#include "transformator.h"

ModelTransformator::ModelTransformator(BaseTransformations &tr) :
	transformation(tr) {}

void ModelTransformator::transform(std::shared_ptr<Object> obj)
{
    double x = transformation.getX();
    double y = transformation.getY();
    double z = transformation.getZ();

    std::shared_ptr<Model> model = std::static_pointer_cast<Model>(obj);

    if (transformation.isMoving())
        model->move(x, y, z);
    if (transformation.isScaling())
        model->scale(x, y, z);
    if (transformation.isRotation())
        model->rotate(x, y, z);
}

CameraTransformator::CameraTransformator(BaseTransformations &tr) :
	transformation(tr) {}


void CameraTransformator::transform(std::shared_ptr<Object> obj)
{
    double x = transformation.getX();
    double y = transformation.getY();
    double z = transformation.getZ();

    std::shared_ptr<Camera> camera = std::static_pointer_cast<Camera>(obj);

    if (transformation.isMoving())
        camera->move(x, y, z);
    if (transformation.isScaling())
        camera->scale(x, y, z);
    if (transformation.isRotation())
        camera->rotate(x, y, z);
}

