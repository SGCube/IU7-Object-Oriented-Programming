#ifndef FACADE_H
#define FACADE_H

#include "scene/scene.h"
#include "managers/uploadmanager.h"
#include "managers/drawmanager.h"
#include "managers/objectmanager.h"

class Facade
{
public:
    Facade() = default;
    ~Facade() = default;

    void addModel(BaseUploader& upld, BaseBuilder& bld);
    void removeModel(size_t index);

    void addCamera();
    void removeCamera(size_t index);

    void transformModel(BaseTransformator& tr, int modelIndex);
    void transformCamera(BaseTransformator& tr, size_t cameraIndex);

    void draw(BaseDrawer& drw, size_t cameraIndex);

private:
    Scene scene;
    UploadManager uploadManager;
    DrawManager drawManager;
    ModelManager modelManager;
    CameraManager cameraManager;
};

#endif // FACADE_H
