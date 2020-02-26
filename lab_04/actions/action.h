#ifndef ACTION_H
#define ACTION_H

#include "facade/facade.h"
#include "workers/builder.h"
#include "workers/uploader.h"
#include "workers/transformator.h"
#include "transformations/transformations.h"

class BaseAction
{
public:
    BaseAction() = default;
    virtual ~BaseAction() = default;

    virtual void execute(std::shared_ptr<Facade> facade) = 0;
};

namespace actions
{
class ModelUploadAction : public BaseAction
{
public:
    explicit ModelUploadAction(const std::string& fileName) :
		fileName(fileName) {}
    ~ModelUploadAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        ModelUploader uploader(fileName);
        ModelBuilder builder;
        facade->addModel(uploader, builder);
    }
private:
    std::string fileName;
};

class CameraAddAction : public BaseAction
{
public:
    explicit CameraAddAction(double angleX, double angleY, double angleZ) :
		angleX(angleX), angleY(angleY), angleZ(angleZ) {}
    ~CameraAddAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        facade->addCamera();
    }
private:
    double angleX, angleY, angleZ;
};

class CameraRemoveAction : public BaseAction
{
public:
    explicit CameraRemoveAction(const size_t index) : index(index) {}
    ~CameraRemoveAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        facade->removeCamera(this->index);
    }
private:
    size_t index;
};

class ModelMoveAction : public BaseAction
{
public:
    explicit ModelMoveAction(double dx, double dy, double dz, size_t index) :
        dx(dx), dy(dy), dz(dz), modelIndex(index) {}
    ~ModelMoveAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        transformtions::Moving shf(dx, dy, dz);
        ModelTransformator transformator(shf);
        facade->transformModel(transformator, modelIndex);
    }
private:
    double dx, dy, dz;
    size_t modelIndex;
};

class ModelScaleAction : public BaseAction
{
public:
    explicit ModelScaleAction(double kx, double ky, double kz, size_t index) :
        kx(kx), ky(ky), kz(kz), modelIndex(index) {}
    ~ModelScaleAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        transformtions::Scaling scl(kx, ky, kz);
        ModelTransformator transformator(scl);
        facade->transformModel(transformator, modelIndex);
    }
private:
    double kx, ky, kz;
    size_t modelIndex;
};

class ModelRotateAction : public BaseAction
{
public:
    explicit ModelRotateAction(double x, double y, double z, size_t index) :
        angleX(x), angleY(y), angleZ(z), modelIndex(index) {}
    ~ModelRotateAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        transformtions::Rotation rt(angleX, angleY, angleZ);
        ModelTransformator transformator(rt);
        facade->transformModel(transformator, modelIndex);
    }
private:
    double angleX, angleY, angleZ;
    size_t modelIndex;
};

class CameraRotateAction : public BaseAction
{
public:
    explicit CameraRotateAction(double x, double y, double z, size_t index)
        : angleX(x), angleY(y), angleZ(z), cameraIndex(index) {}
    ~CameraRotateAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        transformtions::Rotation rt(angleX, angleY, angleZ);
        CameraTransformator transformator(rt);
        facade->transformCamera(transformator, cameraIndex);
    }
private:
    double angleX, angleY, angleZ;
    size_t cameraIndex;
};

class ModelDrawAction : public BaseAction
{
public:
    explicit ModelDrawAction(ModelDrawer drw, size_t index)
        : drawer(drw), cameraIndex(index) {}
    ~ModelDrawAction() = default;

    void execute(std::shared_ptr<Facade> facade) override
    {
        facade->draw(drawer, cameraIndex);
    }
private:
    ModelDrawer drawer;
    size_t cameraIndex;
};
}

#endif // ACTION_H
